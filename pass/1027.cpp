#include<iostream>
using namespace std;
void output(int a)
{
	char d[5];
	int s=0;
	while(a!=0)
	{
		switch(a%13)
		{
			case 10:
				d[s++]='A';
				break;
			case 11:
				d[s++]='B';
				break;
			case 12:
				d[s++]='C';
				break;
			default:
				d[s++]=a%13+'0';
		}
		a/=13;
	}
	if(s==0)
	{
		d[s++]='0';
		d[s++]='0';
	}else if(s==1)
		d[s++]='0';
	cout<<d[s-1]<<d[s-2];
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"#";
	output(a);
	output(b);
	output(c);
	cout<<endl;
	return 0;
}
