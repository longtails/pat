#include<iostream>
#include<cstdio>
using namespace std;
double in[3][3];
int tag[3];
int main()
{
	double a=1;
	int b;
	double tmp=0;
	for(int i=0;i<3;i++)
	{
		tmp=0;//千万记得恢复初值，或者干脆在循环内 double tmp=0;
		//被没有恢复初值给干死了
	    //cin>>in[i][0];
		//	tmp=in[i][0];
		//	tag[i]=0;
		//for(int j=1;j<3;j++)
		for(int j=0;j<3;j++)
		{
		  cin>>in[i][j];
		  if(tmp<in[i][j])
		  {
			  cout<<"tmp"<<tmp<<" ";
			tmp=in[i][j];
			tag[i]=j;
		  }
		}
		cout<<endl;
		a*=tmp;
	}
	for(int i=0;i<3;i++)
	{
		switch(tag[i])
		{
			case 0:
				cout<<"W ";
				break;
			case 1:
				cout<<"T ";
				break;
			default:
				cout<<"L ";
				break;
		}
	}
	//虽然说正经该是37.98但37.97正确
	//以后如果要求四舍五入+0.005即可
	printf("%.2f\n",(a*0.65-1)*2);
	//cout.precision(2);
	//cout.setf(ios::fixed);
	//cout<<(a*0.65-1)*2+0.005<<endl;
	return 0;
}
