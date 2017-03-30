#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;
vector<int> a;
vector<int> b;
int count[100010];
int list[100010];
int main()
{
	fill(count,count+100010,0);
	fill(list,list+100010,-1);
	freopen("1032.in","r",stdin);
	int tmp_a,tmp_b,size;
	scanf("%d%d%d",&tmp_a,&tmp_b,&size);
	char tmp_s[10];
	int flag=-1;
	int start_a=tmp_a;
	int start_b=tmp_b;
	if(tmp_a==tmp_b)
	  flag=tmp_a;
	for(int i=0;i<size;i++)
	{
		scanf("%d%s%d",&tmp_a,tmp_s,&tmp_b);
		list[tmp_a]=tmp_b;
	}
	while(start_a!=-1)
	{
		count[start_a]=1;
		start_a=list[start_a];
	}
	while(start_b!=-1)
	{
		if(count[start_b]==1)
		{
		  flag=start_b;
		  break;
		}
		start_b=list[start_b];
	}
	if(flag==-1)
		printf("-1\n");
	else
		printf("%05d\n",flag);
	return 0;
}
