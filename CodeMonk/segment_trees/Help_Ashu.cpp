# include <iostream>
# include <cstdio>
# include <utility>
# include <vector>

# define L_CHILD(i) 2*i
# define R_CHILD(i) 2*i+1
# define isEven(i) ((i%2)==0)
# define isOdd(i)  ((i%2)==1)

using namespace std;
vector<pair<int,int>>segTree(300000+4);
vector<long long>arr(200000+2);
void build(int node, int start, int end)
{
	//cout<<start<<" "<<end<<endl;
	if(start == end)
	{
		//cout<<"In here leaf"<<endl;
		segTree[node].first = (arr[start]%2==0)?1:0;
		segTree[node].second = (arr[start]%2==0)?0:1;
		return;
	}

	int mid = (start+end)/2;
	build(L_CHILD(node),start,mid);
	build(R_CHILD(node),mid+1,end);
	segTree[node].first = segTree[L_CHILD(node)].first + segTree[R_CHILD(node)].first;
	segTree[node].second = segTree[L_CHILD(node)].second + segTree[R_CHILD(node)].second;
}

void update(int index, long long value, int node, int start, int end)
{
	if(start == end)
	{
		// start is equal to index
		int temp = arr[index];
		arr[index] = value;
		if(isEven(temp) && isOdd(value))
		{
			segTree[node].first--;
			segTree[node].second++;
		}
		else if(isOdd(temp) && isEven(value))
		{
			segTree[node].first++;
			segTree[node].second--;	
		}
		return;
	}

	int mid = (start+end)/2;
	if((index<=mid) && (index>=start))
		update(index,value,L_CHILD(node),start,mid);
	else if((index>=mid+1) && (index<=end))
		update(index,value,R_CHILD(node),mid+1,end);

	segTree[node].first = segTree[L_CHILD(node)].first + segTree[R_CHILD(node)].first; 
	segTree[node].second = segTree[L_CHILD(node)].second + segTree[R_CHILD(node)].second;
}

int queryEven(int node, int start, int end, int qleft, int qright)
{
	if((qleft>end) || (qright<start))
		return 0;
	else if((qleft<=start) && (qright>=end))
		return segTree[node].first;

	int mid = (start+end)/2;
	return queryEven(L_CHILD(node),start,mid,qleft,qright) + queryEven(R_CHILD(node),mid+1,end,qleft,qright); 
}

int queryOdd(int node, int start, int end, int qleft, int qright)
{
	if((qleft>end) || (qright<start))
		return 0;
	else if((qleft<=start) && (qright>=end))
		return segTree[node].second;

	int mid = (start+end)/2;
	return queryOdd(L_CHILD(node),start,mid,qleft,qright) + queryOdd(R_CHILD(node),mid+1,end,qleft,qright); 
}

int main()
{
	int N = 0,Q = 0,queries = 0,x = 0;
	long long y = 0;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%lld",&arr[i]);

	build(1,0,N-1);
	/*cout<<endl<<endl;
	for(auto elem:segTree)
		cout<<elem.first<<" "<<elem.second<<endl;*/

	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d %lld",&queries,&x,&y);

		if(queries == 0)
			update(x-1,y,1,0,N-1);
		else if(queries == 1)
			printf("%d\n",queryEven(1,0,N-1,x-1,(int)y-1));
		else
			printf("%d\n",queryOdd(1,0,N-1,x-1,(int)y-1));
	}
}