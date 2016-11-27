#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Fam
{
	int p;
	double sets;//自己的房产个数
	double area;//自己的房产总面积
	int c;
	Fam()
	{
		p=0;
		sets=0;
		area=0;
		c=1;
	}
}data[10010];
vector<int> group;
vector<int> all;
void un(int a,int b)
{
	int mina=a;
	while(mina!=data[mina].p)mina=data[mina].p;
	int minb=b;
	while(minb!=data[minb].p)minb=data[minb].p;
	if(mina>minb)data[mina].p=minb;
	else data[minb].p=mina;
}
bool big(int a,int b)
{
	if(data[a].area/data[a].c!=data[b].area/data[b].c)
	  return data[a].area/data[a].c>data[b].area/data[b].c;
	else
	  return data[a].p<data[b].p;
}
int main()
{
	int count=0;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		int my=0;
		int f=0;
		int m=0;
		int cc=0;
		int min=0;
		int tmp=0;
	
		cin>>my>>f>>m>>cc;
		if(data[my].p==0)
		{
		  all.push_back(my);
		  data[my].p=my;
		}
		if(f!=-1)
		{
			if(data[f].p==0)
			{
			  all.push_back(f);
			  data[f].p=f;
			}

			un(my,f);
		}
		if(m!=-1)
		{
			if(data[m].p==0)
			{
			  data[m].p=m;
			  all.push_back(m);
			}
			un(my,m);
		}
		for(int j=0;j<cc;j++)
		{
			cin>>tmp;
			if(data[tmp].p==0)
			{
			  data[tmp].p=tmp;
			  all.push_back(tmp);
			}
			un(my,tmp);
		}
		cin>>data[my].sets
			>>data[my].area;
	}
	for(int i=0;i<all.size();i++)
	{
	   int imin=all[i];
	   int icur=all[i];
	   while(imin!=data[imin].p)imin=data[imin].p;
	   data[all[i]].p=imin;
	   if(icur!=imin)
	   {
		   data[imin].area+=data[icur].area;
		   data[imin].sets+=data[icur].sets;
		   data[imin].c+=data[icur].c;
	   }else
		 group.push_back(imin);
	}
	cout<<group.size()<<endl;
	sort(group.begin(),group.begin()+group.size(),big);

	for(int i=0;i<group.size();i++)
	{
		int icur=group[i];
		printf("%04d %d %.3lf %.3lf\n",data[icur].p,
					data[icur].c,
					data[icur].sets/data[icur].c,
					data[icur].area/data[icur].c);
	}
	return 0;
}
