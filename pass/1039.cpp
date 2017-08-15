#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
PAT的时间限制一般没有那么严格，但是这道题很明显是要求用hash方法做，
并且坑定了使用stl中的map方法。
有人说是map中使用了string==来查找，造成超时，但经过创建class A,重载==
和<,发现结果仍是最后一个测试点超时。

map内部是通过平衡二叉树完成查找的，而hash是通过直接地址映射完成，是常量级的
总结: 
1.string cin cout均是耗时操作
2.map中使用==进行判断，string的==较为复杂,最后一个测试点超时
3.vector.size()返回的是unsinged int类型,也就是说支持2^32个元素
 */
const int maxn=26*26*26*10+10;
vector<int>data[maxn];
int getid(char *name)
{
	int id=0;
	for(int i=0;i<3;i++)
		id=id*26+(name[i]-'A');
	id=id*10+(name[3]-'0');
	//最后发现原因是忘了*10,但为什么只有最后一个测试没过
	//还是运行超时?之所有有部分通过是因为，测试用例都很小吧。
	//导致数据间隔有一定的空闲，当数据较大是，便超出空闲。
	return id;
}
int main()
{
	freopen("in","r",stdin);
	int SN,CN;
	scanf("%d %d",&CN,&SN);
	int sindex,cn;
	char sstu[5];
	int id=0;
	for(int i=0;i<SN;i++)
	{
		scanf("%d %d",&sindex,&cn);
		for(int j=0;j<cn;j++)
		{
			scanf("%s",sstu);
			id=getid(sstu);
			data[id].push_back(sindex);
		}
	}
	for(int i=0;i<CN;i++)
	{
		scanf("%s",sstu);
		id=getid(sstu);
		sort(data[id].begin(),data[id].end());
		printf("%s %lu",sstu,data[id].size());
		for(int j=0;j<data[id].size();j++)
			printf(" %d",data[id][j]);
		printf("\n");
	}
	return 0;
}
/*
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
//采用key-value方式
typedef map<string,vector<int> > imap;
int main()
{
	//freopen("in","r",stdin);
	imap itmp;
	int SN,CN;
	cin>>CN>>SN;
	int sindex,cn;
	string sstu;
	for(int i=0;i<SN;i++)
	{
		cin>>sindex>>cn;
		for(int j=0;j<cn;j++)
		{
			cin>>sstu;
			if(itmp[sstu].size()==0)
				itmp[sstu].push_back(sindex);
			else
			{
				for(int k=0;k<itmp[sstu].size();k++)
				{
				
					if(sindex<itmp[sstu][k])
					{
					  itmp[sstu].insert(itmp[sstu].begin()+k,sindex);
					  break;
					}else if(k+1>=itmp[sstu].size())
					{
					  itmp[sstu].push_back(sindex);
					  break;
					}
				}
			}
			
		}
	}

	for(int i=0;i<CN;i++)
	{
		cin>>sstu;
		cout<<sstu<<" "<<itmp[sstu].size();
		for(int j=0;j<itmp[sstu].size();j++)
		{
			cout<<" "<<itmp[sstu][j];
		}
		cout<<endl;
	}
	return 0;
}*/
