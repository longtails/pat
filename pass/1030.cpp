#include<iostream>
#include<climits>//INT_MAX头文件
#include<vector>
using namespace std;
const int MAX=INT_MAX;
int N,M,S,D;
int dist[510][510],cost[510][510];
int visit[510];
vector<int>pre[510];
//dfs选出相同路径中花费最少的
int dfs(int d,int c)
{
	if(d==S)
	  return c;
	int tmp_a,tmp_b,min;
	tmp_b=MAX;
	//选出花费最少
	for(int i=0;i<pre[d].size();i++)
	{
		tmp_a=dfs(pre[d].at(i),c+cost[d][pre[d].at(i)]);
		if(tmp_a<tmp_b)
		{
			tmp_b=tmp_a;
			min=pre[d].at(i);
		}
	}
	cost[min][min]=d;//路径链接
	return tmp_b;
}
int main()
{
	//保存记录
	fill(cost[0],cost[0]+510*510,MAX);
	fill(dist[0],dist[0]+510*510,MAX);
	fill(visit,visit+510,0);
	
	cin>>N>>M>>S>>D;
	int tmp_a,tmp_b;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_a>>tmp_b;
		cin>>dist[tmp_a][tmp_b];
		cin>>cost[tmp_a][tmp_b];
		dist[tmp_b][tmp_a]=dist[tmp_a][tmp_b];
		cost[tmp_b][tmp_a]=cost[tmp_a][tmp_b];
	}
	//dijkstra找出最短路径
	int min=S;
	dist[min][min]=0;
	int min_cost=MAX;
	//dijkstra算法
	while(true)
	{
		//get min
		min_cost=MAX;
		for(int i=0;i<N;i++)
		{
			if(visit[i]==0&&dist[i][i]<min_cost)
			{
				min_cost=dist[i][i];
				min=i;
			}
		}
		if(visit[min]==1)
		  break;
		dist[min][min]=min_cost;
		visit[min]=1;
		//relax 松弛
		for(int i=0;i<N;i++)
		{
			if(visit[i]==1||dist[min][i]==MAX)
			  continue;
			if(dist[min][min]+dist[min][i]<dist[i][i])
			{
				dist[i][i]=dist[min][min]+dist[min][i];
				pre[i].clear();
				pre[i].push_back(min);
				//最短路径不是一条
			}else if(dist[min][min]+dist[min][i]==dist[i][i])
				pre[i].push_back(min);
		}
	}
	min_cost=dfs(D,0);
	int cur=S;
	while(true)
	{
		cout<<cur<<" ";
		cur=cost[cur][cur];
		if(cur==D)
		  break;
	}
	cout<<cur<<" "<<dist[D][D]<<" "<<min_cost<<endl;
	return 0;
}
