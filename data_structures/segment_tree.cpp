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