#include<iostream>
#include<vector>

int P[510][510];//路径
int RP[510];//前驱
int preP[510];
int T[510][510];//路径
int RT[510];//前驱
int preT[510];
int v[510];//访问标志

using namespace std;

vector<int> out_path;
void dfs(int s,int d)
{
	out_path.push_back(d);
	if(s==d)
	  return;
	dfs(s,preP[d]);
}
vector<int> out_time;
void dfs_time(int s,int d)
{
	out_time.push_back(d);
	if(s==d)
	  return;
	dfs_time(s,preT[d]);
}
int main()
{
	int max_path=0;
	int max_time=0;
	int shortPath=0;
	int shortTime=0;
	for(int i=0;i<510;i++)
	  for(int j=0;j<510;j++)
	  {
		  preP[i]=i;
		  preT[i]=i;
		  P[i][j]=-1;
		  T[i][j]=-1;
		  v[i]=0;
	  }
	int streets,citys,v1,v2,one_way,length,time,s,d;
	cin>>citys>>streets;
	for(int i=0;i<streets;i++)
	{
		cin>>v1>>v2>>one_way>>length>>time;
		//INF
		max_path+=length;
		max_time+=time;

		P[v1][v2]=length;
	    T[v1][v2]=time;
		if(one_way==0)
		{
			P[v2][v1]=length;
			T[v2][v1]=time;
		}
	}

		
	cin>>s>>d;

	//初始化设置
	for(int i=0;i<citys;i++)
	{
		RP[i]=max_path;
		RT[i]=max_time;
	}
	RT[s]=0;
	RP[s]=0;

	v[d]=1;
	//digstra
	while(true)
	{
		int min=-1;
		int tmp=max_path;
		//选择最小
		for(int i=0;i<citys;i++)
		{
			if(v[i]==0)
			{
				if(tmp>RP[i])
				{
					tmp=RP[i];
					min=i;
				}else if(tmp==RP[i])
				{
					if(RT[min]>RT[i])
					{
						min=i;
					}
				}
			}
		}

		cout<<min<<endl;
		if(min==-1)
		  break;
		for(int i=0;i<citys;i++)
		{
			if(v[i]==0&&P[min][i]!=-1)
			{
				if(P[min][i]+RP[min]<RP[i])
				{
					RP[i]=P[min][i]+RP[min];
					RT[i]=T[min][i]+RT[min];
					preP[i]=min;
				}
				else if(P[min][i]+RP[min]==RP[i]&&RT[min]+T[min][i]<RT[i])
				{
					RT[i]=T[min][i]+RT[min];
					preP[i]=min;
				}

			}
		}
		v[min]=1;
		cout<<min<<endl;
	}
	int min=preP[d];
	cout<<preP[d]<<"aldjfal"<<endl;
	for(int i=0;i<citys;i++)
	{
		if(P[i][d]!=-1)
		{
			cout<<P[i][d]<<" "<<RP[i]<<" "<<RP[d]<<endl;
			cout<<T[i][d]<<" "<<RT[i]<<" "<<RT[d]<<endl;
			if(P[i][d]+RP[i]<RP[d])
			{
				RP[d]=P[i][d]+RP[i];
				RT[d]=T[i][d]+RT[i];
				min=i;
				cout<<"haha"<<endl;
			}
			else if(P[i][d]+RP[i]==RP[d]&&RT[i]+T[i][d]<RT[d])
			{
				RT[d]=T[i][d]+RT[i];
				min=i;
			}
		}
	}
	cout<<"min"<<min<<endl;
	preP[d]=min;

	shortPath=RP[d];

	dfs(s,d);

	//初始化设置
	for(int i=0;i<citys;i++)
	{
		RP[i]=max_path;
		RT[i]=max_time;
		v[i]=0;
	}
	RT[s]=0;
	RP[s]=0;

	v[d]=1;

	//time
	while(true)
	{
		int min=-1;
		int tmp=max_time;
		//选择最小
		for(int i=0;i<citys;i++)
		{
			if(v[i]==0)
			{
				if(tmp>RT[i])
				{
					tmp=RT[i];
					min=i;
				}else if(tmp==RT[i])
				{
					if(RT[min]>RT[i])
					{
						min=i;
					}
				}
			}
		}
		if(min==-1)
		  break;
		for(int i=0;i<citys;i++)
		{
			if(v[i]==0&&T[min][i]!=-1)
			{
				if(T[min][i]+RT[min]<RT[i])
				{
					RT[i]=T[min][i]+RT[min];
					RP[i]=RT[min]+1;
					preT[i]=min;
				}
				else if(T[min][i]+RT[min]==RT[i]&&RP[min]+1<RP[i])
				{
					RP[i]=1+RT[min];
					preT[i]=min;
				}
			}
		}
		v[min]=1;
	}

	min=preT[d];
	for(int i=0;i<citys;i++)
	{
		if(T[i][d]!=-1)
		{
			if(T[i][d]+RT[i]<RT[d])
			{
				RP[d]=1+RP[i];
				RT[d]=T[i][d]+RT[i];
				min=i;
			}
			else if(T[i][d]+RT[i]==RT[d]&&RP[i]+1<RP[d])
			{
				RP[d]=1+RP[i];
				min=i;
			}
		}
	}

	preT[d]=min;
	
	shortTime=RT[d];
	
	

	dfs_time(s,d);

	vector<int>outpath;
	for(int i=out_path.size()-1;i>=0;i--)
	{
		outpath.push_back(out_path[i]);
	}
	out_path.clear();
	vector<int>outtime;
	for(int i=out_time.size()-1;i>=0;i--)
	{
		outtime.push_back(out_time[i]);
	}
	out_time.clear();

	int isSame=true;
	if(outpath.size()==outtime.size())
	{
		for(int a:outpath)
		{
			for(int b:outtime)
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
			<<shortTime<<": "<<outpath[0];
		for(int i=1;i<outpath.size();i++)
		{
			cout<<" -> "<<outpath[i];
		}
		cout<<endl;
	}else
	{
		cout<<"Distance = "<<shortPath<<": "<<outpath[0];
		for(int i=1;i<outpath.size();i++)
		{
			cout<<" -> "<<outpath[i];
		}
		cout<<endl;
		cout<<"Time = "<<shortTime<<": "<<outtime[0];
		for(int i=1;i<outtime.size();i++)
		{
			cout<<" -> "<<outtime[i];
		}
		cout<<endl;
	}
	
	
	outtime.clear();
	outpath.clear();
	return 0;
}
