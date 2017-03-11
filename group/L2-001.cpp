#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int N,M,S,D;
int city[510][510];
int total[510],count[510],visit[510],pathNum[510],pre[510];
int count_path=0;
const int MAX=INT_MAX;
void dfs(int D)
{
	if(D==S)
	{
	  cout<<D;
	  return ;
	}
	dfs(pre[D]);
	cout<<" "<<D;
}
int main()
{
	fill(visit,visit+510,0);
	fill(city[0],city[0]+510*510,MAX);
	cin>>N>>M>>S>>D;
	for(int i=0;i<N;i++)
	  cin>>count[i];
	int tmp_a,tmp_b,tmp_c;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_a>>tmp_b>>tmp_c;
		city[tmp_a][tmp_b]=tmp_c;
		city[tmp_b][tmp_a]=city[tmp_a][tmp_b];
	}
	//dijkstra
	int min_dist=MAX;
	int min=S;
	city[S][S]=0;
	total[S]=count[S];
	pathNum[S]=1;
	while(true)
	{
		min_dist=INT_MAX;
		//get min
		for(int i=0;i<N;i++)
		{
			if(visit[i]==0&&city[i][i]<min_dist)
			{
				min_dist=city[i][i];
				min=i;
			}
		}
		if(visit[min]==1)
		  break;
		visit[min]=1;
		//relax
		for(int i=0;i<N;i++)
		{
			if(visit[i]==1||city[min][i]==MAX)
			  continue;
			if(city[min][min]+city[min][i]<city[i][i])
			{
				city[i][i]=city[min][min]+city[min][i];
				pre[i]=min;
				total[i]=total[min]+count[i];
				pathNum[i]=pathNum[min];
			}else if(city[min][min]+city[min][i]==city[i][i])
			{
				pathNum[i]+=pathNum[min];
				//这道题说的是尽快，尽量多，所确定的路径是唯一的。
				if(total[min]+count[i]>total[i])
				{
				  total[i]=total[min]+count[i];
				  pre[i]=min;
				}
			}
		}
	}
	//路径个数
	cout<<pathNum[D]<<" "<<total[D]<<endl;
	dfs(D);
	cout<<endl;
	return 0;
}
/*
 4 4 0 3
 10 20 30 30
 0 1 1
 0 2 2
 1 3 1
 2 3 2

 1 60
 0 1 3

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int N,M,S,D;
int city[510][510];
int count[510];
int visit[510];
vector<int> pre[510];
vector<int>out;
int count_path=0;
const int MAX=INT_MAX;
int max_cost=-1;
int dfs(int D,int C)
{
	if(D==S)
	{
	  count_path++;
	  return C;
	}
	int tmp_a,tmp_b,min;
	tmp_b=0;

	for(int i=0;i<pre[D].size();i++)
	{
		tmp_a=dfs(pre[D].at(i),C+count[pre[D].at(i)]);
		if(tmp_a>tmp_b)
		{
			tmp_b=tmp_a;
			if(tmp_b>max_cost)
			  max_cost=tmp_b;
			min=pre[D].at(i);
		}
	}
	//确定是最优那条路
	if(max_cost==tmp_b)
		out.push_back(min);
	return tmp_b;
}
int main()
{
	fill(visit,visit+510,0);
	fill(city[0],city[0]+510*510,MAX);
	cin>>N>>M>>S>>D;
	for(int i=0;i<N;i++)
	  cin>>count[i];
	int tmp_a,tmp_b,tmp_c;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_a>>tmp_b>>tmp_c;
		city[tmp_a][tmp_b]=tmp_c;
		city[tmp_b][tmp_a]=city[tmp_a][tmp_b];
	}
	//dijkstra
	int min_dist=MAX;
	int min=S;
	city[S][S]=0;
	while(true)
	{
		min_dist=INT_MAX;
		//get min
		for(int i=0;i<N;i++)
		{
			if(visit[i]==0&&city[i][i]<min_dist)
			{
				min_dist=city[i][i];
				min=i;
			}
		}
		if(visit[min]==1)
		  break;
		visit[min]=1;
		//relax
		for(int i=0;i<N;i++)
		{
			if(visit[i]==1||city[min][i]==MAX)
			  continue;
			if(city[min][min]+city[min][i]<city[i][i])
			{
				city[i][i]=city[min][min]+city[min][i];
				pre[i].clear();
				pre[i].push_back(min);
			}else if(city[min][min]+city[min][i]==city[i][i])
			{
				pre[i].push_back(min);
			}
		}
	}
	int tmp=dfs(D,count[D]);
	cout<<count_path<<" "<<tmp<<endl;
	for(int i=0;i<out.size();i++)
	{
		cout<<out.at(i)<<" ";
	}
	cout<<D<<endl;
	return 0;
}
 */
