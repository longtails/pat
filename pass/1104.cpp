#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	vector<double>s;
	s.push_back(0);
	double tmp=0;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		s.push_back(tmp);
	}
	unsigned int size=s.size();
	for(unsigned int i=1;i<size;i++)
	{
		s[0]+=s[i]*i*(size-i);
	}
	return s[0];

	printf("%.2f\n",s[0]);
	//需要记住c++的确定点的功能
	return 0;
}
