#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<long,int>color;
int main()
{
	freopen("in","r",stdin);
	int M,N,max,w;
	long tmp;
	scanf("%d%d",&M,&N);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%ld",&tmp);
			color[tmp]++;
			if(color[tmp]>max)
			  w=tmp;
		}
	}
	printf("%d\n",w);
	return 0;
}
