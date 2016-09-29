# include <iostream>
# include <vector>
# include <string>

using namespace std;

vector<int>ftree(100001);
string s;

int N;//N is size

void update(int node)			// delta is always equal to 1
{
	for(;node<=N;node += (node&-node))
		ftree[node]^=1;
}

int query(int idx)
{
	int q = 1;
	for(int i=idx+1;i!=0;i+=(i&(i-1)))
		q = !(q^ftree[i]);
	return q;
}

void build()
{
	for(int i=0;i<N;i++)
		update(i+1);
}

int main()
{	
	int Q = 0;
	scanf("%d %d",&N,&Q);
	cin>>s;
	while(Q--)
	{
		int a;
		scanf("%d ",&a);
		if(a==2)
		{
			int b,c;
			scanf("%d %d",&b,&c);
			int res = !(query(b)^query(c));
			if(res)
				printf("yes\n");
			else
				printf("no\n");
		}
		else if(a==1)
		{
			int b;
			char c;
			scanf("%d %c",&b,&c);
			update(b+1);
		}
	}
}