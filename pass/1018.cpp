#include<iostream>
#include<vector>
using namespace std;
int CMAX;
int N;
int SP;
int M;
/*
 * 2017/02/08
 * DFS求出所有最短距离
 * 本想用dijkstra算法的，可是不会求出所有最短集，还是缺联系呢！
 * 后边不上dijkstra算法的
 *
 * 最后一个测试点卡住了，提示段错误！查了半天，
 * vector的push_back pop_back审查可半天，么问题呀！
 * 最后猜测应该是自己定义的数组容量不够，仔细审题，
 * 果然！N<=500!!!!
 * */
int S [510][510] ;
int V [510] ;//访问
vector<int> C;
vector<vector<int> >out;
const int MAX=65500;
int dfs(int a,int b,int t,vector<int>tmp_p)
{
	if(a==b)
	{
		int tmp=0;
		int tmp_all=0;
		/*
		 *1.在入结果集前就把最短距离、带出的车量，带回的车量入队,
		 *省的，在比较时的再次计算！
		 *2.本题最坑的地方是：调整时是从出发开始，单向的，返回不调整！
		 *比如　4 16 0平衡后应该是 5 5 5，
		 *对于4　我们需要带出　1辆车
		 *16这多了11量车，接着我们带着11来到了0，卸掉5，返回6
		 *----------就是这么坑，可从题目分明看不出来嘛!!!!----------
		 *之前测试点部分正确的想法：把路上多余的车分摊，带回剩下的，
		 *如果不够，就不上。这种方式带出或者带回必有一个0
		 * */
		for(int i=0;i<tmp_p.size();i++)
		{
			if(C[tmp_p.at(i)]>=CMAX/2)
			  tmp_all+=(C[tmp_p.at(i)]-CMAX/2);
			else
			{
				//tmp_all路上保留，最后要带回来的
				//tmp需要从原站点取出的
				if(tmp_all<CMAX/2-C[tmp_p.at(i)])
				{
					tmp+=(CMAX/2-C[tmp_p.at(i)]-tmp_all);
					tmp_all=0;
				}else
				{
					tmp_all-=(CMAX/2-C[tmp_p.at(i)]);
				}
			}
		}
		tmp_p.push_back(t);
		tmp_p.push_back(tmp_all);
		tmp_p.push_back(tmp);

		if(out.size()>0)
		{
			int tmp1=out.at(0).at(out.at(0).size()-3);
			tmp=t;
			if(tmp<tmp1)
			{
				out.clear();
				out.push_back(tmp_p);
			}else if(tmp==tmp1)
			{
				tmp1=out.at(0).at(out.at(0).size()-1);
				tmp=tmp_p.at(tmp_p.size()-1);
				if(tmp<tmp1)
				{
					out.clear();
					out.push_back(tmp_p);
				}else if(tmp==tmp1)
				{
					out.push_back(tmp_p);
				}
			}
		}else
		{
			out.push_back(tmp_p);
		}
		tmp_p.pop_back();
		tmp_p.pop_back();
		tmp_p.pop_back();
		return out.size();
	}
	for(int i=1;i<=N;i++)
	{
		if(S[a][i]>0&&V[i]==0)
		{
		  V[i]=1;
		  tmp_p.push_back(i);
		  dfs(i,b,t+S[a][i],tmp_p);
		  tmp_p.pop_back();
		  V[i]=0;
		}
	}
	return 0;
}

int main()
{
	for(int i=0;i<100;i++)
	{
		V[i]=0;
		for(int j=0;j<100;j++)
		{
			S[i][j]=-1;
		}
	}
	cin>>CMAX>>N>>SP>>M;
	int tmp_c=0;
	C.push_back(0);
	for(int i=0;i<N;i++)
	{
		cin>>tmp_c;
		C.push_back(tmp_c);
	}
	int tmp_a=0;
	int tmp_b=0;
	int tmp_t=0;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_a>>tmp_b>>tmp_t;
		S[tmp_a][tmp_b]=tmp_t;
		S[tmp_b][tmp_a]=tmp_t;
	}
	
	vector<int>tmp_v;
	dfs(0,SP,0,tmp_v);
	int min=out.at(0).at(out.at(0).size()-2);
	int w=0;
	for(int i=0;i<out.size();i++) 
	{
		if(min>out.at(i).at(out.at(i).size()-2))
		{
			min=out.at(i).at(out.at(i).size()-2);
			w=i;
		}
	}
	cout<<out.at(w).at(out.at(w).size()-1)<<" 0";
	for(int i=0;i<out.at(w).size()-3;i++)
	{
		cout<<"->"<<out.at(w).at(i);
	}
    cout<<" "<<min<<endl;
	return 0;
}
