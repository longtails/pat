#include<iostream>
using namespace std;
int N;
struct tree
{
	tree* left;
	tree* right;
	int val;
	int flag;
};
tree *root=NULL;
bool output(tree *a);
//还要向上返回的,向右转
tree *rightRotate(tree*a)
{
	tree*b=a->left;
	a->left=b->right;
	b->right=a;
	return b;
}
//向左转
tree* leftRotate(tree *a)
{
	tree* b=a->right;
	a->right=b->left;
	b->left=a;
	return b;
}
tree* leftRightRotate(tree*a)
{
	a->left=leftRotate(a->left);
	return rightRotate(a);
}
tree *rightLeftRotate(tree*a)
{
	a->right=rightRotate(a->right);
	return leftRotate(a);
}
int getHeight(tree* a)
{
	if(a==NULL)
	  return 0;
	else
	{
		int l=getHeight(a->left);
		int r=getHeight(a->right);
		return l>r?l+1:r+1;
	}
}
//不要父亲，就需要返回时来更新
//当a==NULL时，new的tree是传不出去的，
//当a不是NULL,对a的内容设置new的tree是可以传出去的
tree* insert(tree *a,int val)
{
	if(a==NULL)
	{
		//这个a传不出去
		a=new tree();
		a->left=NULL;
		a->right=NULL;
		a->val=val;
		return a;
	}
	//r
	if(val>a->val)
	{
		//返回时绑定
		a->right=insert(a->right,val);
		//插入后要调整了
		int l=getHeight(a->left);
		int r=getHeight(a->right);
		if(r-l>=2)
		{
			//r r
			if(val>a->right->val)
			{
				a=leftRotate(a);
			}else
			{
				a=rightLeftRotate(a);
			}
		}
	}else if(val<a->val)
	{
		a->left=insert(a->left,val);
		//插入后要调整了
		int l=getHeight(a->left);
		int r=getHeight(a->right);
		if(l-r>=2)
		{
			//l r
			if(val>a->left->val)
			{
				a=leftRightRotate(a);
			}else
			{
				a=rightRotate(a);
			}
		}
	}
	return a;
}
#include<queue>
bool output(tree *a)
{
	queue<tree*>que;
	que.push(a);
	int flag=1;
	a->flag=1;
	while(que.empty()==false)
	{
		if(que.front()->left!=NULL)
		{
			que.push(que.front()->left);
			que.front()->left->flag=que.front()->flag*2;
		}
		if(que.front()->right!=NULL)
		{
			que.push(que.front()->right);
			que.front()->right->flag=que.front()->flag*2+1;
		}
		cout<<que.front()->val;
		flag=que.front()->flag;
		que.pop();
		if(que.empty()==false)
		  cout<<" ";
		else
		  cout<<endl;
	}
	if(flag==N)
	  return true;
	else
	  return false;
}
int main()
{
	cin>>N;
	int tmp=0;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		//insert
		root=insert(root,tmp);
	}
	if(output(root)==false)
	  cout<<"NO"<<endl;
	else
	  cout<<"YES"<<endl;
	return 0;
}
/*
部分正确，原因，没有全局调整
#include<iostream>
#include<queue>
using namespace std;
struct _tree
{
	_tree *l;
	_tree *r;
	_tree *p;
	int v;
	int h;
	int flag;
	_tree()
	{
		l=r=p=NULL;
		v=h=0;
		flag=0;
	}
};
int N;
_tree *root=NULL;
void ll(_tree *b)
{
	_tree* a=b->p;

	
	if(a->p!=NULL)
	{

		if(a->p->l==a)
		  a->p->l=b;
		if(a->p->r==a)
		  a->p->r=b;
	}
	b->p=a->p;

	//b->r有可能是NULL
	a->l=b->r;
	if(b->r!=NULL)
		b->r->p=a;
	b->r=a;
	a->p=b;

	if(b->p==NULL)
	{

	  root=b;
	}
}
void lr(_tree *b)
{
	_tree* a=b->p;
	_tree* c=b->r;

	if(a->p!=NULL)
	{
		if(a->p->l==a)
		  a->p->l=c;
		if(a->p->r==a)
		  a->p->r=c;
	}
	
	//l
	b->r=c->l;
	if(c->l!=NULL)
	  c->l->p=b;
	c->l=b;
	b->p=c;
	c->p=a;
	//r
	a->l=c->r;
	c->r=a;
	c->p=a->p;
	a->p=c;

	if(c->p==NULL)
	{
		 root=c;
	}
}
void rl(_tree *b)
{
	_tree*a=b->p;
	_tree*c=b->l;

	if(a->p!=NULL)
	{
		if(a->p->l==a)
		  a->p->l=c;
		if(a->p->r==a)
		  a->p->r=c;
	}
	

	//r
	c->p=a;
	if(c->r!=NULL)
	  c->r->p=b;
	b->l=c->r;
	c->r=b;
	b->p=c;
	//l
	c->p=a->p;
	a->p=c;
	a->r=c->l;
	c->l=a;
	if(c->p==NULL)
	  root=c;
}
void rr(_tree *b)
{
	_tree*a=b->p;
	//1
	if(a->p!=NULL)
	{
		if(a->p->l==a)
		  a->p->l=b;
		if(a->p->r==a)
		  a->p->r=b;
	}
	b->p=a->p;
	//2
	a->p=b;

	a->r=b->l;

	if(b->l!=NULL)
		b->l->p=a;

	b->l=a;

	if(b->p==NULL)
	  root=b;
}
int updateH(_tree *a)
{
	if(a==NULL)
	  return 0;
	int tmp_a=updateH(a->l);
	int tmp_b=updateH(a->r);
	a->h=tmp_a-tmp_b;
	if(tmp_a>tmp_b)
	  return tmp_a+1;
	else
	  return tmp_b+1;
}
void avl(_tree*a)
{
	if(a==NULL)
	  return;

    //if(a->h>-2&&a->h<2)
	 // return;
	if(a->h==2)
	{
		if(a->l!=NULL)
		{
			if(a->l->h<-1||a->l->h>1)
			  avl(a->l);
			else if(a->l->h==1)
			{
				//l l
				ll(a->l);
			}else if(a->l->h==-1)
			{
				if(a->l->r!=NULL&&a->l->r->h==1)
				{
					//l r
					lr(a->l);

				}else
				  avl(a->l);
			}
		}
	} else if(a->h==-2)
	{
		if(a->r!=NULL)
		{
			if(a->r->h<-1||a->r->h>1)
			{
			  avl(a->r);
			}
			else if(a->r->h==1)
			{
				if(a->r->l!=NULL&&a->r->l->h==1)
				{
					//r l
					rl(a->r);

				}
			}else if(a->r->h==-1)
			{
				//r r
				rr(a->r);
			}
		}
	}else if(a->h==1)
	  avl(a->l);
	else if(a->h==-1)
	  avl(a->r);
}
bool output(_tree *node);
void insertAt(_tree *a,_tree*b)
{
	//a:root b:insert
	if(a==NULL)
	  return;
	if(b->v<a->v)
	{
		++a->h;
		if(a->l==NULL)
		{
			a->l=b;
			b->p=a;
			updateH(root);
			avl(root);
			updateH(root);
		}else
			insertAt(a->l,b);
	}else
	{
		--a->h;
		if(a->r==NULL)
		{
			a->r=b;
			b->p=a;
			updateH(root);
			avl(root);
			updateH(root);
			//avl(a);
			}else
			insertAt(a->r,b);
	}
}
void insert(int a)
{
	_tree *node=new _tree();
	node->v=a;
	node->h=0;
	if(root==NULL)
	{
		root=node;
		return;
	}else
		insertAt(root,node);
}
bool output(_tree *node)
{
	int tmp_last=0;
	queue<_tree*>myQue;
	myQue.push(node);
	tmp_last=node->flag;
	node->flag=1;
	while(myQue.empty()==false)
	{
		if(myQue.front()->l!=NULL)
		{
			myQue.push(myQue.front()->l);
			myQue.front()->l->flag=myQue.front()->flag*2;
		}
		if(myQue.front()->r!=NULL)
		{
			myQue.push(myQue.front()->r);
			myQue.front()->r->flag=myQue.front()->flag*2+1;
		}
		cout<<myQue.front()->v;
		tmp_last=myQue.front()->flag;
		myQue.pop();
		if(myQue.empty()==false)
		  cout<<" ";
		else
		{
		  cout<<endl;
		  if(tmp_last==N)
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>N;
	int tmp=0;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		insert(tmp);
	}
	if(output(root)==true)
	  cout<<"YES"<<endl;
	else
	  cout<<"NO"<<endl;
	return 0;
}
*/
