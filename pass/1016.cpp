#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
vector<double> rate;
double rate_sum=0;
struct _com
{
	string name;
	int mm;
	int dd;
	int hh;
	int mm2;
	bool isOn;
};
/*
 * compare of string && cstring 
 * 这里说的字母排序仅仅是按照前列字母的大小排序的，前列相等时，
 * 接着拿取后一个字母
 * */
int comp(_com a,_com b)
{
	if(a.name==b.name)
	{
		if(a.mm<b.mm)
		  return true;
		else if(a.mm>b.mm)
		  return false;

		if(a.dd<b.dd)
		  return true;
		else if(a.dd>b.dd)
		  return false;

		if(a.hh<b.hh)
		  return true;
		else if(a.hh>b.hh)
		  return false;


		if(a.mm2<b.mm2)
		  return true;
		else if(a.mm2>b.mm2)
		  return false;

		return false;
	}else
	  return a.name<b.name;
}
vector<_com> com;

int main()
{
	int tmp_rate=0;
	for(int i=0;i<24;i++)
	{
		cin>>tmp_rate;
		rate.push_back(tmp_rate);
		rate_sum+=tmp_rate;
	}
	int tmp_count=0;
	cin>>tmp_count;
	_com tmp_com;
	string tmp_line;
	for(int i=0;i<tmp_count;i++)
	{
		cin>>tmp_com.name;
		scanf("%2d:%2d:%2d:%2d",&tmp_com.mm,
					&tmp_com.dd,
					&tmp_com.hh,
					&tmp_com.mm2);
		cin>>tmp_line;
		if(strcmp(tmp_line.c_str(),"on-line")==false)
		  tmp_com.isOn=true;
		else
		  tmp_com.isOn=false;
		com.push_back(tmp_com);
	}
	sort(com.begin(),com.end(),comp);

	int count=1;
	//这一步其实，没必要，不再修改了
	_com com_tmp=com.at(0);
	for(int i=0;i<com.size();i++)
	{
		if(com_tmp.name!=com.at(i).name)
		{
			com_tmp=com.at(i);
			count++;
		}
	}
	com_tmp=com.at(0);
	int j=0;
	double total=0;//部分和
	int isBegin=0;//总和
	int isShow=0;//
	for(int i=0;i<count;i++)
	{
		for(;j<com.size();j++)
		{
			if(com_tmp.name==com.at(j).name)//&&j<com.size()-1)
			{
				if(com.at(j).isOn==true)
				{
					com_tmp=com.at(j);
					isBegin=1;

				}
				//已经成功配对
				else if(com.at(j).isOn==false&&isBegin==1)
				{
						com_tmp=com.at(j-1);						
						_com com_back=com_tmp;
						//on
						double tmp=0;
						int tmp_count=0;
						while(com_back.dd<com.at(j).dd||
									com_back.hh<com.at(j).hh||
									com_back.mm2<com.at(j).mm2)
						{
							tmp+=rate.at(com_back.hh);
							tmp_count++;
							if(com_back.mm2==59)
							{
								if(com_back.hh==23)
								  com_back.dd+=1;
								com_back.hh=(com_back.hh+1)%24;
							}
							com_back.mm2=(com_back.mm2+1)%60;
						}

						/*
						 * 错误范例，
						 10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10  
						 2
						 CYLL 01:01:06:01 on-line  
						 CYLL 01:01:06:02 off-line  
						 这样算的就明显错误了。

						 错误计算方法，以后计算时，尽量减少以分类计算这种计算方法，情况列举很容易丢失
						 建议：采取更通用的方法，比如更改后的计算方法。之后要加强这方面的训练。
					    double tmp=(60-com_tmp.mm2)*rate.at(com_tmp.hh)+
							com.at(j).mm2*rate.at(com.at(j).hh);
						//hh
						if(com_tmp.dd!=com.at(j).dd)
						{
							//不在同一天，分三步
							//1
							for(int i=com_tmp.hh+1;i<24;i++)
							{
								tmp+=rate.at(i)*60;
							}
							//2.day
							for(int i=com_tmp.dd+1;i<com.at(j).dd;i++)
							{
								tmp+=rate_sum*60;
							}
							//3.
							for(int i=0;i<com.at(j).hh;i++)
							{
								tmp+=rate.at(i)*60;
							}
						}else
						{
							//同一天,直接
							//1
							for(int i=com_tmp.hh+1;i<com.at(j).hh;i++)
							{
								tmp+=rate.at(i)*60;
							}
						}
						*/
						total+=tmp;
						if(total>0)
						{
							if(isShow==0)
							{
								printf("%s %02d\n",com_tmp.name.c_str(),com_tmp.mm);
								isShow=1;
							}

							printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
										com_tmp.dd,com_tmp.hh,com_tmp.mm2,
										com.at(j).dd,com.at(j).hh,com.at(j).mm2,
										tmp_count,
										tmp/100
								  );
							
						}

						isBegin=0;
				}
			}else
			{
				com_tmp=com.at(j);
				break;
			}
		}
		if(total>0)
			printf("Total amount: $%.2f\n",total/100);
		total=0;
		isShow=0;
		isBegin=0;
	}
	return 0;
}
/*************************************参考别人的代码*****************************************
 * 1.比较算法，这个自己要联系
 * 2.处理时间差部分,计算费用
 * */
    #include<iostream>  
    #include<stdio.h>  
    #include<stdlib.h>  
    #include<string.h>  
    #include<vector>  
    #include<map>  
    using namespace std;  
    const int HOURS=24;  
    const int NAME=21;  
    typedef struct Record{  
        char name[NAME];  
        int mou;  
        int dd;  
        int hh;  
        int mm;  
        char line[10];  
    }Record;  
    typedef struct Res{  
        float money;  
        int last_time;  
    }Res;  
    int compare_name(const void *a ,const void *b){  
        int tmp=strcmp(((Record*)a)->name,((Record *)b)->name);  
        if(tmp==0){  
            if(((Record*)a)->mou!=((Record *)b)->mou)  
                return ((Record*)a)->mou-((Record *)b)->mou;  
            if(((Record*)a)->dd!=((Record *)b)->dd)  
                return ((Record*)a)->dd-((Record *)b)->dd;  
            if(((Record*)a)->hh!=((Record *)b)->hh)  
                return ((Record*)a)->hh-((Record *)b)->hh;  
            if(((Record*)a)->mm!=((Record *)b)->mm)  
                return ((Record*)a)->mm-((Record *)b)->mm;  
        }  
        else  
            return tmp;  
    }  
