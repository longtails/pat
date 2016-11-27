#include<iostream>
#include<vector>
#include<string>
using namespace std;
int l[15];
int r[15];
int n[15];
vector<vector<int>>out;
void level(int i,int d)
{
	if(out.size()<=d)
	{
		vector<int> tmp;
		tmp.push_back(i);
		out.push_back(tmp);
	}else
	  out[d].push_back(i);
	if(r[i]!=-1)
	  level(r[i],d+1);
	if(l[i]!=-1)
	  level(l[i],d+1);
}
void in(int i,int last)
{
	if(r[i]!=-1)
	{
		in(r[i],last);
	}
	cout<<i;
	n[i]=-1;
	if(last!=i)
	  cout<<" ";
	else
	  cout<<endl;
	
	if(l[i]!=-1)
	{
	  in(l[i],last);
	}
}
int main()
{
	int count=0;
	string tmp;

	int head=0;
	cin>>count;


	for(int i=0;i<15;i++)
	{
		l[i]=-1;
		r[i]=-1;
		n[i]=-1;
	}
	

	for(int i=0;i<count;i++)
	{
//		l[i]=-1;
//		r[i]=-1;
//		n[i]=-1;在这是有问题的,初始化的问题
		n[i]=-1;

		cin>>tmp;
		if(tmp!=string("-"))
		{
		  l[i]=stoi(tmp,nullptr,0);
		  n[l[i]]=i;
		  head=i;
		}
		cin>>tmp;
		if(tmp!=string("-"))
		{
		  r[i]=stoi(tmp,nullptr,0);
		  n[r[i]]=i;
		  head=i;
		}
	}
	//find head
	while(true)
	{
		if(n[head]==-1)
		{
			break;
		}else
		  head=n[head];
	}

	level(head,0);
	for(int i=0;i<out.size();i++)
	{
		for(int j=0;j<out[i].size();j++)
		{
			cout<<out[i][j];
			if(j==out[i].size()-1)
			if(i==out.size()-1)
			{
			  cout<<endl;
			  break;
			}
			cout<<" ";
		}
	}
	int ll=head;

	while(true)
	{
		if(l[ll]==-1)
		{
			break;
		}else
		  ll=l[ll];
	}
	in(head,ll);
	return 0;
}
