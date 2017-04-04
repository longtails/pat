#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstdio>

using namespace std;
int w[300000];
int f[300000];
vector<int> fc[300000];//the member of gang
//长度为3的char
void output(int a)
{
	char tmp[4];
	tmp[3]='\0';
	for(int i=2;i>=0;i--)
	{
		tmp[i]=char('A'+a%100);
		a/=100;
	}
	cout<<tmp;
}
int toInt(char*a)
{
	int tmp=0;
	for(int i=0;i<3;i++)
	{
		tmp*=100;
		tmp+=(a[i]-'A');
	}
	return tmp;
}
int gf(int a)
{
	if(a==f[a])
	  return a;
	return f[a]=gf(f[a]);
}
void un(int a,int b)
{
	int fa=gf(a);
	int fb=gf(b);
	if(fa>fb)
	  f[fa]=fb;
	else
	  f[fb]=fa;
}
bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.first<b.first;
}
int main()
{
	//freopen("in","r",stdin);
	fill(w,w+30000,0);
	for(int i=0;i<300000;i++)
	  f[i]=i;
	int n,k,tmp,l,r;
	char tmp1[4];
	char tmp2[4];
	tmp1[3]='\0';
	tmp2[3]='\0';
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>tmp1>>tmp2>>tmp;
		l=toInt(tmp1);
		r=toInt(tmp2);
		w[l]+=tmp;
		w[r]+=tmp;
		un(l,r);
	}
	for(int i=0;i<300000;i++)
		if(w[i]>0)		fc[gf(i)].push_back(i);
	vector<pair<int,int> >out;
	pair<int,int> tmp_pair;
	int tmp_w=0;
	for(int i=0;i<300000;i++)
	{
		if(w[i]>0&&fc[i].size()>2)
		{
			tmp_pair.first=fc[i].at(0);
			tmp_pair.second=fc[i].size();
			tmp_w=w[fc[i].at(0)];
			//find the head of gang
			for(int j=1;j<fc[i].size();j++)
			{
				tmp_w+=w[fc[i].at(j)];
				if(w[fc[i].at(j)]>w[tmp_pair.first])
				{
					tmp_pair.first=fc[i].at(j);
				}
			}
			//the total relation w:the sum of member`s w divide 2 
			if(tmp_w/2>k)
				out.push_back(tmp_pair);
		}
	}
	cout<<out.size()<<endl;
	if(out.size()==0)
	  return 0;
	sort(out.begin(),out.end(),comp);
	for(int i=0;i<out.size();i++)
	{
		output(out.at(i).first);
		cout<<" "<<out.at(i).second<<endl;
	}
	return 0;
}
