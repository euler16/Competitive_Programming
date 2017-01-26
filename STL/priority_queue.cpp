# include <iostream>
# include <queue>

using namespace std;

int main()
{
		priority_queue<int> v;
		v.push(4);
		v.push(10);
		v.push(2);

		cout<<v.top()<<endl; v.pop();
		cout<<v.top()<<endl; v.pop();

		return 0;
}
