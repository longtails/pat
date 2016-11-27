#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
/*
 *
 *   1、查找f,
 *   2、两两合并,即链化
 * */
//f的下表为数据，内容为f
int f[1005];
int gf(int c)
{
	//这一步的操作是对于union来说的，因为union,只是链化，让该组的数据直接指向f
	//这样更新有问题，不是更新树的顶端，造成部分更新
	//int cf=gf(f[c]);
	//return f[c]=cf;//在此更新
	//必须最后来一次全部的更新
	if(f[c]!=c) return f[c]=gf(f[c]);

	return c;
}
bool big(int a,int b)
{
	return a>b;
}
int main()
{
	int n=0;
	//方便我们最好的查找计算
	memset(f,-1,sizeof(f));
	cin>>n;
	//由于最后是求人数，即是将人分组
	vector<int>in[1005];
	vector<int>d;
	d.assign(n,-1);
	//这其中的计算是有线索的，并不会受-1影响
	for(int i=0;i<n;i++)
	{
		int hobs=0;
		scanf("%d:",&hobs);
		//线化
		for(int j=0;j<hobs;j++)
		{
			int hob=0;
			cin>>hob;
			in[hob].push_back(i);
		}
	}

	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<1005;i++)
	{

		if(in[i].size()==0)
		  continue;

	  //就算在这操作，将改组元素直接指向f,但并不能保证a或b就是链且是末端
	  //该操作只能算是优化性能。
	  //并且，在优化时，还是寻找父亲，故在gf中更合理
		//i号hob,人数分组合并
		int u=gf(in[i][0]);
		for(int j=1;j<in[i].size();j++)
		{
			int v=gf(in[i][j]);
			//这还必须是这样，归一
			if(u!=v)f[v]=u;
		}
	}

	//更新f,使其直接指向父亲
	for(int i=0;i<n;i++)gf(i);

	vector<int>out;
	out.assign(n,0);
	//for(int i=0;i<n;i++)out[gf(i)]++;
	for(int i=0;i<n;i++)out[f[i]]++;
	sort(out.begin(),out.begin()+out.size(),big);

	int count=0;
	for(int i=0;i<n;i++)
	{
		if(out[i]==0)
		  continue;
		count++;
	}
	cout<<count<<endl;
	for(int i=0;i<n;i++)
	{
		if(out[i]>0)
		  cout<<out[i];
		if(out[i+1]>0)
		  cout<<" ";
		if(out[i+1]==0)
		{
			cout<<endl;
			break;
		}
	}
	return 0;
}
	
/*
vector<vector<int> > cl;
bool big(int a,int b)
{
	return a>b;
}
int main()
{
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> d;
		vector<int> v;
		d.assign(1001,-1);
		int m=0;
		scanf("%d:",&m);
		d[0]=1;
		for(int j=0;j<m;j++)
		{
			int t=0;
			cin>>t;
			d[t]=1;
			v.push_back(t);
		}
		int flag=0;
		for(int j=0;j<cl.size();j++)
		{
			vector<int>&tmp=cl[j];
			for(int a:v)
			{
				if(tmp[a]!=-1)
				{
				  flag=1;
				  break;
				}
			}
			if(flag==1)
			{
				for(int a:v)
				{
					tmp[a]=1;
				}
				tmp[0]++;
				break;
			}
		}
		if(flag==0)
		{
			cl.push_back(d);
		}else
			flag=0;
	}
	cout<<cl.size()<<endl;
	vector<int> out;
	for(vector<int>a:cl)
	{
		out.push_back(a[0]);
	}
	sort(out.begin(),out.begin()+cl.size(),big);
	for( int i=0;i<out.size();i++)
	{
		cout<<out[i];
		if(i<(out.size()-1))
		  cout<<" ";
	}
	cout<<endl;
	return 0;
}*/
