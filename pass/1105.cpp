#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
int m[10000][10000];
using namespace std;
int r=0;
int c=0;
void ass(vector<int>&d)
{
	int l=0;
	int ii=1;
	int jj=1;
	int size=d.size()-1;
	int pos=1;
	while(d[0]!=size)
	{
		if(l==0)
		{
			l=1;
			for(int i=1;i<=c;i++)
			{
				if(m[ii][i]==0)
				{
					jj=i;
					m[ii][jj]=d[pos];
					pos++;
					d[0]++;
				}
			}
		}
		else if(l==1)
		{
			l=2;
			for(int i=1;i<=r;i++)
			{
				if(m[i][jj]==0)
				{
					ii=i;
					m[ii][jj]=d[pos];
					pos++;
					d[0]++;
				}
			}
		}
		else if(l==2)
		{
			l=3;
			for(int i=c;i>0;i--)
			{
				if(m[ii][i]==0)
				{
					jj=i;
					m[ii][jj]=d[pos];
					pos++;
					d[0]++;
				}
			}
	
		}else
		{
			l=0;
			for(int i=r;i>0;i--)
			{
				if(m[i][jj]==0)
				{
					ii=i;
					m[ii][jj]=d[pos];
					pos++;
					d[0]++;
				}
			}
		}

	}
}
bool cam(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	vector<int> d;
	vector<int> v;
	d.push_back(0);
	v.push_back(0);
	//需要添加数据时，直接排序
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		d.push_back(tmp);
		v.push_back(0);
	}
	int half=sqrt(n);
	for(int i=half;i>0;i--)
	{
		if(n%i==0)
		{
			half=i;
			break;
		}
	}
	c=half;
	r=n/c;

	sort(d.begin()+1,d.begin()+d.size(),cam);
	
	ass(d);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
		  cout<<m[i][j];
		  if(j<c)
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
