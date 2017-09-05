#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Node
{
	int ads;
	int key;
	int next;
};
int NEXT[100010];
int one[100010];
vector<Node> nodes;
bool comp(Node a,Node b)
{
	return a.key<b.key;
}
int main()
{
	freopen("in","r",stdin);
	int N,ads,tmp;
	Node node;
	fill_n(NEXT,100010,-1);
	scanf("%d%d",&N,&ads);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",&node.ads,
					&node.key,
					&node.next);
		nodes.push_back(node);
		NEXT[node.ads]=node.next;
	} 
	//attention1:这些节点中有些可能不在一条链上
	int count=0;//记录链中的节点
	while(ads>0&&NEXT[ads]>0)
	{
		count++;
		tmp=ads;
		ads=NEXT[ads];
		NEXT[tmp]=-2;
	}
	if(ads>=0)//attention2 head ads=-1则表示没有节点 
	{
		NEXT[ads]=-2;
		count++;
	}
	sort(nodes.begin(),nodes.end(),comp);
	printf("%d ",count);
	for(int i=0;i<N;i++)
	{
		if(NEXT[nodes[i].ads]==-2)
		printf("%.5d\n%.5d %d ",nodes[i].ads,
					nodes[i].ads,
					nodes[i].key);
	}
	printf("-1\n");
	return 0;
}

