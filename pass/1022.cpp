#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//由于后续比较的内容均可放在一块，故用容器存储这些字符串
struct _book
{
	string num;
	vector<string> data;
};
vector<_book>book;
int N=0;
int M=0;
//由于编号是格式化后的字符串，即可以按字符排序然后在查找书籍
bool comp(_book a,_book  b)
{
	if(a.num<b.num)
	  return true;
	return false;
}

int main()
{
	cin>>N;
	_book tmp_in;
	string tmp;
	for(int i=0;i<N;i++)
	{
		cin>>tmp_in.num;//num
		cin.get();//吸收掉cin未读取的回车
		//按行读取便于查找
		getline(cin,tmp);//title
		tmp_in.data.push_back(tmp);
		getline(cin,tmp);//author
		tmp_in.data.push_back(tmp);
		char ctmp[1010];
		int j=0;
		//keywords是按空格划分，便于查找
		while((ctmp[j++]=cin.get())!='\n')
		{
			if(ctmp[j-1]==' ')
			{
				ctmp[j-1]='\0';
				tmp_in.data.push_back(ctmp);
				memset(ctmp,'\0',1010);
				j=0;
			}
		}
		if(j>0)
		{
			//读取最后的回车分界字符
			ctmp[j-1]='\0';
			tmp_in.data.push_back(ctmp);
		}
		//publisher
		getline(cin,tmp);
		tmp_in.data.push_back(tmp);
		//publish time
		getline(cin,tmp);
		tmp_in.data.push_back(tmp);

		book.push_back(tmp_in);
		tmp_in.data.clear();
	}
	//排序
	sort(book.begin(),book.end(),comp);
	cin>>M;
	string tmp_1;
	string tmp_2;
	bool isFound=false;
	vector<string> query;
	for(int i=0;i<M;i++)
	{
		cin>>tmp_1;
		cin.get();
		getline(cin,tmp_2);
		query.push_back(tmp_1);
		query.push_back(tmp_2);
	}

	//search
	for(int i=0;i<query.size();)
	{
		tmp_1=query.at(i++);
		tmp_2=query.at(i++);
		cout<<tmp_1<<" "<<tmp_2<<endl;
		for(int j=0;j<book.size();j++)
		{
			if(tmp_2==book.at(j).num)
			{
				cout<<book.at(j).num<<endl;
				isFound=true;
				continue;
			}
			for(int k=0;k<book.at(j).data.size();k++)
			{
				if(tmp_2==book.at(j).data.at(k))
				{
					cout<<book.at(j).num<<endl;
					isFound=true;
					break;
				}
			}
		}
		if(isFound==false)
		{
			cout<<"Not Found"<<endl;
		}
		isFound=false;
	}
	return 0;
}
