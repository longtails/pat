#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[90];
	cin>>s;
	int size=strlen(s);
	int n1,n2,n3,tmp;
	n1=0;
	for(int i=3;i<size;i++)
	{
		tmp=(size+2-i)/2;
		if(tmp<=i)
		{
			if(tmp>n1)
			{
				n1=tmp;
				n2=size+2-n1*2;
			}
		}
	}
	for(int i=0;i<n1;i++)
	{
		cout<<s[i];
		for(int j=1;j<n2-1;j++)
		{
			if(i==n1-1)
				cout<<s[i+j];
			else
			  cout<<" ";
		}
		cout<<s[size-1-i];
		cout<<endl;
	}

	return 0;
}
