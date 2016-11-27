#include<iostream>
#include<vector>

using namespace std;
struct Map
{
	int len;
	int time;
	Map()
	{
		len=0;
		time=0;
	}
};
Map _map[510][510];
int v[510][510];

int citys;
vector<int>out;
vector<int>tmp;
int _max=999999;
int _max_time=999999;
int tmpPath=99999;
int tmpTime=99999;
		
vector<int>out_time;
void getShort(int s,int d,int ss=0,int tt=0)
{
	if(s==d)
	{
		if(ss<_max)
		{
		  _max=ss;
		  _max_time=tt;
		  out.clear();
		  out=tmp;
		}else if(ss==_max)
		{
			if(tt<_max_time)
			{
				_max_time=tt;
				out.clear();
				out=tmp;
			}
		}
		if(tt<tmpTime)
		{
			tmpTime=tt;
			tmpPath=ss;
			out_time.clear();
			out_time=tmp;
		}else if(tmpTime==tt)
		{
			//if(ss<tmpPath)
			if(tmp.size()<out_time.size())
			{
				tmpPath=ss;
				out_time.clear();
				out_time=tmp;
			}
		}
	   return ;
	}
	for(int i=0;i<citys;i++)
	{
			if(v[s][i]==0)
			{
					v[s][i]=1;
					v[i][s]=1;
					tmp.push_back(i);
					getShort(i,d,ss+_map[s][i].len,tt+_map[s][i].time);
					tmp.pop_back();
					v[s][i]=0;
					v[i][s]=0;
			}
	}
}

int max_path=0;
int max_time=0;


void dijstra(int s,int d,Map(*a)[510])
{
	
	cout<<a[0][0].len<<endl;
	for(int i=0;i<510;i++)
	{
		//找到当前最小
		int min=-1;
		for(int j=0;j<510;j++)
		{
			if(v[i][j]==0)
			{
				if(min==-1)
				  min=j;
				if(a[i][j].len<a[i][min].len)
				  min=j;
			}
		}
		v[i][min]=1;
	}

}



int main()
{


	out_time.assign(510,0);
	for(int i=0;i<510;i++)
	  for(int j=0;j<510;j++)
		  v[i][j]=-1;
	int streets,v1,v2,one_way,length,time,s,d;
	cin>>citys>>streets;
	for(int i=0;i<streets;i++)
	{
		cin>>v1>>v2>>one_way>>length>>time;


		max_path+=length;
		max_time+=time;

		_map[v1][v2].len=length;
		_map[v1][v2].time=time;
		v[v1][v2]=0;
		if(one_way==0)
		{
			_map[v2][v1].len=length;
			_map[v2][v1].time=time;
			v[v2][v1]=0;
		}
	}
	cin>>s>>d;
	_max=tmpPath=max_path+10;
	_max_time=tmpTime=max_time+10;

	tmp.push_back(s);
	getShort(s,d);
	tmp.clear();

	
	int shortPath=_max;
	int shortTime=tmpTime;

	int isSame=true;
	if(out.size()==out_time.size())
	{
		for(int a:out)
		{
			for(int b:out_time)
			{
				if(a!=b)
				{
				  isSame==false;
				  break;
				}
			}
		}
	}else
	  isSame=false;
	if(isSame==true)
	{
		cout<<"Distance = "<<shortPath<<"; Time = "
			<<shortTime<<": "<<out[0];
		for(int i=1;i<out.size();i++)
		{
			cout<<" -> "<<out[i];
		}
		cout<<endl;
	}else
	{
		cout<<"Distance = "<<shortPath<<": "<<out[0];
		for(int i=1;i<out.size();i++)
		{
			cout<<" -> "<<out[i];
		}
		cout<<endl;
		cout<<"Time = "<<shortTime<<": "<<out_time[0];
		for(int i=1;i<out_time.size();i++)
		{
			cout<<" -> "<<out_time[i];
		}
		cout<<endl;
	}
	
	
	return 0;
}
