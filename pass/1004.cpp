#include<iostream>
#include<vector>
using namespace std;
struct _T
{
	int d;//深度
	int p;//父亲
	int count;
	vector<int>c;//孩子
};
_T tree[100];
vector<int> td;
//0--用来记录层
#include<climits>
int _max=-1;
void upDeep(_T& t,int d)
{
	if(t.c.size()==0)
	{
		t.d=d;
		if(d>_max)
		  _max=d;
		return;
	}
	for(int i=0;i<t.c.size();i++)
	  upDeep(tree[t.c[i]],d+1);
}
void dfs(_T &t)
{
	if(t.c.size()==0)
	{
		td[t.d]++;
		return ;
	}
	for(int i=0;i<t.c.size();i++)
	{
	  dfs(tree[t.c[i]]);
	}
}
int main()
{
	int N,M,ID,K,CH;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		cin>>ID>>K;
		for(int j=0;j<K;j++)
		{
			cin>>CH;
			tree[ID].c.push_back(CH);
			tree[CH].p=ID;
		}
	}
	upDeep(tree[1],1);
	td.assign(_max+1,0);
	dfs(tree[1]);
	for(int i=1;i<td.size();i++)
	{
		if(i==td.size()-1)
		  cout<<td[i]<<endl;
		else
		  cout<<td[i]<<" ";
	}
	return 0;
}
