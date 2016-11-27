#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> id;
vector<int> c;
vector<int> m;
vector<int> e;
vector<int> a;
vector<int> query;

int get(vector<int>&a,int id)
{
	int my=a[id];
	int rank=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>my)
		  rank++;
	}
	return rank;
}
int main()
{
	int M,N;
	cin>>M>>N;
	int tmp,tmp1,tmp2,tmp3;
	for(int i=0;i<M;i++)
	{
		cin>>tmp>>tmp1>>tmp2>>tmp3;
		id.push_back(tmp);
		c.push_back(tmp1);
		m.push_back(tmp2);
		e.push_back(tmp3);
		a.push_back((tmp1+tmp2+tmp3)/3);
	}
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
	    query.push_back(tmp);
	}
	for(int i=0;i<N;i++)
	{
		tmp=query[i];
		int myid=-1;
		for(int i=0;i<M;i++)
		{
			if(tmp==id[i])
			{
				myid=i;
				break;
			}
		}
		if(myid==-1)
		{
		  cout<<"N/A"<<endl;
		  continue;
		}
		tmp=get(a,myid);
		tmp1=get(c,myid);
		int which=0;
		if(tmp1<tmp)
		{
		  tmp=tmp1;
		  which=1;
		}
		tmp2=get(m,myid);
		if(tmp2<tmp)
		{
		  tmp=tmp2;
		  which=2;
		}
		tmp3=get(e,myid);
		if(tmp3<tmp)
		{
		  tmp=tmp3;
		  which=3;
		}
		cout<<tmp<<" ";
		switch(which)
		{
			case 0:cout<<"A"<<endl;
				   break;
			case 1:cout<<"C"<<endl;
				   break;
			case 2:cout<<"M"<<endl;
				   break;
			default:
				   cout<<"E"<<endl;
				   break;
		}
	}


	return 0;
}
