#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int N,M,K,Q;
int pre[22];
int sum[22];
queue<int>que[22];
queue<int>qwait[22];
vector<int>out;
int main()
{
	cin>>N>>M>>K>>Q;
	int tmp;
	for(int i=0;i<K;i++)
	{
		cin>>tmp;
		if(i<M*N)
		{
			//这部分没有按最短窗口时间排队
			que[i%N].push(tmp);
			//窗口有空闲时也得考虑17:00之前能否接受服务
			if(sum[i%N]>=540)
				out.push_back(-1);
			else
			{
				sum[i%N]+=tmp;
				out.push_back(sum[i%N]);
			}
			//计算入out
		}else
		{
				int min=que[0].front()+pre[0];
				int p=0;
				//选择最先空闲的窗口
				for(int j=0;j<N;j++)
				{
					//pre为从8:00开始到前一个用户结束的总时间差
					//加上当前用户所需时间，即可选出最先结束服务的窗口
					if(min>que[j].front()+pre[j])
					{
						min=que[j].front()+pre[j];
						p=j;
					}
				}
				//用于选择窗口
				pre[p]=min;
				que[p].pop();
				que[p].push(tmp);

				//17:00之前能否接受服务
				if(sum[p]>=540)
					out.push_back(-1);
				else
				{
					//更新当前用户完成服务，距离8:00的总时间差
					sum[p]+=tmp;//计算完成时间
					out.push_back(sum[p]);
				}
		}
	}
	for(int i=0;i<Q;i++)
	{
		cin>>tmp;
		tmp=out[tmp-1];
		if(tmp==-1)
		{
			printf("Sorry\n");
			continue;
		}
		printf("%02d:%02d\n",8+tmp/60,tmp%60);
	}

	return 0;
}
