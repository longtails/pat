#include<iostream>
#include<cstdio>
using namespace std;
int longestStr(string &str,int i,int j,int size)
{
	while(i>=0&&j<size&&str[i]==str[j])
	{
		i--;
		j++;
	}
	return j-i+1-2;
}
int main()
{
	freopen("in","r",stdin);
	string str;
	getline(cin,str);
	int longest=0;
	int tmp=1;//这就有点坑，该字符串symmetric string length>=1
	int tmp1=1;//如　A:1 AB:1 AA:2 BAAAB:5
	int strSize=str.length();
	//定点-扩展
	for(int i=0;i<strSize;i++)
	{
		//must detect in same time,一开始if-else,造成AAA型丢失奇数对称的情况
		if(i+1<strSize&&str[i]==str[i+1])
			tmp1=longestStr(str,i,i+1,strSize);
		if(i+2<strSize&&str[i]==str[i+2])
			tmp=longestStr(str,i,i+2,strSize);
		tmp=tmp>tmp1?tmp:tmp1;
		longest=tmp>longest?tmp:longest;
	}
	cout<<longest<<endl;
	return 0;
}
