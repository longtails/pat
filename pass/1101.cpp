#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool big(int a,int b)
{
	return a>b;
}
int main()
{
	vector<int> d;
	vector<int> l;//填充最大值
	vector<int> r;//填充最小值
	d.push_back(0);
	l.push_back(0);
	r.push_back(0);
	int n=0;
	cin>>n;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		d.push_back(tmp);
		r.push_back(tmp);
		l.push_back(tmp);
		if(l[i-1]>tmp)
		  l[i]=l[i-1];
	}
	vector<int> o;
	for(int i=n;i>0;i--)
	{
		if(r[i-1]>r[i])
		  r[i-1]=r[i];
		if(l[i]<=r[i])
		  o.push_back(d[i]);
	}
	cout<<o.size()<<endl;
	sort(o.begin(),o.begin()+o.size(),big);
	for(int i=o.size()-1;i>=0;i--)
	{
	  cout<<o[i];
	  if(i==0)
		cout<<endl;
	  else
		cout<<" ";
	}
	if(o.size()==0)
	  cout<<endl;
	return 0;
}
