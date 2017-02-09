#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct _T
{
	int hh=8;
	int mm=0;
	int ss=0;

	int w=0;//waiting time
};
bool comp(_T a,_T b)
{
	/*
	直接这样用是不对的,必须考虑到=
	if(a.hh<b.hh||a.mm<b.mm||a.ss<b.ss)
	  return true;
	else
	  return false;
	  */
	if((a.hh*60*60+a.mm*60+a.ss)<
		(b.hh*60*60+b.mm*60+b.ss))
	  return true;
	else
	  return false;
}
vector<_T> customer;
vector<_T> waiter;
int N=0;
int K=0;

double compute()
{
	int ss_8_0_0=8*60*60;
	for(int i=0;i<customer.size();i++)
	{
		//注释的比较方式是明显错的，以后注意
		//if(customer.at(i).hh>=17&&customer.at(i).ss>=1)
		if((customer.at(i).hh*60*60+customer.at(i).mm*60+customer.at(i).ss)
					>=17*60*60+1)
		{
			//关于erase()后的vector内存变化待验证
			customer.erase(customer.begin()+i);
			i--;//调整访问迭代
			continue;
		}
		sort(waiter.begin(),waiter.end(),comp);
		int tmp=waiter.at(0).hh*60*60+
			waiter.at(0).mm*60+
			waiter.at(0).ss;
		int tmp2=customer.at(i).hh*60*60+
				customer.at(i).mm*60+
				customer.at(i).ss;

		//计算等待时间
		if(tmp>tmp2)
		  waiter.at(0).w+=(tmp-tmp2);
		else
		{
			//当k<customer到达时间时，不用等直接进去--->错了
			/*
			 * 2 1
			 * 16:59:59 30
			 * 16:59:50 30
			 * 0.0
			 * 当到达时，前边没有人，则应更新结束时，下一个人可用时间，
			 * 不然就只是8:00
			 * */
			waiter.at(0).hh=customer.at(i).hh;
			waiter.at(0).mm=customer.at(i).mm;
			waiter.at(0).ss=customer.at(i).ss;
		}

		tmp=waiter.at(0).mm+customer.at(i).w;
		waiter.at(0).mm=tmp%60;
		waiter.at(0).hh+=tmp/60;
	}
	double sum=0;
	for(int i=0;i<waiter.size();i++)
	{
		sum+=waiter.at(i).w;
	}
	if(customer.size()>0)
		return sum/60/customer.size();
	else
	  return 0;
}
int main()
{
	_T T;
	cin>>N>>K;
	waiter.assign(K,T);
	for(int i=0;i<N;i++)
	{
		scanf("%02d:%02d:%02d %lld",
					&T.hh,&T.mm,&T.ss,
					&T.w
			 );
		customer.push_back(T);
	}
	sort(customer.begin(),customer.end(),comp);
	printf("%.1f\n",compute());
	return 0;
}
