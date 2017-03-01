#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> in;
int count[10];
char c_in[25];
int N=0;
int main()
{
	for(int i=0;i<10;i++)
	  count[i]=0;
	memset(c_in,0,25);
	in.push_back(0);
	scanf("%s",c_in);
	N=strlen(c_in);
	for(int i=0;i<N;i++)
	{
		in.push_back(c_in[i]-'0');
		++count[in.at(i+1)];
	}
	//带进位加
	int tmp=0;
	for(int i=in.size()-1;i>0;i--)
	{
		tmp=(in.at(i)*2+tmp);
		in.at(i)=tmp%10;
		tmp=tmp/10;
		if(count[in.at(i)]>0)
			count[in.at(i)]--;
	}
	//如果最高位进一了，则一定是No
	//最高位没有进位，查看其他是否正常
	int tmpi=0;
	if(tmp==0)
	{
		tmpi=1;
		for(int i=1;i<10;i++)
		{
			if(count[i]>0)
			{
			  count[0]=1;
			  break;
			}
		}

	}
	else
	{
	  tmpi=0;
	  in.at(0)=tmp;
	}
	if(tmp==1||count[0]!=0)
	  cout<<"No"<<endl;
	else
	  cout<<"Yes"<<endl;
	for(int i=tmpi;i<in.size();i++)
	{
		cout<<in.at(i);
	}
	cout<<endl;
	return 0;
}
