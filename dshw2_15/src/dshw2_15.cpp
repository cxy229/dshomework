//============================================================================
// Name        : dshw2_15.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
class CircleQueue{
private:
	int maxSize;
	int front;
	int rear;
	int tag;  //标记队列是否为空
	int *queue;
public:
	CircleQueue(int size){
		maxSize = size+1;
		queue = new T[maxSize];
		front = 0;
		rear = 0;
		tag = 0;
	}
	~CircleQueue(){
		delete [] queue;
	}
	void Clear(){
		front = rear;
	}
	bool empty(){
		if(tag==0){
			return true;
		}else{
			return false;
		}
	}
	bool push(const T item){
		if(tag==1 && front==rear){//队满
			cout<<"队列已满,上溢"<<endl;
			return false;
		}
		if(tag==0) tag=1;
		queue[rear] = item;
		rear = (rear+1)%maxSize;
		return true;
	}
	bool pop(){
		if(tag==0){
			cout<<"队列为空，下溢"<<endl;
			return false;
		}

		front = (front+1)%maxSize;
		if(front==rear) tag=0;
		return true;
	}
	T getFront(){
		if(tag==0){
				cout<<"队列为空"<<endl;
				return false;
			}
			return queue[front];
	}

};

int main() {
	CircleQueue<int> que(10);
	que.push(0);que.push(1);que.push(2);que.push(3);que.push(4);que.push(5);
	for(;!que.empty();){
		cout<<que.getFront()<<"  ";
		que.pop();
	}
	return 0;
}
