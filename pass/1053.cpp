#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int nodeWeight[110];
vector<int> tree[110];
int check[110];
bool comp(int a,int b)
{
	return nodeWeight[a]<nodeWeight[b];
}
//右递归下去
vector<int> seq;
void checkTree(int child,long w,long s,vector<int>& seq)
{
	if(child>=110)return;
	if(w>s)return;
	if(tree[child].size()==0)
	{
		//leaf
		if(w==s)
		{
		  for(int k=0;k<seq.size()-1;k++)
		  {
			  printf("%d ",seq[k]);
		  }
		  printf("%d\n",seq[seq.size()-1]);
		  return;
		}
		return;
	}
	for(int i=tree[child].size()-1;i>=0;i--)
	{
		w+=nodeWeight[tree[child][i]];
		seq.push_back(nodeWeight[tree[child][i]]);
		checkTree(tree[child][i],w,s,seq);
		w-=nodeWeight[tree[child][i]];
		seq.pop_back();
	}
}

int main()
{
	freopen("in","r",stdin);
	fill_n(nodeWeight,110,0);
	fill_n(check,110,0);
	int N,M,tmp;
	long S;
	scanf("%d%d%ld",&N,&M,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&tmp);
		nodeWeight[i]=tmp;
	}
	int count=0;
	int child=0;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&tmp,&count);
		for(int j=0;j<count;j++)
		{
			scanf("%d",&child);
			tree[tmp].push_back(child);
		}
		//按w递增
		sort(tree[tmp].begin(),tree[tmp].end(),comp);
	}
	seq.push_back(nodeWeight[0]);
	checkTree(0,nodeWeight[0],S,seq);
	return 0;
}

