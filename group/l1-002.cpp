#include<iostream>
#include<vector>
using namespace std;
//a:剩余 b当前长度c深度
vector<int> out;
//a位置*，b总大小结束位置--dont care
void output(int max,int b,char c)
{
	for(int i=0;i<max-b;i++)
	{
		if(i<b)
			cout<<" ";
		else
		  cout<<c;
	}
	cout<<endl;
	if(max-2*(b+1)<=0)
	  return;
	output(max,b+1,c);
	for(int i=0;i<max-b;i++)
	{
		if(i<b)
			cout<<" ";
		else
		  cout<<c;
	}
	cout<<endl;
	
}

int main()
{
	int N;
	char c;
	cin>>N>>c;
	int a=N;
	int cur=1;
	a--;
	while(a>=2*(cur+2))
	{
		cur+=2;
		a-=2*cur;
	}
	output(cur,0,c);
	cout<<a<<endl;
	return 0;
}
