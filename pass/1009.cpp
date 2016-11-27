#include<iostream>
#include<stdio.h>
using namespace std;
double a[2010];//我设置成了1010居然没有发生段错误
double b[2010];
double c[2010];
int main()
{
	for(int i=0;i<2010;i++)
	{
		a[i]=b[i]=c[i]=0;
	}
	int N,e;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>e;
		cin>>a[e];
	}
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>e;
		cin>>b[e];
	}
	for(int i=0;i<2010;i++)
	{
		if(a[i]==0)
		  continue;
		for(int j=0;j<2010;j++)
		{
			if(b[j]==0)
			  continue;
			c[i+j]+=a[i]*b[j];
		}
	}
	int count=0;
	for(int i=0;i<2010;i++)
	{
		if(c[i]!=0)
		{
		  count++;
		}
	}
	cout<<count<<" ";
	for(int i=2009;i>=0;i--)
	{
		if(c[i]!=0)
		{
			printf("%d %.1f",i,c[i]);
			if(--count==0)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
