#include<iostream>
#include<vector>
using namespace std;
#define N 510
#define MAX 65535
//dijsktra算法还是需要继续努力的
//使用搜索算法
 
int path[N][N];
int _time[N][N];
bool visit[N];


vector<int> shortPath(2,0);
vector<int> tmp(2,0);
int count=0;
void findPath(int u,int v)
{
	if(u==v)
	{
		if(shortPath[0]==0)
		{
			shortPath=tmp;
			shortPath.push_back(u);
		}else
		{
			if(tmp[0]<shortPath[0])
			{
				shortPath=tmp;
				shortPath.push_back(u);
			}else if(tmp[0]==shortPath[0])
			{
				if(tmp[1]<shortPath[1])
				{
					shortPath=tmp;
					shortPath.push_back(u);
				}
			}
		}
		return;
	}
	for(int i=1;i<=count;i++)
	{
		if(u==i)
		  continue;
		if(path[u][i]!=-1&&visit[i]==false)
		{
			tmp.push_back(u);
			tmp[0]+=path[u][i];
			tmp[1]+=_time[u][i];
			visit[u]=true;
			findPath(i,v);

			visit[u]=false;
			tmp.pop_back();
			tmp[0]-=path[u][i];
			tmp[1]-=_time[u][i];
		}
	}
}

int main()
{
	int m=0;
	int n=0;
	cin>>m>>n;
	count=m;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			path[i][j]=-1;
			_time[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		int tmp1;
		int tmp2;
		int tmp3;
		int tmp4;
		int tmp5;
		cin>>tmp1>>tmp2>>tmp3;
		cin>>tmp4>>tmp5;
		path[tmp1][tmp2]=tmp4;
		_time[tmp1][tmp2]=tmp5;
		//双向路
		if(tmp3==0)
		{
			path[tmp2][tmp1]=path[tmp1][tmp2];
			_time[tmp2][tmp1]=_time[tmp1][tmp2];
		}
	}
	cin>>m>>n;
	findPath(m,n);

	vector<int> _shortPath=shortPath;
	shortPath.clear();
	tmp.clear();
	shortPath.push_back(0);
	shortPath.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);

	int local=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			local=path[i][j];
			path[i][j]=_time[i][j];
			_time[i][j]=local;
		}
	}
	findPath(m,n);

	bool unique=false;
	if(_shortPath.size()==shortPath.size())
	{
		int tmp=2;
		for(int i=2;i<shortPath.size();i++)
		{
			if(shortPath[i]==_shortPath[i])
			{
			  tmp++;
			}
		}
		if(tmp==shortPath.size())
			  unique=true;

	}
	if(unique)
	{
		cout<<"Distance = "<<_shortPath[0]<<"; Time = "<<_shortPath[1]<<": ";
		for(int i=2;i<shortPath.size()-1;i++)
		{
			cout<<_shortPath[i]<<" -> ";
		}
		cout<<_shortPath[_shortPath.size()-1]<<endl;

	}else
	{
		cout<<"Distance = "<<_shortPath[0]<<": ";
		for(int i=2;i<_shortPath.size()-1;i++)
			cout<<_shortPath[i]<<" -> ";
		cout<<_shortPath[_shortPath.size()-1]<<endl;

		cout<<"Time = "<<shortPath[0]<<": ";
		for(int i=2;i<shortPath.size()-1;i++)
			cout<<shortPath[i]<<" -> ";
		cout<<shortPath[shortPath.size()-1]<<endl;
	}

	return 0;

}
















