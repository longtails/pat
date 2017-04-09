#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<string>id;
vector<string>pw;
int N;
string check(string a)
{
	string tmp=a;
	for(int i=0;i<a.size();i++)
	{
		switch(a.at(i))
		{
			case '1':
				tmp.at(i)='@';
				break;
			case '0':
				tmp.at(i)='%';
				break;
			case 'l':
				tmp.at(i)='L';
				break;
			case 'O':
				tmp.at(i)='o';
				break;
			default:
				break;
		}
	}
	return tmp;
}
int main()
{
	freopen("in","r",stdin);
	cin>>N;
	string a,b;
	string tmp;
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		tmp=check(b);
		if(tmp!=b)
		{
			id.push_back(a);
			pw.push_back(tmp);
		}
	}
	
	if(id.size()>0)
	  cout<<id.size()<<endl;
	else
	{
		if(N==1)
			cout<<"There is "<<N<<" account and no account is modified"<<endl;
		else
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		return 0;
	}
	for(int i=0;i<id.size();i++)
	{
		cout<<id.at(i)<<" "<<pw.at(i)<<endl;
	}

	return 0;
}
