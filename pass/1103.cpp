#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> data;
vector<int> data2;
vector<int> ppow;
int stop;
int k;
vector<int>finalFactors;
int finalSum=0;
bool dfs(int N,int cur,vector<int>&factors)
{
	cout<<cur<<k<<endl;
	if(cur==k)
	{
		if(N==0)
		{
			int sum=0;
			for(int i=0;i<factors.size();i++)
			{
				sum+=factors[i];
			}
			if(sum>finalSum)
			{
				//finalFactors=factors;
				data2=factors;
				finalSum=sum;
			}
			return true;
		}
		return false;
	}
	int low=cur>0?factors[cur-1]:1;
	for(int i=low;i<stop;i++)
	{
		cout<<i<<endl;
		dfs(N-ppow[i],cur+1,factors);
	}
	return true;
}
bool cal(int a,int b,int c,int d=1)
{
	if(b==0&&a==0)
	{
		if(data[0]>data2[0])
		{
			data2=data;
			data2.clear();
			for(int da:data)
			  data2.push_back(da);
		}
	  return true;
	}
	if(b==0||a<0)
	  return false;
	int j=0;
	for(int i=d;i<=stop;i++)
	{
		j=ppow[i];
		data[b]=i;
		data[0]+=i;
		cal(a-j,b-1,c,i);
		data[0]-=i;
	}
	return true;
}
bool bigger(int a,int b)
{
	return a>b;
}
int main()
{
	int a,c;
	cin>>a>>k>>c;
	stop=1;
	ppow.push_back(0);
	int p=0;
	do
	{
		p=pow(stop++,c);
		ppow.push_back(p);
	}while(p<=a);
	stop--;

	data.assign(k+1,0);
//	if(cal(a,k,c)==true)
	if(dfs(a,0,data)==true)
	{

		//sort(data2.begin()+1,data2.begin()+data2.size(),bigger);
		cout<<a<<" = "<<data2[1]<<"^"<<c;
		for(int i=1;i<data2.size();i++)
		  cout<<" + "<<data2[i]<<"^"<<c;
		cout<<endl;
	}
	else
	  cout<<"Impossible"<<endl;
	return 0;
}
