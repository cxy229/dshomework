/*
 * intqueue.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef INTQUEUE_H_
#define INTQUEUE_H_

#include<iostream>
using namespace std;

class IntQueue
{
	int maxSize;
	int front;
	int rear;
	int *queue;
	int tag;
public:
	IntQueue(int size)
	{
		maxSize=size+1;
		queue=new int[maxSize];
		front=0;
		rear=1;
		tag=0;
	}
	IntQueue()
	{
		tag = 0;
		maxSize=front=rear=0;
		queue=0;
	}
	~IntQueue()
	{
		delete [] queue;
	}
	void makesize(int size)
	{
		maxSize=size+1;
		queue=new int[maxSize];
		front=0;
		rear=1;
		tag=0;
	}
	bool Getqueue()
	{
		if(queue==0)
			return true;
		else
			return false;
	}

	void Clear()
	{
		tag=0;
		front=0;
		rear=1;
	}

	bool EnQueue(int item)
	{
		if(rear==front)
		{
			cout<<"Queue is FULL"<<endl;
			return false;
		}
		tag=1;
		if(rear!=0)
			queue[rear-1]=item;
		else if(rear==0)
			queue[maxSize-1]=item;
		rear=(rear+1)%maxSize;
		return true;
	}

	bool DeQueue(int& item)
	{
		if(tag==0)
		{
			cout<<"Queue is Empty"<<endl;
			return false;
		}
		item=queue[front];
		front =(front+1)%maxSize;
		if(rear-front==1||front-rear==maxSize-1)
			tag=0;
		return true;
	}
	bool GetFront(int item)
	{
		if(tag==0)
		{
			cout<<"Queue is Empty"<<endl;
			return false;
		}
		item=queue[front];
		return true;
	}
	bool IsEmpty()
	{
		if(tag==0)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if(front==rear)
			return true;
		else
			return false;
	}
};



#endif /* INTQUEUE_H_ */
