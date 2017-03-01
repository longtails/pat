#include<iostream>
#include<vector>
using namespace std;
vector<int>data;
long long N;
int K;
void add2()
{
	//倒着来
	int tmp=0;
	int tmp2=0;
	int size=data.size();
	vector<int> tmp_v;
	for(int i=0;i<size;i++)
	{
		tmp=data.at(i)+data.at(size-1-i)+tmp2;
		tmp_v.push_back(tmp%10);
		tmp2=tmp/10;
	}
	if(tmp2>0)
	{
	  tmp_v.push_back(tmp2);
	}
	data=tmp_v;
}
bool isPal()
{
	int size=data.size();
	for(int i=0;i<size/2;i++)
	{
		if(data.at(i)!=data.at(size-1-i))
		  return false;
	}
	return true;
}
int main()
{
	cin>>N>>K;
	long long tmp=N;
	while(tmp!=0)
	{
		data.push_back(tmp%10);
		tmp/=10;
	}
	int kk=0;

	for(int i=0;i<K;i++)
	{
		if(isPal()==true)
		{
			break;
		}else
		{
		  add2();
		  kk++;
		}
	}
	for(int i=data.size()-1;i>=0;i--)
	{
		cout<<data.at(i);
	}
	cout<<endl<<kk<<endl;

	return 0;
}
