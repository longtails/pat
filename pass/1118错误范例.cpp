#include<iostream>
#include<string>
using namespace std;
#define MAX 10010
int birds[MAX];
int que[MAX];
int main()
{
	int numOfTrees=0;
	int numOfpictures=0;
	cin>>numOfpictures;
	for(int i=0;i<numOfpictures;i++)
	{
		int numOfBirds=0;
		cin>>numOfBirds;
		if(numOfBirds==0)
		  continue;
		int bird[numOfBirds]={0};
		int which=0;
		for(int j=0;j<numOfBirds;j++)
		{
			cin>>bird[j];
			if(which==0&&birds[bird[j]]!=0)
			{
				which=birds[bird[j]];
			}
		}

		if(which!=0)
		{
			for(int j=0;j<numOfBirds;j++)
			{
				if(birds[bird[j]]==0)
				  birds[0]++;
				birds[bird[j]]=which;
			}
			which=0;
		}
		else
		{
			numOfTrees++;
			for(int j=0;j<numOfBirds;j++)
			{
				birds[bird[j]]=numOfTrees;
			}
			birds[0]+=numOfBirds;
		}
	}

	int numOfQue=0;
	cin>>numOfQue;

	for(int i=0;i<numOfQue;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		if(birds[t1]==birds[t2])
		{
			que[i]=1;
		}else
			que[i]=0;
	}
	
	cout<<numOfTrees<<" "<<birds[0]<<endl;
	for(int i=0;i<numOfQue;i++)
	{
		if(que[i]==1)
		  cout<<"Yes"<<endl;
		else
		  cout<<"No"<<endl;
	}


	return 0;
}
