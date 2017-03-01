#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct _P
{
	string n;
	int score;
	int local;

	int local_rank;
	int all_rank;
};
bool comp(_P a,_P b)
{
	if(a.score>b.score)
	  return true;
	else if(a.score==b.score)
	{
		if(a.n<b.n)
		  return true;
	}
	return false;
}
int N=0;
int K=0;
vector<_P>all;
vector<_P>loc;
int main()
{
	_P tmp;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>K;
		for(int  j=0;j<K;j++)
		{
			cin>>tmp.n
				>>tmp.score;
			tmp.local=i+1;
			loc.push_back(tmp);
		}
		sort(loc.begin(),loc.end(),comp);
		for(int j=0;j<K;j++)
		{
			if(j>0&&loc.at(j).score==loc.at(j-1).score)
			{
				loc.at(j).local_rank=
				loc.at(j-1).local_rank;
			}else
				loc.at(j).local_rank=j+1;
		}
		for(int j=0;j<K;j++)
		{
			all.push_back(loc.at(j));
		}
		loc.clear();
	}


	sort(all.begin(),all.end(),comp);
	for(int j=0;j<all.size();j++)
	{
		if(j>0&&all.at(j).score==all.at(j-1).score)
		{
			all.at(j).all_rank=
			all.at(j-1).all_rank;
		}else
			all.at(j).all_rank=j+1;
	}
	cout<<all.size()<<endl;
	for(int i=0;i<all.size();i++)
	{
		cout<<all.at(i).n<<" "<<all.at(i).all_rank<<" "<<all.at(i).local<<" "
			<<all.at(i).local_rank<<endl;
	}


	
	return 0;
}
