#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
vector<int> coins;
int exist[100010];
int main()
{
	freopen("in","r",stdin);
	fill_n(exist,100010,0);
	int N,M,tmp;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&tmp);
		exist[tmp]++;
		coins.push_back(tmp);
	}
	sort(coins.begin(),coins.end());

	bool find=false;
	int i=0;
	for(i=0;i<N;i++)
	{
		tmp=M-coins[i];//做差，若存在，且不是它自己则成功
		if(tmp>0&&exist[tmp])
		{
			if(tmp+tmp==M&&exist[tmp]==1)
			  find=false;
			else
			  find=true;
			break;
		}else if(tmp<=0)
		{
			find=false;
			break;
		}
	}
	if(find)
		printf("%d %d\n",coins[i],tmp);
	else
		printf("No Solution\n");

	return 0;
}
