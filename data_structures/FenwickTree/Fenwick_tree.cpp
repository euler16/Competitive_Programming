//implementation of fenwick tree

# include <iostream>
# include <vector>

using namespace std;

vector<int> ftree(12);
vector<int> arr = {3,2,-1,6,5,4,-3,3,7,2,3};


// n is the maximum index in arr
void update(int node, int delta, int n)
{
	for(;node<=n+1;node+=(node&-node))					// to get_next element
		ftree[node] += delta;
}

int query(int idx, int n)   // want sum till index idx
{
	int sum = 0;
	for(int i=idx+1;i!=0;i=(i&(i-1)))				// to reach parent
		sum+=ftree[i];
	return sum;
}

void build(int n)
{
	for(int i=0;i<=n;i++)
		update(i+1,arr[i],n);
}

//testing
/*int main()
{
	build(10);
	for(auto elem:ftree)
		cout<<elem<<" ";
	return 0;
}*/