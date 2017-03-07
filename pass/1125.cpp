#include<iostream>
#include<vector>
#include<algorithm>
bool comp(int a,int b)
{
	if(a<b)
	  return true;
	else
	  return false;
}
using namespace std;
vector<int>d;
int N;
int main()
{
	cin>>N;
	int tmp_a;
	for(int i=0;i<N;i++)
	{
		cin>>tmp_a;
		d.push_back(tmp_a);
	}
	sort(d.begin(),d.end(),comp);
	int max=0;
	for(int i=1;i<N;i++)
	{
		d[i]+=d[i-1];
		d[i]/=2;
		if(d[i]>max)
		  max=d[i];
	}
	cout<<max<<endl;
	
	return 0;
}
