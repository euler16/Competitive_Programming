# include <iostream>
# include <cstdio>
# include <vector>

# define L_CHILD(i) 2*i
# define R_CHILD(i) 2*i+1

using namespace std;

void build(vector<int> segTree, vector<int>arr, int node, int start , int end)
{
	if(start == end)
		segTree[node] = arr[start];

	else
	{
		int mid = (start+end)/2;
		build(segTree,arr,L_CHILD(node),start,mid+1);
		build(segTree,arr,R_CHILD(node),mid+1,end);

		segTree[node] = segTree[L_CHILD(node)] + segTree[R_CHILD(node)];
	}
}

void update(vector<int> segTree, vector<int>arr, int val ,int index, int node, int start, int end)
{
	if(start == end)
	{
		arr[index] += val;
		segTree[node] += val;
		return;
	}

	else
	{
		int mid = (start + mid)/2;
		if(start<=index && index<=mid)
			update(segTree,arr,val,index,L_CHILD(node),start,mid);
		else
			update(segTree,arr,val,index,L_CHILD(node),mid+1,end);

		segTree[node] = segTree[L_CHILD(node)] + segTree[R_CHILD(node)];
	}
}

int query(vector<int>segTree, vector<int> arr, int node, int start, int end, int qleft, int qright)
{
	if(qleft>end || qright<start)  // query range out of the node range
		return 0;
	else if(l<=start && r>=end)  // node range inside query range
		return segTree[node];

	else    // range is partially inside this node .... returns the portion inside the node range
	{
		int mid = (start + end)/2;
		int p1 = query(segTree,arr,L_CHILD(node), start,mid+1,qleft, qright);
		int p2 = query(segTree,arr,R_CHILD(node), mid+1,end,qleft, qright);
		return (p1+p2);
	}
}

void updateRange(vector<int>segTree, vector<int>arr, vector<int>lazy, int node , int start, int end, int l, int r, int val)
{
	if(lazy[node])
	{
		segTree[node] += (end-start+1)*lazy[node];
		if(start!=end)
		{
			// mark children
			lazy[R_CHILD(node)] += lazy[node];
			lazy[L_CHILD(node)] += lazy[node];	
		}

		lazy[node] = 0;
	}

	if(r<start || l>end)
		return;

	if(l<=start && r>=end)
	{
		segTree[node] += (end-start+1)*val;
		if(start != end)
		{
			lazy[L_CHILD(node)] += val;
			lazy[R_CHILD(node)] += val;
		}
		return;
	}

	// when partial
	int mid = (start + end)/2;
	updateRange(segTree, arr, lazy, L_CHILD(node), start, mid, l, r, val);
	updateRange(segTree, arr, lazy, R_CHILD(node), mid+1, end, l, r, val);
	segTree[node] = segTree[L_CHILD(node)] + segTree[R_CHILD(node)]; 
}


int queryRange(vector<int>segTree, vector<int>arr, vector<int>lazy, int node, int start, int end, int qleft, int qright)
{
	if(lazy[node])
	{
		segTree[node] += (end-start+1)*lazy[node];
		if(start!=end)
		{
			// mark children
			lazy[R_CHILD(node)] += lazy[node];
			lazy[L_CHILD(node)] += lazy[node];	
		}

		lazy[node] = 0;
	}

	if(qright<start || qleft>end)
		return 0;

	if(qleft<=start || qright>=end)
		return segTree[node];

	int mid = (start+end)/2;
	int p1 = queryRange(segTree,arr,lazy,node,start,mid,qleft,qright);
	int p2 = queryRange(segTree,arr,lazy,node,mid+1,end,qleft,qright);
	return (p1+p2);
}