#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	int N,M,min=0,tmp;
	vector<int> chain;
	//cin>>N>>M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		//cin>>tmp;
		scanf("%d",&tmp);
		chain.push_back(tmp);
		min+=tmp;
	}
	vector<int>pay;
	int i=0,j=0;
	int pre=0;
	tmp=0;
	//再找到一组i~j满足后，继续寻找i+1,直接j或j+1,
    //这样基本上一个N，解决
	for(i=0;i<N;i++)
	{
		tmp-=pre;
		for( ;j<N;j++)
		{
			if(tmp>=M)
			  break;
			tmp+=chain[j];
		}
		j-=1;//注意：
		if(tmp<M)
		  break;
		if(tmp<=min)
		{
		  if(tmp<min)//找到更合适的啦，清空之前的记录
			pay.clear();
	      pay.push_back(i+1);
	      pay.push_back(j+1);
		  min=tmp;
		}
		//能够下来说明：找到一组sum[i~j]>=M;
		//**********************************************************************
		//为避免内部循环，可通过仅仅判断chain[i]和chain[j]的大小判断sum[i+1~j]>=M
		//有chain[i~j-1]<M
		//有如下情况：
		//１，chain[i]>=chain[j],下次循环，减去chain[i],则一定sum[i+1~j]<M。
		//	这时，需要判断是否sum[i+1~j+1]>=M,搜索下去知道>=M
		//２，chain[i]<chain[j],下次循环，减去chain[i],则有可能sum[i+1~j]>=M。
		//  这时j,不需要+1,直接进行不断，不满足则继续内层循环即可。
		//通过1,2降低了内层循环次数，原来需要进行N次内循环，现在一次完整的内循环即可。
		//*********************************************************************
		//
		pre=chain[i];
		//减去的那个数比最后这个chain[j]大说明仅靠这个chain[j],
		if(chain[i]>=chain[j])//说明sum(i+1~j)<M,
		  j++;
		//减去的那个数比最后这个chain[j]小说明，有可能不用加chain[j+1]便可>=M
		else//有可能sum(i~j)>=M
		{
	        tmp-=chain[j];
		}
	}
	for(int i=0;i<pay.size();i+=2)
	  printf("%d-%d\n",pay[i],pay[i+1]);
	  //cout<<pay[i]<<"-"<<pay[i+1]<<endl;//千万不要用cout ,cin可能会超时
	return 0;
}
/*
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	int N,M,min=0,tmp;
	vector<int> chain;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&tmp);
		chain.push_back(tmp);
		min+=tmp;
	}
	vector<int>pay;
	int i,j;
	for(int i=0;i<N;i++)
	{
		tmp=0;
		j=0;
		for( j=i;j<N;j++)
		{
			if(tmp>=M)
			  break;
			tmp+=chain[j];
		}
		if(tmp<M)
		  break;
		if(tmp<min)//找到更合适的啦，清空之前的记录
		  pay.clear();
		else if(tmp>min)//记录中比刚发现的要好，不记录
		  continue;
	    pay.push_back(i+1);
	    pay.push_back(j);
		min=tmp;
	}
	for(int i=0;i<pay.size();i+=2)
	  printf("%d-%d\n",pay[i],pay[i+1]);
	return 0;
}*/
