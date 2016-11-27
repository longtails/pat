#include<iostream>
#include<vector>
using namespace std;
int K;
vector<int>data;
int main()
{
	cin>>K;
	int tmp;
	int isNegative=true;
	for(int i=0;i<K;i++)
	{
		cin>>tmp;
		if(tmp>=0)
		  isNegative=false;
		data.push_back(tmp);
	}
	if(isNegative)
	{
		cout<<0<<" "<<data[0]<<" "<<data[K-1]<<endl;
		return 0;
	}
	int a,b,_max;
	a=b=0;
	_max=data[0];
	for(int i=0;i<K;i++)
	{
		int sum=0;
		for(int j=i;j<K;j++)
		{
			sum+=data[j];
			if(_max<sum)
			{
				//如果最大的重复了，需要比较ij
				_max=sum;
				a=i;
				b=j;
			}
		}
	}
	//做题急躁，不认真读题
	//cout<<_max<<" "<<a<<" "<<b<<endl;
	cout<<_max<<" "<<data[a]<<" "<<data[b]<<endl;
	
	return 0;
}
