#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int p[100005];
int d[100005];
vector<int> r;
int count=1;
int n; 
int deep(int site)
{
	if(site==0)
	  return 0;
	int pa=p[site];
	//就差这一步，备忘录，减少运算
	if(d[pa]==-1)
		return d[site]=deep(pa)+1;
	return d[site]=d[pa]+1;
}
int getdeep()
{
	int size=r.size();
	//int min=size+1;这是错误的
	int min=100005;
	for(int i=0;i<size;i++)
	{
		int tmp=r[i];
		int deep=0;
		for(int i=0;i<n;i++)
		{
			tmp=p[tmp];
			if(tmp==-1)
			  break;
			deep++;
		}
		/*
		while(p[tmp]!=-1)
		{
			deep++;
			tmp=p[tmp];
		}
		*/
		if(min>deep)
		{
			min=deep;
			count=1;
		}else if(min==deep)
		{
		  count++;
		}
	}
	return min;
}
int main()
{
	double price=0;
	double rate=0;
	memset(p,-1,sizeof(p));
	memset(d,-1,sizeof(d));
	cin>>n>>price>>rate;
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		cin>>tmp;
		if(tmp==0)
		{
		  r.push_back(i);
		}
		for(int j=0;j<tmp;j++)
		{
			int rs=0;
			cin>>rs;
			p[rs]=i;
		}
	}
	int min=100005;
	for(int i=0;i<r.size();i++)
	{
		int tmp=deep(r[i]);
		if(min>tmp)
		{
			min=tmp;
			count=1;
		}else if(min==tmp)
		  count++;
		
	}
//	int min=getdeep();
	double minp=price*pow(1+rate/100,min);
	printf("%.4f %d\n",minp,count);
	return 0;
}
//树  求从从树根到叶子路径最短的的情况
/*
struct tree
{
	bool leave;
	tree*p;
	tree()
	{
		p=NULL;
		leave=false;
	}
};
int count=1;
int lowest(vector<tree*>&t,vector<int>&v)
{
	int size=v.size();
	int min=size;
	for(int i=0;i<size;i++)
	{
		tree*tmp=t[i];
		if(tmp->leave==true)
		{
			while(tmp->p!=NULL)
			{
				v[i]++;
				tmp=tmp->p;
			}
			if(min>v[i])
			{
			  min=v[i];
			  count=1;
			} else if(min==v[i])
			{
				count++;
			}
		}
	}
	return min;
}
int main()
{
	int n=0;
	double price=0;
	double rate=0;

	vector<tree*>t;
	vector<int>v;
	cin>>n>>price>>rate;

	for(int i=0;i<n;i++)
	{
		tree *tmp=new tree;
		t.push_back(tmp);
		v.push_back(0);
	}
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		int tmp2=0;
		cin>>tmp;
		tree*ttmp=t[i];
		if(tmp==0)
		{
			t[i]->leave=true;
			continue;
		}
		for(int j=0;j<tmp;j++)
		{
			int pos;
			cin>>pos;
			tree*tt=t[pos];
			tt->p=ttmp;
		}
	}
	int min=lowest(t,v);
	double minp=price*pow(1+rate/100,min);
	printf("%.4f ",minp);
	cout<<count<<endl;
	return 0;
}
*/
