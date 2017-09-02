#include<iostream>
#include<cstdio>

using namespace std;
int s[500];
int main()
{
	freopen("in","r",stdin);
	string s1,s2;
	fill_n(s,0,500);
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++)
		s[int(s2[i])]=1;
	for(int i=0;i<s1.length();i++)
	{
		if(s[int(s1[i])]==0)
		  cout<<s1[i];
	}
	cout<<endl;

	return 0;
}
