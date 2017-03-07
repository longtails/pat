#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	node* left;
	node* right;
	int val;
	public: node(){left=right=NULL;val=0;}
};
int N;
int LNR[510];
int LRN[510];
node*root=NULL;
int size;
//build tree
node* build(int a,int b,node*root )
{
	int tmp_r=-1;
	//get root
	int i=a;
	for(;i<=b;i++)
	{
		if(LNR[i]==LRN[size-1])
		{
			size--;
			tmp_r=LNR[i];
			root=new node();
			root->val=tmp_r;
			break;
		}
	}
	if(tmp_r==-1)
		return NULL;
	//由于是lnr，故先建立右子树
	root->right=build(i+1,b,root->right);
	root->left=build(a,i-1,root->left);
	return root;
}
vector<vector<int> >out;
void output(node *root)
{
	queue<node*> que;
	node* last=root;
	node* nlast=root;
	que.push(root);
	vector<int> tmp;
	while(que.empty()==false)
	{
		tmp.push_back(que.front()->val);
	
		if(que.front()->left!=NULL)
		{
			que.push(que.front()->left);
			nlast=que.front()->left;
		}
		if(que.front()->right!=NULL)
		{
			que.push(que.front()->right);
			nlast=que.front()->right;
		}
		if(que.front()==last)
		{
			out.push_back(tmp);
			last=nlast;
			tmp.clear();
		}
		que.pop();
	}
}

int main()
{
	cin>>N;
	size=N;
	for(int i=0;i<N;i++)
		cin>>LNR[i];
	for(int i=0;i<N;i++)
		cin>>LRN[i];
	root=build(0,N-1,root);
	output(root);
	queue<int>tmp;
	for(int i=0;i<out.size();i++)
	{
		if(i%2==1)
		{
			for(int j=0;j<out.at(i).size();j++)
			{
				tmp.push(out.at(i).at(j));
			}
		}else
			for(int j=out.at(i).size()-1;j>=0;j--)
			{
				tmp.push(out.at(i).at(j));
			}
	}
	while(tmp.empty()==false)
	{
		cout<<tmp.front();
		tmp.pop();
		if(tmp.empty()==false)
		  cout<<" ";
		else
		  cout<<endl;
	}
	return 0;
}

