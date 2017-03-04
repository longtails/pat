#include<iostream>
#include<vector>
using namespace std;
int N;
int flag[10010];
int main()
{
	for(int i=0;i<10010;i++)
	  flag[i]=0;
	cin>>N;
	int tmp=0;
	int sum=0;
	int count=0;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		sum=0;
		while(tmp>0)
		{
			sum+=tmp%10;
			tmp/=10;
		
		}
		if(flag[sum]==0)
		{
			count++;
			flag[sum]=1;
		}
	}
	cout<<count<<endl;
	for(int i=0;i<10010;i++)
	{
		if(flag[i]==1)
		{
		  cout<<i;
		  if(--count==0)
			cout<<endl;
		  else
			cout<<" ";
		}
	}
	return 0;
}
