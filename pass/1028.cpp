#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<cstring>
int N;
int C;
using namespace std;
struct IN
{
	int num;
	char name[30];
	int score;
};
list<IN>d;
bool comp1(IN a,IN b)
{
	if(a.num<b.num)
	  return true;
	else
	  return false;
}
bool comp2(IN a,IN b)
{
	int c=strcmp(a.name,b.name);
	if(c<0)
	  return true;
	else if(c>0)
	  return false;
	else
	{
	  if(a.num<b.num)
		return true;
	  else
		return false;
	}
}
bool comp3(IN a,IN b)
{
	if(a.score<b.score)
	  return true;
	else if(a.score>b.score)
	  return false;
	else
	{
	  if(a.num<b.num)
		return true;
	  else
		return false;
	}
}
int main()
{
	cin>>N>>C;
	IN tmp;
	for(int i=0;i<N;i++)
	{
		/*
		长见识了，cin cout太慢，并不是算法的问题
		cin>>tmp.num>>tmp.name>>tmp.score;
		*/
		scanf("%d %s %d",
					&tmp.num,
					tmp.name,
					&tmp.score);
		d.push_back(tmp);
	}

	switch(C)
	{
		case 1:
			d.sort(comp1);
			break;
		case 2:
			d.sort(comp2);
			break;
		case 3:
			d.sort(comp3);
			break;
		default:
			break;
	}
/*
	switch(C)
	{
		case 1:
			sort(d.begin(),d.end(),comp1);
			break;
		case 2:
			sort(d.begin(),d.end(),comp2);
			break;
		case 3:
			sort(d.begin(),d.end(),comp3);
			break;
		default:
			break;
	}
	*/
	list<IN>::iterator it;
	for(it=d.begin();it!=d.end();++it)
	{
		printf("%06d %s %d\n",
					it->num,
					it->name,
					it->score);
	}
	return 0;
}
