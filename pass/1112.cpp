#include<iostream>
#include<string>
#include<map>
using namespace std;
//出现的字母如果全部是连续三次，则卡住了
//否则不能判断
int main()
{
	map<char,int>r;
	int n;
	cin>>n;
	string tmp;
	cin>>tmp;
	for(int i=0;i<tmp.length();i++)
	{
		if(r.find(tmp.at(i))==r.end())
			r[tmp.at(i)]=0;
	}
	for(int i=0;i<tmp.length();i++)
	{
		int count=0;
		char c=tmp.at(i);
		if(r[c]==-1)
		  continue;
		for(int j=i;j<tmp.length();j++)
		{
			if(c==tmp.at(j))
			  count++;
			else
			  break;
		}
		if(count%n==0)
		{
		  r[c]=1;
		  i+=(count-1);
		}
		else
		{
		  r[c]=-1;
		}

	}
	string o1;
	string o2;
	for(int i=0;i<tmp.length();i++)
	{
		char c=tmp.at(i);
		if(r.at(c)==1)
		{
			if(o1.find(c)==string::npos)
				o1+=c;
			i+=(n-1);
		}
		o2+=c;
	}
	cout<<o1<<endl
		<<o2<<endl;
	return 0;
}
