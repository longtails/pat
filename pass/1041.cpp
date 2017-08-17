#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> people;
vector<int> seq;
int main()
{
	freopen("in","r",stdin);
	int N,tmp;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		if(people[tmp]==0)
		  seq.push_back(tmp);
		people[tmp]++;
	}
	int i=0;
	int size=seq.size();
	for(i=0;i<size;i++)
	{
		if(people[seq[i]]==1)
		{
		  cout<<seq[i]<<endl;
		  break;
		}
	}
	if(i==size)
	  cout<<"None"<<endl;
	return 0;
}
