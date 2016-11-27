#include<iostream>
#include<vector>
using namespace std;
#define N 3577
struct _tree{
	int left;
	int right;
	int value;
};
int pre[N];
int post[N];
_tree tree[N];
bool unique=true;
vector<int> in;
void inTrave(int child)
{

	if(child<=0)
	{
	  return;
	}
	//NLR
	//in.push_back(child);
	inTrave(tree[child].left);
	//LNR
	in.push_back(child);
	inTrave(tree[child].right);
	//LRN
	//in.push_back(child);
}
void deTrave(int preBegin,int preEnd,int postBegin,int postEnd,int root)
{

	if(preBegin>preEnd)
	  return;
	if(postBegin>postEnd)
	  return;
	if(pre[preBegin]==post[postEnd])
	{
		unique=false;
		tree[root].value=root;
		tree[root].left=pre[preBegin];
		//真是这个点错了
		deTrave(preBegin+1,preEnd,postBegin,postEnd-1,pre[preBegin]);
	}
	else 
	{
		tree[root].value=root;
		tree[root].left=pre[preBegin];
		tree[root].right=post[postEnd];
		
		int i=0;
		int j=0;
		for(i=postBegin;i<=postEnd;i++)
		{
			if(pre[preBegin]==post[i])
			  break;
		}
		for(j=preBegin;j<=preEnd;j++)
		{
			if(post[postEnd]==pre[j])
			  break;
		}
		//查找不到会递归进-1，并在下一层退出
		//匹配左侧
		deTrave(preBegin+1,j-1,postBegin,i-1,pre[preBegin]);
		deTrave(j+1,preEnd,i+1,postEnd-1,post[postEnd]);
		//以下会造成该停止的时候没有停止，以至于在搜索的时候，
		//没有停止,造成环，导致段错误
		//deTrave(preBegin+1,preEnd,postBegin,i-1,pre[preBegin]);
		//deTrave(j+1,preEnd,postBegin,postEnd-1,post[postEnd]);
	
	}
}
int main()
{
	int count=0;
	cin>>count;
	//pre[0]=count;
	for(int i=1;i<=count;i++)
	{
		cin>>pre[i];
		pre[0]++;
	}
	post[0]=count;
	for(int i=1;i<=count;i++)
	{
		cin>>post[i];
	}
	if(count==0)
	  return 0;
	deTrave(2,pre[0],1,post[0]-1,pre[1]);
	if(unique==true)
	  cout<<"Yes"<<endl;
	else
	  cout<<"No"<<endl;

	inTrave(pre[1]);
	int i=0;
	for(i=0;i<in.size()-1;i++)
	{
		cout<<in.at(i)<<" ";
	}
	cout<<in.at(i)<<endl;
	return 0;
}
/*
 * 题目说明：
 *
 *
 *	考察二叉树的遍历问题
 *		 NLR,LRN,LNR之间的关系，以及对三种遍历的深刻理解
 *		 NLR LRN 如果我们将 LR RL视为一组即都是他们的孩子，则此时NLR LRN是对称的
 *		 一般我们对遍历前序能很快写出来，同样对于后序，我们从右侧，把R当做L，L当做R,那么此时
 *		 后序的也就能很快书写出来。
 *		通过NLR和LRN我们能找到共同的N,并找到它的左右孩子，当它没有左右孩子时，解递归到那一层时,
 *		就只剩下该节点了。
 *		接着我们要在N节点下的左右孩子下分别独立的递归下去，直到其中一个没有数据
 *
 *
 *		NLXXXXXXXRXXXXXXX
 *		YYYYLYYYYYYYYYYYRN
 *
 *
 *		左子树递归部分
 *		LXXXXXXXXXXXXXXX
 *		YYYYL
 *		右子树递归部分
 *		RXXXXXXX
 *		YYYYLYYYYYYYYYYYR
 *		.
 *		.
 *		.
 *
 *		这其实是对我们遍历时递归的一个解递归
 *		
 *
 *		关于二义性问题
 *		
 *		每一个递归部分
 *		我们通过NLR的L该值为x
 *		LRN的R值为y,
 *		通过x,y确定N的左右孩子
 *		当x==y时，我们无法确定该值是左还是右
 *
 */


