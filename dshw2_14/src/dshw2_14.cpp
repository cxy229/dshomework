//============================================================================
// Name        : dshw2_14.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#include<stdio.h>

template <class T>
class LinkNode  //  节点
{
public:
	T data;    // 数据域
	LinkNode<T> *link;   //  指向后继节点的指针
	LinkNode(const T&el = 0,LinkNode<T> *ptr = 0){  // 构造函数
		data = el;
		link = ptr;
	}
};

template <class T>
class LinkQueue
{
private:
	int size;  // 队列中当前元素的个数
	LinkNode<T> * front;   // 队列的头指针
	LinkNode<T> * rear;    // 队列的尾指针
public:
	LinkQueue(){
		size = 0;
		front = rear = NULL;
	}
	~LinkQueue(){
		Clear();
	}
	bool IsEmpty(){
		if(front == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	void Clear(){
		while(front != NULL){
			rear = front;
			front = front->link;
			delete rear;
		}
		rear = NULL;
		size = 0;
	}
	bool EnQueue(const T item){     // item入队  插入队尾
		if(rear == NULL){
			front =  rear = new LinkNode<T>(item, NULL);
		}
		else{
			rear->link = new LinkNode<T>(item, NULL);
			rear = rear->link;
		}
		size++;
		return true;
	}
	T DeQueue(){
		T  item;
		LinkNode<T> * temp;
		if(size == 0){
			cout<<"队列为空."<<endl;
			return false;
		}
		else{
			item = front->data;
			temp = front;
			front = front->link;
			delete temp;
			if(front == NULL){
				rear = NULL;
			}
			size--;
			return item;
		}
	}
	T GetFront(){
		T  item;
		if(size == 0){
			cout<<"队列为空."<<endl;
			return false;
		}
		else{
			item = front->data;
			return item;
		}
	}
};

int main()
{
	cout<<"请输入n个0和9之间的数字 ： "<<endl;
	LinkQueue<int> Queue[10];
	LinkQueue<int> Queue_ALL;
	int i;
	do{                               //输入
		cin>>i;
		Queue[i].EnQueue(i);
	}while(getchar() != '\n');
	for(i = 0;i <= 9;i++){                //连接为一个队列
		if(!Queue[i].IsEmpty()){
			while(!Queue[i].IsEmpty()){
				Queue_ALL.EnQueue(Queue[i].DeQueue());
			}
		}
	}

	while(!Queue_ALL.IsEmpty()){           //输出
		cout<<Queue_ALL.DeQueue()<<"  ";
	}
	cout<<endl;
	return 0;
}
