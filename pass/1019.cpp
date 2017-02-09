#include<iostream>
using namespace std;
#include<vector>
vector<int> num;
int N=0;
int b=2;
int main()
{
	cin>>N>>b;
	if(N==0)
		num.push_back(N);
	while(N>0)
	{
		num.push_back(N%b);
		N=N/b;
	}
	bool isP=true;
	for(int i=0;i<num.size()/2;i++)
	{
		if(num.at(i)!=num.at(num.size()-1-i))
		{
			isP=false;
			break;
		}
	}
	if(isP==true)
	  cout<<"Yes"<<endl;
	else
	  cout<<"No"<<endl;
	cout<<num.at(num.size()-1);
	for(int i=num.size()-2;i>=0;i--)
	{
		cout<<" "<<num.at(i);
	}
	cout<<endl;
	return 0;
}
