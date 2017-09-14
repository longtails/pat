/*************************************************************************
    > File Name: 1058.cpp
    > Author: liu
    > Mail: scylhy@163.com 
    > Created Time: 2017年09月14日 星期四 15时50分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,
							  &d,&e,&f);
	int s3=(c+f)%29;
	int s2=b+e+(c+f)/29;
	int s1=a+d+s2/17;
	s2%=17;
	printf("%d.%d.%d\n",s1,s2,s3);
	return 0;
}
