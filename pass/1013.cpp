#include<iostream>
#include<vector>
#include<map>
using namespace std;
int city[1010][1010];
int f[1010];
vector<int>check;
int N,M,K;
int getf(int a)
{
	for(int i=1;i<=N;i++)
	{
		f[i]=i;
	}
	//完全----------着这样是不行的，应该在发现最小时，进行递归设置
	for(int i=1;i<=N;i++)
	{

		int min=f[i];
		if(i==a)
		  continue;
		for(int j=1;j<=N;j++)
		{
			if(j==a)
			  continue;
			if(city[i][j]==1)
			{
				if(min>f[j])
				  min=f[j];
			}
		}
		for(int j=1;j<=N;j++)
		{
			if(j==a)
			  continue;
			if(city[i][j]==1)
			  f[j]=min;
		}
	}
	map<int,int>out;
	for(int i=1;i<=N;i++)
	{
		if(a==i)
		  continue;
		out[f[i]]=1;
	}
	return out.size();
}
int main()
{
	cin>>N>>M>>K;
	int tmp1,tmp2;
	for(int i=1;i<=N;i++)
		f[i]=i;
	for(int i=0;i<M;i++)
	{
		cin>>tmp1>>tmp2;
		city[tmp1][tmp2]=1;
		city[tmp2][tmp1]=1;
		/*
		if(tmp1>tmp2)
		  f[tmp1]=tmp2;
		else
		  f[tmp2]=tmp1;
		  */
	}
	for(int i=0;i<K;i++)
	{
		cin>>tmp1;
		check.push_back(tmp1);
	}
	for(int i=0;i<check.size();i++)
	{
		cout<<getf(check[i])-1<<endl;
	}

	return 0;
}
