#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>d;
	int m;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		d.push_back(m);
	}
	sort(d.begin(),d.begin()+n);
	if(n%2)
	  cout<<1;
	else
	  cout<<0;
	cout<<" ";
	int sum=0;
	int half=n/2;
	for(int i=n-1;i>=0;i--)
	{
		if(i>=half)
		  sum+=d.at(i);
		else
		  sum-=d.at(i);
	}
	cout<<sum<<endl;
	return 0;
}

