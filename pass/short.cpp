#include<iostream>
#include<climits>
#include<stack>
#define inf INT_MAX
using namespace std;

int a[510][510];
int b[510][510];
//求最短路径是选择 参数 a b 
//最短时间 参数 b a
//前结点保存在 a[i][i]中
int sp[510];//记录当前最短
int st[510];//记录当前最短
void dijkstra(int(*a)[510],int (*b)[510],int start,int end,int n)
{
	bool visit[510];
	//初始化,前序
	for(int i=0;i<n;i++)
	{
		visit[i]=false;
		sp[i]=inf;
		st[i]=inf;
	}
	a[start][start]=start;
	sp[start]=0;
	st[start]=0;
	visit[start]=true;

	int begin=start;
	while(true)
	{
		//更新
		for(int i=0;i<n;i++)
		{
			if(a[start][i]==-1)
			  continue;
			if(sp[i]>a[start][i]+sp[start])
			{
				sp[i]=a[start][i]+sp[start];
				st[i]=b[start][i]+st[start];
				//start=i;//这样不全
				a[i][i]=start;
			}else if(sp[i]==a[start][i]+sp[start])
			{
				if(st[i]>b[start][i]+st[start])
				{
					st[i]=b[start][i]+st[start];
					a[i][i]=start;
				}
			}
		}
		int min=inf;
		int begin=-1;
		//选择起始点，必须从全局找,这样的贪心才是最
		for(int i=0;i<n;i++)
		{
			if(!visit[i]&&sp[i]<min)
			{
				min=sp[i];
				begin=i;
			}
		}
		if(begin==-1)
		  break;
		start=begin;
		visit[start]=true;

		if(start==end)
		  break;
	}
	
}

//dijstra算法

int main()
{
	for(int i=0;i<510;i++)
	{
		for(int j=0;j<510;j++)
		{
			a[i][j]=-1;
			b[i][j]=-1;
		}
	}
	int  N,M;
	cin>>N>>M;
	int v1,v2,one_way,length,_time;
	for(int i=0;i<M;i++)
	{
		cin>>v1>>v2>>one_way;
		cin>>a[v1][v2];
		cin>>b[v1][v2];
		if(one_way==0)
		{
			a[v2][v1]=a[v1][v2];
			b[v2][v1]=b[v1][v2];
		}
	}
	int s,d;
	cin>>s>>d;

	bool isSame=true;
	stack<int> st1,st2;
	int Dis,Time;

	dijkstra(a,b,s,d,N);
	Dis=sp[d];
	int t=d;
	st1.push(d);

	while(true)
	{
		if(a[t][t]==t)
		  break;
		st1.push(a[t][t]);
		t=a[t][t];
	}

	dijkstra(b,a,s,d,N);
	Time=sp[d];

	t=d;
	st2.push(d);
	while(true)
	{
		if(b[t][t]==t)
		  break;
		if(b[t][t]!=a[t][t])
		  isSame=false;
		st2.push(b[t][t]);
		t=b[t][t];
	}

	if(isSame)
	{
		cout<<"Distance = "<<Dis<<"; Time = "<<Time<<": ";
		while(st1.empty()==false)
		{
			if(st1.top()==d)
			  cout<<st1.top()<<endl;
			else
				cout<<st1.top()<<" -> ";
			st1.pop();
		}
	}else
	{
		cout<<"Distance = "<<Dis<<": ";
		while(st1.empty()==false)
		{
			if(st1.top()==d)
			  cout<<st1.top()<<endl;
			else
				cout<<st1.top()<<" -> ";
			st1.pop();
		}

		cout<<"Time = "<<Time<<": ";
		while(st2.empty()==false)
		{
			if(st2.top()==d)
			  cout<<st2.top()<<endl;
			else
				cout<<st2.top()<<" -> ";
			st2.pop();
		}

	}

	return 0;
}