//这个方式很厉害!
    void compute_money(Record *r1,Record *r2,int *rate, Res *res){  
        Record r;  
        r.dd=r1->dd;  
        r.hh=r1->hh;  
        r.mm=r1->mm;  
        res->money=0;  
        res->last_time=0;  
		//get
        while(r.dd<r2->dd||r.hh<r2->hh||r.mm<r2->mm){  
            res->money+=rate[r.hh];  
            res->last_time++;  
            r.mm++;  
            if(r.mm>=60){  
                r.mm=0;  
                r.hh++;  
                if(r.hh>=24){  
                    r.hh=0;  
                    r.dd++;  
                }  
            }  
        }  
        res->money/=100;  
    }  
    int check_ok(Record *r,int index,int n){  
        char pname[NAME];  
        int i,flag=0,has=0;  
        strcpy(pname,r[index].name);  
        for(i=index;i<n;i++){  
            if(strcmp(r[i].name,pname)==0){  
                if(r[i].line[1]=='n'){  
                    flag=1;  
                }  
                else if(r[i].line[1]=='f'&&1==flag){  
                    flag=0;  
                    has=1;  
                }  
            }  
            else  
                break;  
        }  
        return has;  
    }  
    int main()  
    {  
        int rate[HOURS];  
        int i,n;  
        for(i=0;i<HOURS;i++)  
            scanf("%d",&rate[i]);  
        scanf("%d",&n);  
        Record *r=new Record [n];  
        for(i=0;i<n;i++){  
            scanf("%s",r[i].name);  
            scanf("%d:%d:%d:%d",&r[i].mou,&r[i].dd,&r[i].hh,&r[i].mm);  
            scanf("%s",r[i].line);  
        }  
        qsort(r,n,sizeof(Record),compare_name);  
        if(n>0){  
            i=0;  
            while(i<n){  
                int has=check_ok(r,i,n);  
                char pname[NAME];  
                if(1==has){  
                    printf("%s %02d\n",r[i].name,r[i].mou);  
                    strcpy(pname,r[i].name);  
                    int flag=0;  
                    float t_money=0;  
                    Record rn;  
                    while(strcmp(pname,r[i].name)==0){  
                        if(r[i].line[1]=='n'){  
                            rn.dd=r[i].dd;  
                            rn.hh=r[i].hh;  
                            rn.mm=r[i].mm;  
                            flag=1;  
                        }  
                        else if(r[i].line[1]=='f'&&1==flag){  
                            flag=0;  
                            printf("%02d:%02d:%02d %02d:%02d:%02d",rn.dd,rn.hh,rn.mm,r[i].dd,r[i].hh,r[i].mm);  
                            Res res;  
                            compute_money(&rn,&r[i],rate,&res);  
                            printf(" %d $%.2f\n",res.last_time,res.money);  
                            t_money+=res.money;  
      
                        }  
                        i++;  
                    }  
                    printf("Total amount: $%.2f\n",t_money);  
                }  
                else  
                    i++;  
            }  
        }  
        return 0;  
    }  















