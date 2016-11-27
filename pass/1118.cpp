#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
/*
 * 不相交数组
 * */
#define max 10010
int birds[max];
int used[max];
//用birds[0]记录不相交数组的个数
void init()
{
	for(int i=0;i<max;i++)
	{
		birds[i]=i;
		used[i]=0;
	}
}
//这一步不错
int findfather(int x)
{
	if(x==birds[x])
	{
		//链式向外传递
		return x;
	}
	return findfather(birds[x]);
}
//当然还有这
void union_set(int x,int y)
{
	//到着的树
	if(x!=birds[x])
	  x=findfather(x);
	if(y!=birds[y])
	  y=findfather(y);
	//变换的只有root
	if(x==y)
	{
	  return;
	}
	if(x<y)
	{
		birds[y]=x;
	}else
	{
		//当前不用担心
		birds[x]=y;
	}
}

int main()
{
	init();
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m=0;
		cin>>m;
		int x=0;
		int y=0;
		cin>>x;
		used[x]=1;
		for(int j=1;j<m;j++)
		{
			cin>>y;
			used[y]=1;
			union_set(x,y);
			x=y;
		}
	}
	int p=0;
	cin>>p;
	int x=0;
	int y=0;
	string *tree=new string[p];
	for(int i=0;i<p;i++)
	{
		cin>>x>>y;
		int xf=findfather(x);
		int yf=findfather(y);
		if(xf==yf)
		  tree[i]="Yes";
		else
		  tree[i]="No";
	}
	map<int,int> root;
	for(int i=1;i<max;i++)
	{
		if(used[i])
		{
			int tmp=findfather(i);
			root[tmp]=i;
			used[0]++;
		}
	}
	birds[0]=root.size();
	cout<<birds[0]<<" "<<used[0]<<endl;
	for(int i=0;i<p;i++)
	{
		cout<<tree[i]<<endl;
	}
	delete[]tree;
	return 0;
}





