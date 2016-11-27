#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

long long eq10(string a,long long base)
{
  long long a10=0;
  for(long long i=0;i<a.length();i++)
  {
    if(a[i]>='0'&&a[i]<='9')
      a10+=pow(base,a.length()-i-1)*(a[i]-'0');
    else
      a10+=pow(base,a.length()-i-1)*(a[i]-'a'+10);
  }
  return a10;
}

int comp1(long long a,string b,long long base)
{
  long long a10=0;
  for(long long i=0;i<b.length();i++)
  {
    if(b[i]>='0'&&b[i]<='9')
      a10+=pow(base,b.length()-i-1)*(b[i]-'0');
    else
      a10+=pow(base,b.length()-i-1)*(b[i]-'a'+10);
    if(a10>a)
      return 1;
  }
  if(a10<a)
    return -1;
  else
    return 0;
 }

int comp2(long long a,string b,long long base)
{
  long long a10=0;
  for(long long i=b.length()-1;i>=0;i--)
  {
    if(b[i]>='0'&&b[i]<='9')
      a10+=pow(base,b.length()-i-1)*(b[i]-'0');
    else
      a10+=pow(base,b.length()-i-1)*(b[i]-'a'+10);
    if(a10>a)
      return 1;
  }
  if(a10>a)
	return 1;
  if(a10<a)
    return -1;
  else
    return 0;
 }
 
long long isSame(string a,string b,long long base)
{
  //判断b的最低进制
  long long max=0;
  long long num=0;
  for(long long i=0;i<b.length();i++)
  {
    if(b[i]>='0'&&b[i]<='9')
    {
      num=(b[i]-'0');
    }else
    {
      num=(b[i]-'a'+10);
    }
    if(max<num)
      max=num;
  }

  long long a10=eq10(a,base);
  long long b10=0;
  
  //确定范围
  long long _max=a10+1;
  long long _min=max+1;
  if(a10<max)
  {
    _max=max+1;
    _min=a10+1;
  }


  long long m=_min;
  int cc=0;
  while(_min<=_max)
  {
    cc=comp1(a10,b,m);
    //cc=comp2(a10,b,m);
    if(cc==1)
    {
      _max=m-1;
    }else if(cc==-1)
    {
      _min=m+1;
    }else if(cc==0)
      return m;
    m=(_min+_max)/2;
  }
  return -1;
}
  
 
int main()
{
  string a,b;
  long long c,d;
  cin>>a>>b>>c>>d;
  long long out=-1;

  if(c==2)
  {
	  string tmp=a;
	  a=b;
	  b=tmp;
  }
  if(a==b)
	out=d;
  else
	  out=isSame(a,b,d);
  if(out==-1)
    cout<<"Impossible"<<endl;
  else
    cout<<out<<endl;
  return 0;
}
