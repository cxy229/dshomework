#include<iostream>
using namespace std;
#include <stdio.h>
#include<string>
template<class T>
class LinkNode        //结点类
{
public:
	T data;		  //存储的数据
	LinkNode * next;  //指向下一结点的指针
	LinkNode(T data=0)//构造函数
	{
		this->data=data;
		next = NULL;
	}
};
template<class T>
class LinkList          //链表类
{
public:
	LinkNode<T> * head;	//头指针
	LinkNode<T> * tail; //尾指针
	int length;		//链表长度
public:
	LinkList()			//无参构造
	{
		head=tail=NULL;
		length=0;
	}
	void addfromback(T num) //从后面增加结点
	{
		if(head == NULL)//空链表
		{
			head=tail=new LinkNode<T>(num);
			head->next=tail->next=NULL;
			length++;
		}
		else
		{
			LinkNode<T>* p=new LinkNode<T>(num);
			tail->next=p;
			tail=p;
			tail->next=NULL;
			length++;
		}
	}
	void addfromfront(T num)		//从前面增加结点
	{
		if(head == NULL)
		{
			head=tail=new LinkNode<T>(num);
			head->next=tail->next=NULL;
			length++;
		}
		else
		{
			LinkNode<T>* p=new LinkNode<T>(num);
			p->next=head;
			head=p;
			length++;
		}
	}
	void addrandomly(int position,T num)  //在position后插入
	{
		if(position == 0)
			addfromfront(num);
		else if(position == length)
			addfromback(num);
		else
		{
			LinkNode<T>*p=head;
			for(int i=1;i<position;i++)
			{
				p=p->next;
			}
			LinkNode<T>*q=new LinkNode<T>(num);
			q->next=p->next;
			p->next=q;
			length++;
		}
	}
	void deletefromfront()//删除第一个结点
	{
		if(head == NULL)		//空链表
		{
			cout<<"No node to delete";
		}
		else
		{
			LinkNode<T> *p=head;
			head=head->next;
			delete p;
			length--;
		}
	}
	void deletefromback()//删除最后结点
	{
		if(tail == NULL)//空链表
		{
			cerr<<"No node to delete!"<<endl;
		}
		LinkNode<T>*p;
		for(p=head;p->next!= tail;p=p->next){}
		delete tail;
		tail=p;
		tail->next=NULL;
		length--;
	}
	void deleterandomly(int position)//删除任意位置结点
	{
		if(position == 0)
			deletefromfront();
		else if(position == length)
			deletefromback();
		else
		{
			LinkNode<T>*p=head;
			for(int i=1;i<position-1;i++)
			{
				p=p->next;
			}
			LinkNode<T>*q=p->next;
			p->next=q->next;
			q->next=NULL;
			delete q;
			length--;
		}
	}
	void deleteacertainnum(T num)//删除存放特定数值的结点
	{
		LinkNode<T>*p;
		int temp=1;
		for(p=head;p != NULL;p=p->next)
		{
			if(p->data == num)
				deleterandomly(temp);
			else temp++;
		}
	}
	LinkNode<T>* line(int l)//返回第l个结点
	{
		LinkNode<T>* p=head;
		for(int j=0;j<l;j++)
		{
			p=p->next;
		}
		return p;
	}
};
//光标
class Cursor
{
public:
    int line; //行
    int c;   //该行第几个
    Cursor()  // 初始化
	{
       line = 0;
       c = 0;
    }
    void set(int l, int n)// Cusor属性
	{
      line = l;
      c = n;
    }
    friend ostream& operator <<(ostream& out, Cursor& a);
    friend istream& operator >>(istream& in, Cursor& a);
};
ostream& operator <<(ostream& out, Cursor& a)
{
    out<<":第"<<a.line<<"个文本行"<<", "<<a.c<<"个字符之后";
    return out;
}
istream& operator >>(istream& in, Cursor& a)
{
    cout<<"文本行:";
    in>>a.line;
    cout<<"第几个字符:";
    in>>a.c;
    return in;
}

//文本类
class TextEditor
{
public:
	LinkList<string> article;
	string name;
	int cursor;
	int line;
	int total;    //总共有多少个字母
	TextEditor()
	{
	     name="TextEditor";
	     line=0;
	     total=0;
	     cursor = 0;
    }

	string getname()
	{
	   return name;
    }
	void setname() {
		cout << "name:" << endl;
		cin >> name;
	}
	int getcursor()
	{
	  return cursor;
    }

