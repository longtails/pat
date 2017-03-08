#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long int>A;
vector<long int>B;
bool comp(long int a,long int b)
{
	if(a<b)
		return true;
	else
	  return false;
}
int main()
{
	long int M;
	long int N;
	long int tmp;
	scanf("%ld",&M);
	for(long int i=0;i<M;i++)
	{
		scanf("%ld",&tmp);
		A.push_back(tmp);
	}
	scanf("%ld",&N);
	for(long int i=0;i<N;i++)
	{
		scanf("%ld",&tmp);
		A.push_back(tmp);
	}
	//还好内存和时间限制的不太大，不然我这代码早挂了
	sort(A.begin(),A.end(),comp);
	B.push_back(A.at(0));
	for(int i=1;i<A.size();i++)
	{
		if(B.at(B.size()-1)==A.at(i))
		  continue;
		B.push_back(A.at(i));
	}

	if(B.size()%2==1)
		printf("%ld\n",B.at(B.size()/2));
	else
		printf("%ld\n",B.at(B.size()/2-1));

	return 0;
}
