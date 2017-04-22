#include<iostream>
#include<vector>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>coupon;
int v[100010];
vector<int>val;
int main()
{
	freopen("in","r",stdin);
	fill(v,v+10010,0);
	int N,M,tmp;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
	  scanf("%d",&tmp);
	  coupon.push_back(tmp);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
	  scanf("%d",&tmp);
	  val.push_back(tmp);
	}
	sort(coupon.begin(),coupon.end());
	sort(val.begin(),val.end());
	//加和增大，即是++ 或--
	//排序后，从小到大 --;从大到小++;中间部分为+-
	//所以首位各遍历一遍求和即可。
	int p,q,sum;
	sum=p=q=0;
	while(p<N&&q<M&&coupon[p]<0&&val[q]<0)
	{
		sum+=coupon[p++]*val[q++];
	}
	//注意M和N不一定相等
	p=N-1;
	q=M-1;
	while(p>=0&&q>=0&&coupon[p]>0&&val[q]>0)
	{
		sum+=coupon[p--]*val[q--];
	}
	cout<<sum<<endl;
	return 0;
}
