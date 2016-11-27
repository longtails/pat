#include<iostream>
#include<vector>
using namespace std;
struct A
{
	A*l;
	A*r;
	int val;
	int deep;
	A()
	{
		l=r=NULL;
		val=deep=0;
	}
};
int deep=1;
int MAX=1;
void create(A*node,A*d)
{
	if(node==NULL)
	  return;
	deep++;
	if(node->val>=d->val)
	{
	  if(node->l==NULL)
	  {
		node->l=d;
		d->deep=deep;
		if(MAX<deep)
			  MAX=deep;
	
		deep=1;
	  }else
		  create(node->l,d);
	}
	else
	{
	  if(node->r==NULL)
	  {
		node->r=d;
		d->deep=deep;
		if(MAX<deep)
			  MAX=deep;
		deep=1;
	  }else
		create(node->r,d);
	}
}
int main()
{
	int n=0;
	cin>>n;
	int m=0;
	int o1=0;
	int o2=0;
	A*data=NULL;
	
	vector<A*>in;
	if(n==1)
	{
		cin>>o1;
		cout<<1<<" + "<<0<<" = "<<1<<endl;
		return 0;
	}else
	{
		cin>>m;
		data=new A;
		data->val=m;
		data->deep=1;
		in.push_back(data);
	}
	for(int i=1;i<n;i++)
	{
		cin>>m;
		A *tmp=new A;
		tmp->val=m;
		create(data,tmp);
		in.push_back(tmp);
	}
	for(A*a:in)
	{
		if(a->deep==MAX)
		  o1++;
		if(a->deep==(MAX-1))
		  o2++;
	    delete a;
	}
	cout<<o1<<" + "<<o2<<" = "<<o1+o2<<endl;
	return 0;
}

