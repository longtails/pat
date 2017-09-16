#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//计算数据宽度,ma为小数点位置，mb为第一个非零数的位置
int width(char*c,int n,int &ma,int &mb)
{
  //deal with 0.000123
  int a=n;
  int b=-1;
  for(int i=0;i<n;i++)
  {
    if(a!=n&&b>=0)
      break;
    if(a==n&&c[i]=='.')//小数点位置
      a=i;
    else if(b==-1&&c[i]!='0')//第一个非零位置
      b=i;
  }
  ma=a; mb=b;
  //未发现非零数字，那么数据的宽度是0
  if(b==-1)
  {
    mb=0;
    return 0;
  }
  if(a>b)
    return a-b;
  else
    return a-b+1;
}
int main()
{
//  freopen("in","r",stdin);
  int n;
  const int MAX=2000;
  char c[MAX];
  char a[MAX];
  char b[MAX];
  fill_n(a,MAX,'0');
  fill_n(b,MAX,'0');
  scanf("%d %s",&n,c);
  int aa,ab,ba,bb;
  int ma=width(c,strlen(c),aa,ab);
  int i=ab;
  int j=0;
  //将从第一个非零数字开始复制数字到a中，方便格式化数据输出
  for(;i<strlen(c);i++,j++)
  {
    if(c[i]=='.')
    {
      j--;
      continue;
    }
    a[j]=c[i];
  }
  //  a[j]='\0';//查看a中数据用
  scanf("%s",c);
  int mb=width(c,strlen(c),ba,bb);
  //将从第一个非零数字开始复制数字到b中，方便格式化数据输出
  for(i=bb,j=0;i<strlen(c);i++,j++)
  {
    if(c[i]=='.')
    {
      j--;
      continue;
    }
    b[j]=c[i];
  }
  // b[j]='\0';


  int flag=1;
  //比较两个科学计数法表示的数据,比较数据宽度，宽度相等时比较底数是否一致
  //N够大
  if(ma!=mb)
    flag=0;
  else
    for(int i=0;i<n;i++)
    {
      if(a[i]!=b[i])
      {
        flag=0;
        break;
      }
    }

  if(flag==1)
    printf("YES");
  else
    printf("NO");
  //注意底数宽度不及精度时要进行补0
  printf(" 0.");
  for(int i=0;i<n;i++)
  {
      printf("%c",a[i]);
  }
  printf("*10^%d",ma);

  if(flag==0)
  {
      printf(" 0.");
      for(int i=0;i<n;i++)
          printf("%c",b[i]);
      printf("*10^%d",mb);
  }
  printf("\n");
  return 0;
}
