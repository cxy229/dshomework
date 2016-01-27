//============================================================================
// Name        : LinkList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>

template <class T>
class LinkNode
{
public:
	T data;
	LinkNode<T> *link;
	LinkNode(const T&el = 0,LinkNode<T> *ptr = 0){
		data = el;
		link = ptr;
	}
};

template <class T>
class LinkList{
private:
	int count;
	LinkNode<T> *head, *tail;  // 表头和表尾指针
	LinkNode<T> *prevPtr, *currPtr;   //  记录表当前遍历位置的指针，由插入和删除操作更新
public:
 	LinkList<T>(){
 		prevPtr = NULL;
 		currPtr = NULL;
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void add(const T value);
	void creat();   //   创造链表
	void show();     // 显示链表
	bool insertPos(const int pos,const T value);  //在pos处插入
	LinkNode<T>* setPos(int pos);  // 返回指定位置pos的指针
	int getSize();   // 链表中的节点个数
};
template <class T>
int LinkList<T>::getSize()
{
	return count;
}

template <class T>
void LinkList<T>::add(const T value)
{
	count++;
	LinkNode<T> *p;
	if(head == NULL){
		head = new LinkNode<T>;  // 头结点
		head->link = NULL;
		tail = head;        //  尾指针指向头结点

		p = new LinkNode<T>;        //生成新节点
		p->data = value;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
	}
	else{
		p = new LinkNode<T>;        //生成新节点
		p->data = value;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
	}
}
template <class T>
bool LinkList<T>::insertPos(const int pos, const T value)
{
	LinkNode<T> *p,*q;
	if((p = setPos(pos-1))  == NULL){   // p是第i个节点的前驱
		cout<<"插入操作不允许"<<endl;
		return false;
	}
	q = new LinkNode<T>(value,p->link);
	p->link = q;
	if(p == tail){
		tail = q;    //  在表尾进行插入操作
	}
	count++;
	return true;
}
template <class T>
LinkNode<T> * LinkList<T>::setPos(int pos)
{
	if(pos == -1){  //  i为-1则定位到头结点
		return false;
	}
	int count = 0;
	LinkNode<T> *p = head->link;
	while(p != NULL && count < pos){
		p = p->link;
		count++;
	}
	return p;   //  指向第i个节点， 当链表长度小于i时返回NULL
}

template <class T>
void LinkList<T>::creat()
{
	head = new LinkNode<T>;  // 头结点
	head->link = NULL;
	tail = head;        //  尾指针指向头结点
	T i;
	LinkNode<T> *p;
	do{
		cin>>i;
		count++;
		p = new LinkNode<T>;        //生成新节点
		p->data = i;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
    }while(getchar() != '\n');
	tail->link = NULL;    //尾节点下一个指向为NULL
}
template <class T>
void LinkList<T>::show()
{
	LinkNode<T> *p = head;
	if(head->link == NULL){
        cout<<"无任何数据,请创建链表"<<endl;
        creat();
    }
    else{
		p = p->link;     //跳过头结点
		cout<<"show： ";
    do{
        cout<<p->data<<"  ";
        p = p->link;
        }while(p != NULL);
    cout<<endl;
    }
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
