#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node*l;
	Node*r;
};
void build(Node*&t,int val)
{
	if(t==NULL)
	{
		t=new Node;
		t->val=val;
		t->l=t->r=NULL;
	    return;
	}
	if(val<t->val)
	  build(t->l,val);
	else
	  build(t->r,val);
}
void traverse(Node*t,vector<int>&a)
{
	if(t==NULL)
	  return;
	a.push_back(t->val);
	traverse(t->l,a);
	traverse(t->r,a);
}
void traverse_mirror(Node*t,vector<int>&a)
{
	if(t==NULL)
	  return;
	a.push_back(t->val);
	traverse_mirror(t->r,a);
	traverse_mirror(t->l,a);
}
bool isBST(Node*&t,vector<int>&a,bool &isMirror)
{
	for(int i=0;i<a.size();i++)
	  build(t,a[i]);
	vector<int>b;
	traverse(t,b);
	int i=0;
	for(i=0;i<b.size();i++)
	{
		if(a[i]!=b[i])
		  break;
	}
	if(i==b.size())//succeed
	{
	  isMirror=false;
	  return true;
	}
	else
	{
		b.clear();
		traverse_mirror(t,b);
		for(i=0;i<b.size();i++)
		{
			if(a[i]!=b[i])
			  break;
		}
		if(i==b.size())//succeed
		{
			isMirror=true;
		    return true;
		}
	}
	return false;
}
void show(Node *t,bool isMirror=false,bool isRoot=false)
{
	if(t==NULL)
	  return ;
	if(isMirror==false)
	{
		show(t->l,isMirror);
		show(t->r,isMirror);
	}else
	{
		show(t->r,isMirror);
		show(t->l,isMirror);
	}
	cout<<t->val;
	if(!isRoot)
	  cout<<" ";
	else
	  cout<<endl;
}
int main()
{
	freopen("in","r",stdin);
	int N,tmp;
	bool isMirror=false;
	vector<int>pre;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		pre.push_back(tmp);
	}
	Node*t=NULL;
	if(isBST(t,pre,isMirror)==false)
	  cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		show(t,isMirror,true);
	}
	return 0;
}
