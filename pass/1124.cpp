#include<iostream>
#include<vector>
using namespace std;
int M;
int N;
int S;

string tmp_s;
vector<string>que;
int main()
{
	cin>>M>>N>>S;
	int tmp_a=S-1;
	bool isNo=true;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_s;
		for(int j=0;j<que.size();j++)
		{
			if(tmp_s==que.at(j))
			{
				tmp_a++;
			}
		}
		if(i==tmp_a)
		{
			isNo=false;
			cout<<tmp_s<<endl;
			que.push_back(tmp_s);
			tmp_a+=N;
		}
	}
	if(isNo==true)
	  cout<<"Keep going..."<<endl;

	return 0;
}
