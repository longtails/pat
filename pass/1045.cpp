#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>favor_count;
int toAds[220];//address by hash
/*
解决思路：favor进行hash映射及toAds，获得的地址为存储favor_count计数的数组下标
	顺序访问strips, 对于第i次访问，从(i~0)查找favor_j的计数数组，进行比较，若
	>=则favor_count[i]=favor_count[j]+1;
	最后找出favor_count中最大的计数即可
 */
int count(int pos)
{
	int cur=toAds[pos];
	int max=favor_count[cur];
	for(int i=cur;i>=0;i--)
	{
		if(favor_count[cur]<=favor_count[i])
		  favor_count[cur]=favor_count[i]+1;
		if(max<favor_count[cur])
		  max=favor_count[cur];
	}
	return max;
}
int main()
{
	freopen("in","r",stdin);
	fill_n(toAds,220,-1);
	int N=0,M=0,L=0;
	int tmp=0;
	scanf("%d%d",&N,&M);
	favor_count.assign(M,0);
	for(int i=0;i<M;i++)
	{
		scanf("%d",&tmp);
		toAds[tmp]=i;
	}
	scanf("%d",&L);
	int max=0;
	for(int i=0;i<L;i++)
	{
		scanf("%d",&tmp);
		if(toAds[tmp]>=0)
		{
		  tmp=count(tmp);
		  if(max<tmp)
			max=tmp;
		}
	}
	printf("%d\n",max);
	return 0;
}

