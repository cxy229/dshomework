//============================================================================
// Name        : ArrayQueue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

template <class T>
class ArrayQueue
{
private:
	int maxSize;
	int front;
	int rear;
	T *queue;
public:
	ArrayQueue(int size){
		maxSize = size + 1;    // 多出一个空间  区分队列空与满
		queue = new T[maxSize];
		front = rear = 0;
	}
	~ArrayQueue(){
		delete [] queue;
	}
	void Clear(){
		front = rear;
	}
	bool EnQueue(const T item){    // item入队  插入队尾
		if((rear + 1) % maxSize == front){
			cout<<"队列已满."<<endl;
			return false;
		}
		queue[rear] = item;
		rear = (rear + 1) % maxSize;
		return true;
	}
	bool DeQueue(T & item){    //出队  赋给item
		if(front == rear + 1){
			cout<<"队列为空."<<endl;
			return false;
		}
		else{
			item = queue[front];
			front = (front + 1) % maxSize;
			return true;
		}
	}
	bool GetFront(T & item){ //获得队首值 但不出队
		if(front == rear){
			cout<<"队列为空."<<endl;
			return false;
		}
		else{
			item = queue[front];
			return true;
		}
	}
};

int main()
{
	return 0;
}
