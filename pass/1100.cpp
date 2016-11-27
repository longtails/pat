#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
map<string,int>m1={
	{"tret",0},
	{"jan",1},
	{"feb",2},
	{"mar",3},
	{"apr",4},
	{"may",5},
	{"jun",6},
	{"jly",7},
	{"aug",8},
	{"sep",9},
	{"oct",10},
	{"nov",11},
	{"dec",12},
	{"tam",13},
	{"hel",26},
	{"maa",39},
	{"huh",52},
	{"tou",65},
	{"kes",78},
	{"hei",91},
	{"elo",104},
	{"syy",117},
	{"lok",130},
	{"mer",143},
	{"jou",156}

};
map<string,int>m2={
	{"tam",1},
	{"hel",2},
	{"maa",3},
	{"huh",4},
	{"tou",5},
	{"kes",6},
	{"hei",7},
	{"elo",8},
	{"syy",9},
	{"lok",10},
	{"mer",11},
	{"jou",12}
};
map<int,string>m3={
	{0,"tret"},
	{1,"jan"},
	{2,"feb"},
	{3,"mar"},
	{4,"apr"},
	{5,"may"},
	{6,"jun"},
	{7,"jly"},
	{8,"aug"},
	{9,"sep"},
	{10,"oct"},
	{11,"nov"},
	{12,"dec"}
};
map<int,string>m4={
	{1,"tam"},
	{2,"hel"},
	{3,"maa"},
	{4,"huh"},
	{5,"tou"},
	{6,"kes"},
	{7,"hei"},
	{8,"elo"},
	{9,"syy"},
	{10,"lok"},
	{11,"mer"},
	{12,"jou"}
};
int main()
{
	int n=0;
	char tmp[110][30];
	cin>>n;
	//老问题了
	getchar();
	string sttmp;
	for(int i=0;i<n;i++)
	{
		getline(cin,sttmp);
		memcpy(tmp[i],sttmp.c_str(),sttmp.length()+1);
	}
	for(int i=0;i<n;i++)
	{
		if(tmp[i][0]>='0'&&tmp[i][0]<='9')
		{
			int t=atoi(tmp[i]);
			if(t>=13)
			{
				cout<<m4.at(t/13);
				if(t%13!=0)
				  cout<<" "<<m3.at(t%13)<<endl;
				else
				  cout<<endl;
			}
			else if(t==0)
			{
			  cout<<"tret"<<endl;
			}
			else 
			{
				  cout<<m3.at(t%13)<<endl;
			}
		}else
		{
			int it=0;
			char *t=strtok(tmp[i]," ");
			char *tt=NULL;
			if((tt=strtok(NULL," "))!=NULL)
			{
				it=13*m2.at(t)+m1.at(tt);
			}else
			{
				if(strcmp(t,"tam")==0)
				{
				  it=13;
				}
				else
				  it=m1.at(t);
			}
			cout<<it<<endl;
		}
	}
	return 0;
}