	void movecursor(int origin=0,int offset=0)//origin=0从起点 1从当前位置 orgin = -1移至结尾
	{
       if(origin == 0){
    	   cursor = offset;
       }else if(origin == 1){
    	   cursor += offset;
       }else if(origin==-1){
    	   cursor = total;
       }
       else{
    	   cout<<"光标移动错误"<<endl;
       }
       cout<<"当前光标位置："<<cursor<<endl;
    }
	void addtext()// 在文档末尾添加文本
  {
    cout<<"追加文本:";
    string a;
    getline(cin,a);//接受a到cin中
    if(a!="")//若输入字符串不为空（不是回车）
    {
        if(line!=0)
        {
			article.tail->data+=a;//string类重载+
        }
        else
        {
            article.addfromback(a);//增加结点
            line++;
        }
        total+=a.length();
    }
    if(a=="")        //若以回车开头
    {
        getline(cin,a);
        article.addfromback(a);//重新建一个结点
        line++;
        total+=a.length();
    }
	movecursor(-1); //移动光标到最后
    }
	void inserttext()//在指定光标后插入文本
{
	int t;
	cout<<"设置光标：";
	cin>>t;
	if(t<=total&&t>=0){
		cursor = t;
	}else{
		cout<<"设置光标错误"<<endl;
	}
	int i;
	LinkNode<string>* p=article.line(0);//p指向第j个结点
	for(i=cursor;i>=0&&p!=NULL;){
		if((unsigned)i<= p->data.length()){
			break;
		}else{
			i-=p->data.length();
			p=p->next;
		}
	}
	string s;
	cout<<"请输入：";
	getchar();  //输入一个字符串
	getline(cin,s);
	p->data.insert(i,s);   //在光标处插入串s

}
	void deletetext()//有bug
	{
	int line,off,len;
    cout<<"删除位置行数：";
	cin>>line;
	cout<<"第几个字符:";
	cin>>off;
    int len_deleted = 0;
    cout<<"删除长度:";
    cin>>len;
	LinkNode<string>* p=article.line(line);//指向第j个结点
    if(len<0)
        len = 0;
	if(len>off)
	{
		cout<<"删除内容超过一行,只删除一行"<<endl;
		len=off;
	}
    if(len<=off)       //删除不超过一行
    {
		p->data.erase(off,len);//从起始位置开始删除规定长度
        len_deleted = len;
	}
    total -= len_deleted;
    movecursor(-1);
   }
	void findtext()//查找字符串，并将光标移动到子串开头
{
	int resline=0,resoff=0,flag=0;
    string s;
    cout<<"输入你想找的字符: ";
    cin>>s;
	LinkNode<string>* p=article.head;
    while(p!=NULL)
    {
		resoff = p->data.find(s);//int find(char c) const;//从pos开始查找字符c在当前字符串的位置
        if(resoff==string::npos)//当前行没找到
        {
			p=p->next;
            resline++;
        }
        else
		{
			cout<<"首次出现位置：";
			cout<<"行："<<resline<<"偏移："<<resoff<<endl;
			flag = 1;
            break;
		}
    }
   if(flag==0){     //没找到
	   cout<<"没找到"<<endl;
   }
}
	void count()
{

	int a1=0,a2=0,a3=0,a4=0,a5=0;//字母，数字，标点，空格，总数
	LinkNode<string>*p=article.head;
	for(;p!=NULL;p=p->next)
	{
		int n;
		n=p->data.length();
		a5+=n;
		for(int i=0;i<n;i++)
		{
			if((p->data[i]>=65&&p->data[i]<=90)||(p->data[i]>=97&&p->data[i]<=122))
			a1++;
			else if(p->data[i]>=48&&p->data[i]<=57)
			a2++;
			else if(p->data[i]==32)
			a4++;
			else
			a3++;
		}
	}
	cout<<"总字符个数为："<<a5<<endl;
	cout<<"字母个数为："<<a1<<endl;
	cout<<"数字个数为："<<a2<<endl;
	cout<<"标点个数为："<<a3<<endl;
	cout<<"空格个数为："<<a4<<endl;

}
	friend ostream& operator <<(ostream &out,TextEditor &t);
	friend istream& operator >>(istream &in,TextEditor & t);
	void init(){
		char c;
		do{
		cout<<"0.设置文档名字"<<endl;
		cout<<"1.获取文档名字"<<endl;
		cout<<"2.移动并显示光标"<<endl;
		cout<<"3.追加文本"<<endl;
		cout<<"4.当前位置插入文本"<<endl;
		cout<<"5.查找文本"<<endl;
		cout<<"6.删除文本"<<endl;
		cout<<"7.统计"<<endl;
		cout<<"8.显示文本"<<endl;
		int i = 100;
		cout<<"请输入序号：";
		cin>>i;
		switch(i){
		case 0:
			setname();
			break;
		case 1:
			cout<<getname()<<endl;
			break;
		case 2:
			{int i=0,j=0;
			cout<<"origin:";cin>>i;
			cout<<"offset:";cin>>j;
			movecursor(i,j);
			break;}
		case 3:
			addtext();
			break;
		case 4:
			inserttext();
			break;
		case 5:
			findtext();
			break;
		case 6:
			deletetext();
			break;
		case 7:
			count();
			break;
		case 8:
			cout<<*this<<endl;
			break;
		case 9:
			return;
		default:
			cout<<"序号错误"<<endl;
		}

		cout<<"是否继续（y/n）:";
		cin>>c;
		}while(c=='y');
		cout<<"结束"<<endl;
		return;
	}
};
ostream& operator <<(ostream& out, TextEditor& t)
{
	LinkNode<string> * p=t.article.head;
	for( ; p != NULL; p=p->next)
    {
		out<<p->data<<endl;
    }
    return out;
}

int main()
{
	TextEditor text;
	text.init();
	return 0;
}
