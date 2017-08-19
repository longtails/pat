#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct pairs
{
	char val[4];
	int seq;
};
bool comp(pairs a,pairs b)
{
	return a.seq<b.seq;
}
vector<pairs>cards;
void _init(int base,int size,char A)
{
	int i=base;
	for(int j=1;j<=size;i++,j++)
	{
		cards[i].val[0]=A;
		if(j<10)
			cards[i].val[1]=char('0'+j);
		else
		{
			cards[i].val[1]='1';
			cards[i].val[2]=char('0'+j%10);
		}
	}
}
void init()
{
	pairs tmp;
	tmp.val[2]='\0';
	tmp.val[3]='\0';
	cards.assign(54,tmp);

	_init(0,13,'S');
	_init(13,13,'H');
	_init(26,13,'C');
	_init(39,13,'D');
	_init(52,2,'J');
}
vector<int>seq;
int main()
{
	int N,tmp;
	freopen("in","r",stdin);
	init();
	cin>>N;

	for(int i=0;i<54;i++)
	{
		cin>>tmp;
		seq.push_back(tmp);
	}

	for(int j=0;j<N;j++)
	{
		for(int i=0;i<54;i++)
		{
			cards[i].seq=seq[i];
		}
		sort(cards.begin(),cards.end(),comp);
	}
	int i=0;
	for(i=0;i<cards.size()-1;i++)
	{
		cout<<cards[i].val<<" ";
	}
	cout<<cards[i].val<<endl;
	return 0;
}
