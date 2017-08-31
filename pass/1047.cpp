#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int nameToNum(string name)
{
	int num=(name[0]-'A');//懒得写循环了～～
	num*=26;
	num+=(name[1]-'A');
	num*=26;
	num+=(name[2]-'A');
	num*=26;
	num+=(name[3]-'0');
	return num;
}
string numToName(int n)
{
	char tmp[5];
	tmp[4]='\0';
	tmp[3]=char(n%26+'0');
	n/=26;
	tmp[2]=char(n%26+'A');
	n/=26;
	tmp[1]=char(n%26+'A');
	n/=26;
	tmp[0]=char(n%26+'A');
	return tmp;
}
vector<int> course[2550];
int main()
{
	freopen("in","r",stdin);
	int N,K,C,tmp,iname;
	char name[5];
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s%d",name,&C);
		iname=nameToNum(name);
		for(int j=0;j<C;j++)
		{
			scanf("%d",&tmp);
			course[tmp].push_back(iname);
		}
	}
	int size=0;
	string sname;
	for(int i=1;i<=K;i++)
	{
		size=course[i].size();
		printf("%d %d\n",i,size);
		sort(course[i].begin(),course[i].end());
		for(int j=0;j<course[i].size();j++)
		{
			sname=numToName(course[i][j]);
			printf("%s\n",sname.c_str());
		}
	}
	return 0;
}
