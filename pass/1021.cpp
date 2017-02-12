#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N=0;
vector<vector<int> >node;
//以后可以写成　vector<int> node[10100];
//vector<vector<int> >node;
vector<int> v;
vector<int> f;
vector<int> out;
//get father　better way
//联通分支比较简单
//通过查并集确定连通分支还是比较简单的
//但是代码比较长，看到别人比较好的代码，
//待学习
int getF(int a)
{
	if(f[a]==a)return a;
    return f[a]=getF(f[a]);
}
int un(int a,int b)
{
	int fa=0;
	int fb=0;
	fa=getF(a);
	fb=getF(b);
	//注意更改父亲时，要更改成父亲的父亲而不是自己的父亲
	//不然迭代更新不了,就错乱了
	//尽管此时f[a]还没有更新，但可以通过getF()获取更新后的父亲
	if(fa>fb)f[fa]=fb;
	else if(fa<fb) f[fb]=fa;
	if(fa==fb)  return 0;
	return 1;
}
//dfs确定深度，方法很简单，但是容易超时，
//在pat上没有超时，但在new code上超时了
int dfs(int a)
{
	if(v[a]==1)
	  return 0;
	v[a]=1;
	int max=0;
	for(int i=0;i<node[a].size();i++)
	{
		if(v[node[a].at(i)]==0);
		{
			int tmp=dfs(node[a].at(i));
			if(tmp>max)
			  max=tmp;
		}
	}
	return max+1;
}
int main()
{
	cin>>N;
	vector<int> tmp_v;
	node.assign(N,tmp_v);
	f.assign(N,0);
	v.assign(N,0);
	int tmp=0;
	int tmp1=0;
	for(int i=0;i<N;i++)
	  f[i]=i;
	for(int i=0;i<N-1;i++)
	{
		cin>>tmp>>tmp1;
		un(tmp1-1,tmp-1);
		/*
		 * 根本不需要的,最初加上这玩意，支持错误，
		 * 这些工作在un中就已经做了
		if(tmp>tmp1)
		  f[tmp-1]=tmp1-1;
		else
		  f[tmp1-1]=tmp-1;
	    */
		node[tmp-1].push_back(tmp1-1);
		node[tmp1-1].push_back(tmp-1);
	}
	vector<int> ff;
	for(int i=0;i<N;i++)
		ff.push_back(getF(i));
	//去除相同,保证每个元素只有一个
	for(int i=0;i<ff.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(ff.at(i)==ff.at(j))
			{
			  ff.erase(ff.begin()+j);
			  i--;
			  break;
			}
		}
	}
	if(ff.size()>1)
	{
		cout<<"Error: "<<ff.size()<<" components"<<endl;
	}else
	{
		int count=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				v[j]=0;
			}
			int tmp=dfs(i);
			if(tmp>count)
			{
				out.clear();
				out.push_back(i);
				count=tmp;
			}else if(tmp==count)
			{
				out.push_back(i);
			}
		}
		//不用排序，直接输出，因为就是按顺序来查的
		for(int i=0;i<out.size();i++)
		  cout<<out.at(i)+1<<endl;
	}
	return 0;
}
