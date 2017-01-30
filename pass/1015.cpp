#include <iostream>
#include<cmath>
using namespace std;
/*
 * reversible num base on radix d
 * test the two num which radix is 10  is prime*/
long reverse(long a,int b)
{
	long c=0;
	long out=0;
	long count=0;
	do
	{
		count++;
		c*=10;
		c+=a%b;
		a/=b;
	}while(a>=1);
	long tmp=0;
	for(long i=0;i<count;i++)
	{
		tmp=c%10;
		c/=10;
		out+=pow(b,i)*tmp;
	}
	return out;
}
long  getreverse(long n,int radix)  
{  
  long num=n%radix;   
  while((n/radix)!=0)  
  {  
     n/=radix;                 
     num = num*radix + n%radix;                
  }  
    
  return num;  
} 
bool isPrime(int a)  
{  
    int i;  
    if(a==0 || a==1) return false;  
  
    //注意是i<=sqrt(),之前弄成i<sqrt,一直出错  
    for(i=2; i <= sqrt((double)a); i++){  
        if( a%i == 0) return false;  
    }  
  
    return true;  
}  
bool is_Prime(int a)
{
	if(a==1)
	  return false;
	if(a==2)
	  return true;
	for(int i=2;i<a/2+1;i++)
	{
		if(a%i==0)
		  return false;
	}
	return true;
}
bool isPrime(int a,int b)
{
	/*
	cout<<"a:"<<reverse(a,b)<<endl;
	cout<<"b:"<<getreverse(a,b)<<endl;
	*/
	if(isPrime(a)==false)
	  return false;
	else
	  return isPrime(reverse(a,b));
}
int main()
{
	int data=10;
	int radix=10;
	while(true)
	{
		cin>>data;
		if(data<0)
		  return 0;
		cin>>radix;
		if(isPrime(data,radix)==false)
		  cout<<"No"<<endl;
		else
		  cout<<"Yes"<<endl;
	}
	return 0;
}
