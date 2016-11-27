#include<iostream>
using namespace std;

int main()
{
	int N,tmp;
	cin>>N;
	int cur=0;
	int cost=0;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		if(tmp>cur)
		{
			cost+=(tmp-cur)*6+5;
			cur=tmp;
		}else
		{
			cost+=(cur-tmp)*4+5;
			cur=tmp;
		}
	}
	cout<<cost<<endl;

}
