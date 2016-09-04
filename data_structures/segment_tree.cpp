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