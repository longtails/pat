#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	deque<int> E;
	int N;
	cin>>N;
	int tmp;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		E.push_back(tmp);
	}
	sort(E.begin(),E.begin()+N);
	int E1=0;
	for(int i=0;i<N;i++)
	{
		tmp=E.at(0);
		E.pop_front();
		for(int j=E1;j<tmp;j++)
		{
			if(j==N-i)
			  E1=j;
			else if(j>N-i)
			{
				break;
			}
		}
	}
	cout<<E1<<endl;
	return 0;
}
