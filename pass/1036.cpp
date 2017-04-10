#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int N;
struct T{
	string name;
	string gender;
	string subject;
	int score;
};
vector<T>m;
vector<T>f;
bool comp(T a,T b)
{
	return a.score<b.score;
}
int main()
{
	//freopen("in","r",stdin);
	cin>>N;
	T tmp;
	for(int i=0;i<N;i++)
	{
		cin>>tmp.name>>tmp.gender>>tmp.subject>>tmp.score;
		if(tmp.gender=="M")
		  m.push_back(tmp);
		else
		  f.push_back(tmp);
	}
	sort(m.begin(),m.end(),comp);
	sort(f.begin(),f.end(),comp);
	if(f.size()!=0)
	{
	  cout<<f.at(f.size()-1).name<<" ";
	  cout<<f.at(f.size()-1).subject<<endl;
	}else
		cout<<"Absent"<<endl;
        if(m.size()!=0)
	{
		cout<<m.at(0).name<<" ";
		cout<<m.at(0).subject<<endl;
	}else
		cout<<"Absent"<<endl;
	if(m.size()==0||f.size()==0)
	  cout<<"NA"<<endl;
	else
	  cout<<f.at(f.size()-1).score-m.at(0).score<<endl;
	return 0;
}
