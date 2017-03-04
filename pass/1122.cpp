#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >d;
vector<int> v;
vector<int> out;
int N;
int M;
int K;
int main()
{
	cin>>N>>M;
	v.assign(N,0);
	d.assign(N,v);
	int tmp_a=0;
	int tmp_b=0;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_a>>tmp_b;
		tmp_a--;
		tmp_b--;
		d[tmp_a][tmp_b]=1;
		d[tmp_b][tmp_a]=1;
	}
	cin>>K;
	int tmp_c;
	int tmp_d;
	int count=0;
	bool yn=true;
	for(int i=0;i<K;i++)
	{
//		cout<<"------------"<<i<<endl;
		cin>>tmp_d;
		count=tmp_d;
		tmp_a=-1;
		tmp_b=-1;
		for(int j=0;j<tmp_d;j++)
		{
			count--;
			if(j==0)
			{
			    cin>>tmp_a;
				tmp_a--;
				tmp_b=tmp_a;
				v[tmp_a]=1;
				continue;
			}
			else
			{
				cin>>tmp_c;
				tmp_c--;
				if(d[tmp_b][tmp_c]==1)
				{
					if(v[tmp_c]==1)
					{
						//只有最后一个节点跟第一个节点一样才对
						if(tmp_c!=tmp_a)
						  yn=false;
						//中间节点又访问第一个节点了，错
						else if(count!=0)
						  yn=false;
					}else
						v[tmp_c]=1;
				}else
				  yn=false;
				tmp_b=tmp_c;
			}
		}
		for(int i=0;i<N;i++)
		{
			if(v[i]==0)
			  yn=false;
		   v[i]=0;
		}
		if(tmp_d!=N+1)
		  yn=false;

		if(yn==false)
		  out.push_back(0);
		else
		  out.push_back(1);
		yn=true;
	}
	for(int i=0;i<out.size();i++)
	{
		if(out.at(i)==0)
		  cout<<"NO"<<endl;
		else
		  cout<<"YES"<<endl;
	}
	return 0;
}
