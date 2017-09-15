#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=100000;
int prime[MAX];
int main()
{
  //筛选法求质数表
  //
  fill_n(prime,MAX,1);
  for(int i=2;i*i<MAX;i++)
    for(int j=2;i*j<MAX;j++)
      prime[i*j]=0;
  long int n;
  scanf("%ld",&n);
  printf("%ld=",n);
  if(n==1)printf("1");
  int cnt=0;
  int b=0;
  for(int i=2;i<=n;i++)
  {
    if(prime[i]==0)continue;
    cnt=0;
    //计算N有几i的乘积
    while(n%i==0)
    {
      cnt++;
      n/=i;
    }
    //一个也没有则，说明这个数不在N的因子中
    if(cnt==0)continue;

    //除第一次外
    if(b==0)b=1;
    else printf("*");

    printf("%d",i);

    //输出i的质数
    if(cnt>1)printf("^%d",cnt);
  }
  printf("\n");
  return 0;
}
