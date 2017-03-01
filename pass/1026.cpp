#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct _T
{
	int b;
	int p;
	int w;
	int v;
	int flag;
	int c;//table
};
int N;
int K;
int M;
vector<_T>in;
vector<_T>table;//只使用b,v
_T tmp_t;
int getVip(long int a,long int b)
{
	for(int i=b;i<N;i++)
	{
		if(in.at(i).flag>0)
		  continue;
	   if(in.at(i).b<=a)
	   {
		  if(in.at(i).v==1)
		    return i;
	   }else
		 return -1;
	}
	return -1;
}
//按服务时间排序
bool isSmall(_T a,_T b)
{
	if(a.b+a.w<b.b+b.w)
	  return true;
	else if(a.b+a.w==b.b+b.w)
	{
		if(a.v==1&&b.v==0)
		  return true;
	}
	return false;
}
void  outputT(int a)
{
	int h=a/3600;
	int m=(a/60)%60;
	int s=a%60;
	printf("%02d:%02d:%02d",
				h,m,s);
}
int main()
{
	cin>>N;
	int h,m,s;
	tmp_t.w=0;
	tmp_t.flag=0;
	tmp_t.c=0;
	for(int i=0;i<N;i++)
	{
		scanf("%02d:%02d:%02d %d %d",
					&h,&m,&s,&tmp_t.p,&tmp_t.v);
		if(tmp_t.p>120)
			tmp_t.p=120;
		tmp_t.b=h*3600+m*60+s;
		tmp_t.p*=60;
		in.push_back(tmp_t);
	}
	cin>>K>>M;
	tmp_t.b=8*3600;
	tmp_t.v=0;
	table.assign(K,tmp_t);
	int v;
	for(int i=0;i<M;i++)
	{
		cin>>v;
		table.at(v-1).v=1;
	}
	//sort in
	sort(in.begin(),in.end(),isSmall);
	for(int i=0;i<N;i++)
	{
		if(in.at(i).flag==1)
		  continue;
		if(in.at(i).b>=21*3600)
		{
			in.at(i).flag=2;
			 continue;
		}
		//get table avalible
		int vj=-1;
		int vjj=-1;
		//+++++++++++++++++++++++++++++++++++++++++++++++++++1
		for(int j=0;j<K;j++)
		{
			//找到不需要等待，直接可以用的桌子，从小号开始
			/*
			if(table.at(j).b<=in.at(i).b)//wait
			{
			//这样合有个问题，就是没有vip桌子，但有普通桌子时，vj会显示没有桌子可用,还是分开吧
				if(in.at(i).v==1)
					if(table.at(j).v==1){vj=j;break;}
				else{	vj=j;break;}
			}
			*/
			if(table.at(j).b<=in.at(i).b)//wait
			{
					vj=j;
					break;
			}
		}
		for(int j=0;j<K;j++)
		{
			if(table.at(j).b<=in.at(i).b)//wait
			{
				if(table.at(j).v==1)
				{
					vjj=j;
					break;
				}
			}
		}
		if(in.at(i).v==1)
		{
			//有vip桌子可用,没有时就是用普通桌子
			if(vjj>-1)
			  vj=vjj;
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++2
		//get min table
		/*所有的table时间小于用户到达时间时vj==-1，需要选择最小的table,这是是按table时间*/
		if(vj==-1)
		{
			vj=0;
			int tmp=table.at(0).b;
			for(int j=0;j<K;j++)
			{
				if(tmp>table.at(j).b)
				{
					vj=j;
					tmp=table.at(j).b;
				}
			}

		}
		int vi=-1;
		if(table.at(vj).b>=21*3600)
		  break;

		//+++++++++++++++++++++++++++++++++++++++++++++++++++3
		int vip_pre=getVip(table.at(vj).b,i);
		//等待的人员有vip
		if(vip_pre>=0)
		{
			//找合适的vip桌子，从小号开始
			int tmp_vip=table.at(vj).b;
			for(int j=0;j<K;j++)
			{
				if(table.at(j).v==1&&table.at(j).b<=table.at(vj).b)
				{
					vj=j;
					break;
				}
			}
		}
		table.at(vj).c++;
		if(table.at(vj).v==1)vi=vip_pre;
		
		if(vi<=0)vi=i;
		else i--;//如果是找到vip，则需要校正等待人员

		in.at(vi).flag=1;
		if(table.at(vj).b<in.at(vi).b)//dont wait
		{
			in.at(vi).w=0;
			table.at(vj).b=in.at(vi).b;//更新服务时间
		}else 	
		  in.at(vi).w=table.at(vj).b-in.at(vi).b;
		//更新为服务结束时间
		table.at(vj).b+=in.at(vi).p;
	}

	//按服务时间排序
	sort(in.begin(),in.end(),isSmall);
	for(int i=0;i<in.size();i++)
	{
		if(in.at(i).flag!=1)
		  continue;
		outputT(in.at(i).b);
		cout<<" ";
		outputT(in.at(i).b+in.at(i).w);
		//按满30进位
		if(in.at(i).w%60>=30)
		  cout<<" "<<in.at(i).w/60+1<<endl;
		else
		  cout<<" "<<in.at(i).w/60<<endl;
	}

	for(int i=0;i<K-1;i++)
	  cout<<table.at(i).c<<" ";
	cout<<table.at(table.size()-1).c<<endl;
	return 0;
}
/*
    主要是有几个条件不明。条件太多。
        they will be assigned to the available table with the smallest number.我们在安排桌子时要按照从小到达安排。安排vip桌子时也是从小开始。
        如果没有vip桌子可用，那要用普通桌子。
        It is assumed that every pair of players can play for at most 2 hours.玩的时间最多2小时，超过2h,需要我们截取。pat_a 4号(第5个)测试点。牛客网有一个138人的测试点。
        The waiting time must be rounded up to an integer minute(s). 最后输出时间，取整（round不是直接舍去多余的小数，直接进一个么！不是向上取整么！），要四舍五入到分。pat最后一个一分的测试点。牛客网没有这个测试点。
        Notice that the output must be listed in chronological order of the serving time.输出按服务时间的先后顺序排。
        开放时间 8:00-21:00
    设计思路
    按时间轴开始，排序后的用户（到达顺序）—>处理（1、不需要等待，直接处理 2、需要等待，要寻找结束最早的桌子，时间轴为桌子）–>如果遇到vip，校正用户，时间轴为用户。
*/
