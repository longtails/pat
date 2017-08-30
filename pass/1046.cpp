#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>dis;
int main()
{
	freopen("in","r",stdin);
	int N,M,tmp,tmp2,sum;
	scanf("%d",&N);
	sum=0;
	dis.push_back(sum);//city0 起始距离0
	for(int i=0;i<N;i++)
	{
		scanf("%d",&tmp);
		sum+=tmp;
		dis.push_back(sum);//记录距离和，求两个城市距离通过做差求得
	}
	scanf("%d",&M);
	int a,b;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&tmp,&tmp2);
		tmp--;tmp2--;//纠正数组下标
		a=(dis[tmp]-dis[tmp2]+sum)%sum;//避免出现负数，求补
		b=(dis[tmp2]-dis[tmp]+sum)%sum;
		if(a<b)
		  printf("%d\n",a);
		else
		  printf("%d\n",b);
	}
	return 0;
}
