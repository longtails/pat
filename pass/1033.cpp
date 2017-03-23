#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
/*
 * 终于AC啦！
 *这道题确实有点复杂，仔细分析后条例很清晰,容易忽略边界条件!
 * */
using namespace std;
int c,d,davg,n;
//有同学使用的是pair,我要查一下stl,怎么用呢。
struct station
{
	long int d;
	double p;
};
vector<station>sta;
vector<station>out;
bool comp(station a,station b)
{
	//按照距离+价格两个因素排序
	//最开始是按照距离起点的距离排序的，这就出现一个问题，
	//同一个地点，有价格不同的加油站，排序就出现问题了。
	if(a.d<b.d)
	  return true;
	else if(a.d==b.d&&a.p<b.p)
	  return true;
	return false;
}
int main()
{
	station tmp;
	//测试用例
	freopen("in1033","r",stdin);
	cin>>c>>d>>davg>>n;
	int len=c*davg;
	for(int i=0;i<n;i++)
	{
		cin>>tmp.p>>tmp.d;
		sta.push_back(tmp);
	}
	sort(sta.begin(),sta.end(),comp);
	//忽略了，这种特殊情况。调整了算法，仍是该测试点错误，就该想到是特殊了呀！！-->pat 测试点2
	if(sta.at(0).d!=0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	//1.找到花费最少的站点，无论是否能到达目的地
	int cango=0;//表示，在加油站补充后，最远能跑多远
	int pre=0;//表示，上一次加油的站点
	int cur=-1;//表示，在可到达的范围内，价格都大于上个站点，记录其中价格最小的那个！
    out.push_back(sta.at(0));
    cango=sta.at(0).d+len;
	for(int i=1;i<sta.size();i++)
	{
		//可到达
		if(cango-sta.at(i).d>=0)
		{
			//如果价格比上一个站点便宜或者相同，不说什么了，直接更新
			if(sta.at(i).p<=sta.at(pre).p)
			{
				pre=i;
				out.push_back(sta.at(i));
				cango=sta.at(i).d+len;
				cur=-1;
			}else
			{
				//如果这个返回内，价格都比上个站点贵，则记录最小的那个
				if(cur==-1||sta.at(i).p<sta.at(cur).p)
				  cur=i;
				//当，pre=n-2,cur=n-1且又到达不了目的地时，cur也是要加入的
				//这是最后一个，直接结束 见测试用例１
				if(sta.at(i).d+len<d&&i+1==sta.size())
				{
					pre=i;
					out.push_back(sta.at(i));
					cango=sta.at(i).d+len;
					cur=-1;
					break;
				}
			}
		}else//当cango覆盖不了时，对所记录的最小cur，更新
		{
			if(cur!=-1&&cur<i)
			{
				i=cur;
				pre=i;
				out.push_back(sta.at(i));
				cango=sta.at(i).d+len;
				cur=-1;
			}
		}
	}
	//2.对筛选下来的站点，进行计算
	double lenP=0;//花费
	double length=0;//行走的距离，最后如果等于d,则到达目的地
	for(int i=0;i<out.size();i++)
	{
		// positive　number这种情况不存在! if(d==0)break;
		// 之前没有加(i+1<out.size()&&sta.at(i+1).d>=d)限制，会有一种用例失败，见用例2
		if(i+1==out.size()||(i+1<out.size()&&sta.at(i+1).d>=d))
		{
			if(out.at(i).d+len<d)
			{
				length=out.at(i).d+len;
			}else
			{
				lenP+=out.at(i).p*(d-length);
				length+=(d-length);
			}
		}else if(out.at(i).p>out.at(i+1).p)
		{
			//如果当前站点比下一个贵，那就只买到下一个站点。
			lenP+=out.at(i).p*(out.at(i+1).d-length);
			length=out.at(i+1).d;
		}else
		{
			//如果下一个站点，比这个站点便宜或者相同，那就加满油,len-(length-out.at(i).d)是当前最多能加的
			lenP+=out.at(i).p*(len-(length-out.at(i).d));
			length+=(len-(length-out.at(i).d));
		}
	}
	if(length==d)
		printf("%.2f\n",lenP/davg);
	else
		printf("The maximum travel distance = %.2f\n",length);
	return 0;
}
/*
 用例1
 当，pre=n-2,cur=n-1且又到达不了目的地时，cur也是要加入的
				
 50 2000 12 8
 8.00 1250
 7.00 600
 7.00 150
 7.10 0
 7.20 200
 7.50 400
 7.30 1000
 6.85 300
 ---->The maximum travel distance = 1850.00

 用例2
// 有加油站在目的城市的后边

 50 200 12 8
 6.00 1250
 7.00 600
 7.00 150
 7.10 0
 7.20 200
 7.50 400
 7.30 1000
 6.85 300
 --->117.92

 用例3,这是newcoder上的用例,一个距离多个站点
 30 2 3 10
 2145174067 0
 35 1
 2 0
 58 1
 67 1
 56 1
 42 1
 73 1
 19 0
 37 0
 ----->1.33
 
 */
