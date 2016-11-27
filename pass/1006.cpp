#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
struct _INFO
{
	string id;
	int in;
	int out;
};
int M;
vector<_INFO>info;
int main()
{
	cin>>M;
	int a,b,c;
	int d,e,f;
	_INFO tmp;
	char id[16];
	for(int i=0;i<M;i++)
	{
		memset(id,16,0);
		scanf("%s %02d:%02d:%02d %02d:%02d:%02d",id,&a,&b,&c,&d,&e,&f);
		tmp.id=id;
		tmp.in=a*60*60+b*60+c;
		tmp.out=d*60*60+e*60+f;
		info.push_back(tmp);
	}
	int min=0;
	int max=0;
	for(int i=0;i<info.size();i++)
	{
		if(info[min].in>info[i].in)
		  min=i;
		if(info[max].out<info[i].out)
		  max=i;
	}
	cout<<info[min].id<<" "<<info[max].id<<endl;

	return 0;
}
