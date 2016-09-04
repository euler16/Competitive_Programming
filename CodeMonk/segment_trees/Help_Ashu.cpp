/*Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.
He gives him an array of N natural numbers and asks him to solve the following queries:-

Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

input:
First line of the input contains the number N. Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5
1<=l<=r<=N
0<=Ai<=10^9
1<=x<=N
0<=y<=10^9

Note:- indexing starts from 1.*/

# include <iostream>
# include <cstdio>
# include <vector>
# include <utility>

using namespace std;

// not a lazy problem - lazy only for range updation
/*vector<pair<int,int>>lazy(200000+2);*/
vector<pair<long long,long long>>segTree(200000+2);
vector<long long>arr(100000+1);

// lazy will store num even and num odd
// first is for odd second is for even
void build(int node, int start,int end)
{
	if(start == end)
	{
		segTree[node].first = (arr[start]%2 == 0)?1:0;
		segTree[node].second = (arr[start]%2 == 0)?0:1;
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node,start, mid);
		build(2*node+1,mid+1,end);
		segTree[node].first = segTree[2*node].first + segTree[2*node+1].first; // check what is the sum of two pairs equal to
		segTree[node].second = segTree[2*node].second + segTree[2*node+1].second;	
	}
}
// lazy node will store number of even or odd
void update(int node, int start, int end, int x, int y)
{
	// modify index x to y
	if(start == end)   // start == x
	{
		arr[start] = y;
		if( ((arr[x]%2)==0) && ((y%2)==1) ) // y is odd
		{
			segTree[node].first -= 1;
			segTree[node].second += 1;
		}
		else if( ((arr[x]%2)==0) && ((y%2)==1) )
		{
			segTree[node].first += 1;
			segTree[node].second -= 1;
		}
		return;
	}	

	int mid = (start + end)/2;
	if(start<=x && mid>=x)
		update(2*node,start,mid,x,y);
	else
		update(2*node+1,mid+1,start,x,y);
	
	segTree[node].first = segTree[2*node].first + segTree[2*node+1].first; // check what is the sum of two pairs equal to
	segTree[node].second = segTree[2*node].second + segTree[2*node+1].second;
	return;
}

int main()
{
	int N = 0,Q = 0;
	int query = 0, x = 0, y = 0;
	scanf("%d",&N);
	for(int i = 0;i<N;i++)
		scanf("%d",&arr[i]);

	build(1,0,N-1);
	scanf("%d",&Q);

	while(Q--)
	{
		scanf("%d %d %d",&query,x,y);
		if(query == 0)
		{

		}
		else if(query == 1)
		{

		}
		else if(query == 2)
		{

		}
	}
}
