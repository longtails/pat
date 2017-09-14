/*************************************************************************
    > File Name: 1055.cpp
    > Author: liu
    > Mail: scylhy@163.com 
    > Created Time: 2017年09月12日 星期二 19时47分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<algorithm>
struct man{
	char name[10];
	int age;
	long wealth;
};
bool comp(man a,man b)
{
	if(a.wealth>b.wealth)
		return true;
	else if(a.wealth<b.wealth)
		return false;
	
	if(a.age<b.age)
		return true;
	if(a.age>b.age)
		return false;
	if(strcmp(a.name,b.name)<0)
		return true;
	return false;
}
using namespace std;
vector<man>men;
int main()
{
	freopen("in","r",stdin);
	int N,K;
	man tmp;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s%d%ld",tmp.name,&tmp.age,&tmp.wealth);
		men.push_back(tmp);
	}
	sort(men.begin(),men.end(),comp);
	int c,a,b,count;
	for(int i=0;i<K;i++)
	{
		count=0;
		scanf("%d%d%d",&c,&a,&b);
		printf("Case #%d:\n",i+1);
		for(int j=0;j<men.size();j++)
		{
			if(men[j].age>=a&&men[j].age<=b)
			{
				count++;
				printf("%s %d %ld\n",men[j].name,men[j].age,men[j].wealth);
				if(count==c)
					break;
			}
		}
		if(count==0)
			printf("None\n");

	}

	return 0;
}

