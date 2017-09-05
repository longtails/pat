#include<iostream>
#include<cstdio>
using namespace std;

int seq[1010];
int main()
{
	freopen("in","r",stdin);
	int M,N,K,tmp,count,pre,split,isRight;
	scanf("%d%d%d",&M,&N,&K);
	for(int i=0;i<K;i++)
	{
		pre=split=0;
		isRight=1;
		for(int j=0;j<N;j++)
		{
		  scanf("%d",&tmp);
		  if(tmp>pre)//新的划分
		  {
			if(tmp<split)//划分值非递增,非法
				isRight=0;
			split=tmp;
			count=1;
		  }else
			count++;

		  if(count>M)//超过栈的容量
		    isRight=0;
		  pre=tmp;
		}
		if(isRight==0)
		  printf("NO\n");
		else
		  printf("YES\n");
	}
	return 0;
}


