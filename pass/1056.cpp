/*************************************************************************
    > File Name: 1056.cpp
    > Author: liu
    > Mail: scylhy@163.com 
    > Created Time: 2017年09月14日 星期四 17时55分19秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int flag[10010];
int w[10010];
int r[10010];
vector<int> va;
vector<int> vb;
int main()
{
	freopen("in","r",stdin);
	int NP,NG;
	int tmp;
	scanf("%d%d",&NP,&NG);
	for(int i=0;i<NP;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<NP;i++)
	{
		scanf("%d",&tmp);
		va.push_back(tmp);
		flag[i]=0;
		r[i]=1;
	}
	int ng=NG;
	int max=0;//组内最大的下标
	//采用双队列,交替跟进,记录晋级人数
	vector<int>*a=&va;
	vector<int>*b=&vb;
	vector<int>*c=a;
	while(a->size()>1)
	{
		ng=NG;
		max=(*a)[0];
		for(int i=0;i<a->size();i++)
		{
			if(w[max]<w[(*a)[i]])
				max=(*a)[i];
			ng--;
			if(ng==0||i==a->size()-1)//ng控制一组,按照顺序没NG个一组
			{
				//晋级人员压栈，最终，未晋级人员的排名便是晋级栈的大小+1
				b->push_back(max);
				flag[max]=1;//晋级标志,max晋级
				max=(*a)[i+1];
				ng=NG;
			}
		}
		for(int i=0;i<a->size();i++)
			if(flag[(*a)[i]]==0)//晋级人数为:b->size(),故未晋级的排名为b->size()+1
				r[(*a)[i]]=b->size()+1;
			else
				flag[(*a)[i]]=0;//恢复check值,待下次访问使用
		a->clear();//va
		//交换
		c=b;b=a;a=c;
	}
	for(int i=0;i<NP;i++)
	{
		printf("%d",r[i]);
		if(i==NP-1)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}

