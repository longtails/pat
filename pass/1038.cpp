#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef vector<int> vint;
vint vsmall;
//is ab<ba
bool isSmall(vint a,vint b)
{
	int tmpa,tmpb;
	int sizea=a.size();
	int sizeb=b.size();
	for(int i=0;i<sizea+sizeb;i++)
	{
		if(i<sizea)
		  tmpa=a[i];
		else if(i<sizea+sizeb)
		  tmpa=b[i-sizea];

		if(i<sizeb)
		  tmpb=b[i];
		else if(i<sizeb+sizea)
		  tmpb=b[i-sizeb];
		if(tmpa<tmpb)
		  return true;
		else if(tmpa>tmpb)
		  return false;
	}
}
//二叉排序树
struct  bcomp
{
	vint tmp;
	bcomp *left=NULL;
	bcomp *right=NULL;
};
bcomp *head=NULL;
void insert(bcomp*root,bcomp*tmp)
{
	if(isSmall(root->tmp,tmp->tmp))
	{
		if(root->right==NULL)
		  root->right=tmp;
		else
		  insert(root->right,tmp);

	}else
	{
		if(root->left==NULL)
		  root->left=tmp;
		else
		  insert(root->left,tmp);
	}
}
void build(bcomp n)
{
	bcomp *btmp=new bcomp();//为方便AC，不delete操作
	btmp->tmp=n.tmp;
	if(head==NULL)
		head=btmp;
	else
		insert(head,btmp);
}
int zero=0;//处理不输出开头的0，如002，应是2
int allbits=0;//控制总位数，处理特殊情况，全是0，如000要输出0
void show(bcomp *root)
{
	if(root==NULL)
		return;
	show(root->left);
	for(int j=0;j<root->tmp.size();j++)
	{
		if(zero>0)
		  cout<<root->tmp[j];
		else if(root->tmp[j]>0)
		{
		  cout<<root->tmp[j];
		  zero++;
		}else if(zero+1==allbits)
		  cout<<root->tmp[j];
		//这绝对是坑点
		allbits--;
	}
	show(root->right);
}
int main()
{
	freopen("in","r",stdin);
	int N,tmp;
	vint vtmp;
	cin>>N;
	string stri;
	bcomp btmp;
	for(int i=0;i<N;i++)
	{
		cin>>stri;
		allbits+=stri.length();
		for(int j=0;j<stri.length();j++)
			vtmp.push_back(stri[j]-'0');
		btmp.tmp=vtmp;
		build(btmp);
		vtmp.clear();
	}
	show(head);
	return 0;
}
