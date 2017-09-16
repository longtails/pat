#include<iostream>
#include<cstdio>
#include<cstdio>
#include<stack>
using namespace std;
//树状数组
int lowbit(int x){
  return x&(-x);
}
/*
 //这里不用这个
void calStage(int *sum,int n)
{
  int par=0;
  for(int i=1;i+lowbit(i)<=n;i++)
  {
    par=i+lowbit(i);//后继，更新d00..非终端结点
    sum[par]+=sum[i];
  }
}
*/
void update(int *sum,int n,int k,int v)
{
  int par=k;
  while(par<=n)
  {
    sum[par]+=v;
    par+=lowbit(par);
  }
}
int gs(int *sum,int n)
{
  int s=0;
  while(n>0)
  {
    s+=sum[n];
    n=n-lowbit(n);//前驱，求和
  }
  return s;
}

int gRank(int *sum,int imax,int k)
{
  int l=1;int r=imax;
  int m=(l+r)/2;
  while(l<r)
  {
    m=(l+r)/2;
    if(gs(sum,m)>=k)r=m;
    else l=m+1;
  }
  return r;//返回l或者r都可以，但不可以返回m
  //退出二分是，m
}
const int MAX=100010;
int sum[MAX];
stack<int> stk;
int main()
{
  //fill_n(sum,MAX,0);//设置0，可以不写这句，把定义放到静态变量区即可
  freopen("in","r",stdin);
  int N,tmp;
  char op[20];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%s",op);
    switch(op[1])
    {
      case 'u'://push
        scanf("%d",&tmp);
        stk.push(tmp);
        update(sum,MAX,tmp,1);
  
        break;
      case 'o'://pop
        if(stk.size()<=0)
          printf("Invalid\n");
        else
        {
          update(sum,MAX,stk.top(),-1);
          printf("%d\n",stk.top());
          stk.pop();
        }
       break;
      default://'e'  peekMadian
        if(stk.size()<=0)
          printf("Invalid\n");
        else
          //偶数+1/2仍是原来的偶数/2
          printf("%d\n",gRank(sum,MAX,(stk.size()+1)/2));
    }
  }
	return 0;
}


