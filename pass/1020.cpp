#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N=0;
vector<int> iner;
vector<int> post;
vector<int> dep;
vector<int> level;
int cur=0;
void deep(int a,int b,int d=0)
{
	if(a>b)
	  return;
	int w=-1;
	//确定节点
	for(int j=a;j<=b;j++)
	{
		if(post.at(cur)==iner.at(j))
		{
			w=j;
			break;
		}
	}
	if(w==-1)
	  return;
	cur--;
	level.at(d)=w;
	//先访问友子树
	deep(w+1,b,2*d+1);
	deep(a,w-1,2*d);
}
int main()
{
	int tmp=0;
	cin>>N;
	level.assign(10000,-1);
	cur=N-1;
	dep.assign(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		post.push_back(tmp);
	}
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		iner.push_back(tmp);
	}
	deep(0,iner.size()-1,1);
	cout<<iner.at(level.at(1));
	for(int i=2;i<10000;i++)
	{
		if(level.at(i)!=-1)
		  cout<<" "<<iner.at(level.at(i));
	}
	cout<<endl;
	return 0;
}


/****************************处理笔记****************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N=0;
vector<int> iner;
vector<int> post;
int  dep [10000];
//vector<int> dep;
int cur=0;
/*自己写的冒泡排序算法，最开始用的是algorithm的排序算法，
 * 但是由于不了解其内部算法，导致部分检测点错误，自己写排序解决了这个算法*/
void sort(vector<int> &a)
{
	int tmp=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=1;j<a.size()-i;j++)
		{
			if(dep[a.at(j-1)]>dep[a.at(j)])
			{
				tmp=a.at(j-1);
				a.at(j-1)=a.at(j);
				a.at(j)=tmp;
			}
		}
	}
}
/*
 * algorithm sort排序算法
bool comp(int a,int b)
{
	return dep[a]<dep[b];
}
*/

/*
 //树的确定方法1,自己最开始的笨蛋算法
 void deep(int a,int b,int d=0)
{
	if(a>b)
	  return;
	int w=-1;
	//确定节点
	for(int i=post.size()-1;i>=0;i--)
	{
		for(int j=a;j<=b;j++)
		{
			if(post.at(i)==iner.at(j))
			{
				w=j;
				break;
			}
		}
		if(w!=-1)
		  break;
	}
	if(w==-1)
	  return;
	//先序遍历,记录节点深度
	dep.at(iner.at(w))=d;
	deep(a,w-1,d+1);
	deep(w+1,b,d+1);
}*/
//树的确定方法2
//这是参考别人,LRN倒退确定顶点算法
void deep(int a,int b,int d=0)
{
	if(a>b)
	  return;
	int w=-1;
	//确定节点
	for(int j=a;j<=b;j++)
	{
		if(post.at(cur)==iner.at(j))
		{
			w=j;
			break;
		}
	}
	if(w==-1)
		return;
	cur--;
	//先序遍历,记录节点深度
	//pat会返回异常退出结果，改成如下的数组
	//dep.at(iner.at(w))=d; 形式，即可得到正确结果
	dep[iner.at(w)]=d;
	//先访问右子树
	deep(w+1,b,d+1);
	deep(a,w-1,d+1);
}
int main()
{
	int tmp=0;
	cin>>N;
	cur=N-1;
	for(int i=0;i<10000;i++)
	  dep[i]=-1;
	//矫正成0~N-1
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		post.push_back(tmp-1);
	}
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		iner.push_back(tmp-1);
	}

	deep(0,iner.size()-1,0);
	qsort(iner);
	//algorithm　sort会破坏序列的LR位置,会部分测试点错误
	//sort(iner.begin(),iner.end(),comp);
	cout<<iner.at(0)+1;
	for(int i=1;i<iner.size();i++)
	  cout<<" "<<iner.at(i)+1;
	cout<<endl;
	/*
	 * 对于LRN和LNR的序列，他们均保持 LR关系，因此简单排序后即可得到所需序列
	sort(post.begin(),post.end(),comp);
	cout<<post.at(0)+1;
	for(int i=1;i<post.size();i++)
	  cout<<" "<<post.at(i)+1;
	cout<<endl;
	*/
	return 0;
}

