#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int data[100010];
int v[100010];
int N;
int M;
vector<int>out;
int main()
{
	for(int i=0;i<100010;i++)
	{
		data[i]=-1;
		v[i]=0;
	}
	cin>>N;
	int tmp=0;
	int tmp2=0;
	for(int i=0;i<N;i++)
	{
		cin>>tmp>>tmp2;
		if(tmp<tmp2)
		{
			data[tmp]=tmp2;
			data[tmp2]=-3;
		}else
		{
			data[tmp2]=tmp;
			data[tmp]=-3;
		}

	}
	cin>>M;
	int count=0;
	for(int i=0;i<M;i++)
	{
		cin>>tmp;
		v[tmp]=1;
		if(data[tmp]>=0)
		{
			data[data[tmp]]--;
		}else
		{
			data[tmp]--;
		}
	}
	for(int i=0;i<100010;i++)
	{
		if(v[i]==0)
			  continue;
		if(data[i]==-2||data[i]==-4)
		{
			count++;
			out.push_back(i);
		}
		if(data[i]>=0)
		{
			if(data[data[i]]==-4)
			{
				count++;
				out.push_back(i);
			}
		}
	}
	cout<<out.size()<<endl;
	for(int i=0;i<out.size();i++)
	{
		printf("%05d",out.at(i));
		if(i+1==out.size())
		  cout<<endl;
		else
		  cout<<" ";
	}
	return 0;
}
