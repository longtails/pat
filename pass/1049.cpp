#include<iostream>
#include<cstdio>
#include<cmath>
int digits[20];
using namespace std;
int main()
{
	unsigned int N;
	cin>>N;
	fill_n(digits,20,1);
	int i=1;
	int sum=0;
	int pre=0;//N的i-1~0位的数
	int d=0;//记录(0,10) (0,100) (0,1000) ...下的完整１的个数
	while(N)
	{
		digits[i]=N%10+1;
		//sum中便记录着非整i位的1计数
		//i-1位
		//digits[i]-1个完整的i-1位1
		//1.sum本身记录着前i-1位1的个数，如149，当前sum中记录着49中的1的个数
		//2.digits[i]-1个完整i-1位1的个数，如249，含有3*20个1, (0~99)中含20个1
		sum+=(digits[i]-1)*d;

		//第i位 249 中1xx有i位1的计数为1+99个
		if(digits[i]>2)//1xxx　xxx个i位1
			sum+=pow(10,i-1);
		//149,则仅有第三位1的个数为1+49个
		if(digits[i]==2)//1pre pre个i位的1
			sum+=(pre+1);

		pre=pre+(digits[i]-1)*pow(10,i-1);//N的i位构成的数字
		d=10*d+pow(10,i-1);//记录(0,9) (0,99) (0,999) ...1的个数
		N/=10;
		i++;
	}
	cout<<sum<<endl;
	return 0;
}
