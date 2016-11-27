#include<iostream>
#include<vector>
using namespace std;

int path[510][510];
int hands[510];
bool visit[510];
int N,M,C1,C2;
int _min=-1;
int count=0;
int _max=-1;
void dfs(int a,int b,int len,int han)
{
	if(a==b)
	{
		if(_min==-1)
		{
		  _min=len;
		  count=1;
		  _max=han;
		}
		else if(_min>len)
		{
			count=1;
			_min=len;
			_max=han;
		}else if(_min==len)
		{
			//题目没说是在最短路中寻找最大人数
			//但想想也是啊
			count++;
			if(han>_max)
			  _max=han;
	
		}
		return ;
	}
	visit[a]=true;
	for(int i=0;i<N;i++)
	{
		if(path[a][i]!=-1&&visit[i]==false)
		dfs(i,b,len+path[a][i],han+hands[i]);
	}
	visit[a]=false;
}
int main()
{
	for(int i=0;i<510;i++)
	{
		visit[i]=false;
		for(int j=0;j<510;j++)
		  path[i][j]=-1;
	}
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++)
	{
		cin>>hands[i];
	}

	int x,y;
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		//没说单向路还是双向，那就是双向
		cin>>path[x][y];
		path[y][x]=path[x][y];
	}
	dfs(C1,C2,0,hands[C1]);
	cout<<count<<" "<<_max<<endl;
	
	return 0;
}
