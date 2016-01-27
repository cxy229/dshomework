/*
 * MinHeap.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <iostream>
using namespace std;

template<class T>
void Swap(T& a,T&b)
{
	T count;
	count=a;
	a=b;
	b=count;
}

template<class T>
class Minheap
{
	T *heap;
	int MaxSize;
	int n;
public:
	Minheap(int ms=0)
	{
		MaxSize=ms;
		heap=new T[ms];
		n=0;
	}
	bool build(T* a,int m)
	{
		int i;
		if(m>MaxSize)
			return false;
		else
		{
			for(i=0;i<m;i++)
				heap[i]=a[i];
			n=m;
			for(i=(n-2)/2;i>-1;i--)
				siftDown(i);
		}
		return true;
	}
	bool insert(T num)
	{
		if(n<MaxSize)
		{
			heap[n]=num;
			siftUp(n);
			n++;
			return true;
		}
		return false;
	}
	bool deleteMin(T& date)
	{
		if(n==0)
			return false;
		else
		{
			date=heap[0];
			heap[0]=heap[--n];
			siftDown(0);
			return true;
		}
	}
	bool deleteJ(int j,T &date)
	{
		if(j>=n&&n==0&&j<0)
			return false;
		else
		{
			date=heap[j];
			heap[j]=heap[--n];
			siftDown(j);
			return true;
		}
	}
	bool  isEmpty()
	{
		return n==0;
	}
	bool isLeaf(int pos)  //pos为节点个数
	{
		return pos>n/2;
	}
	void siftUp(int j)
	{
		while(j>-1)
		{
			if(heap[j]<heap[(j-1)/2])
			{
				Swap(heap[j],heap[(j-1)/2]);
				j=(j-1)/2;
			}
			else
				break;
		}
	}
	void siftDown(int j)//j为下标
	{
		int MinIn;
		while(!isLeaf(j+1))
		{
			if(2*j+2<n&&heap[2*j+1]>heap[2*j+2])
				MinIn=2*j+2;
			else
				MinIn=2*j+1;
			if(heap[j]>heap[MinIn])
			{
				Swap(heap[j],heap[MinIn]);
				j=MinIn;
			}
			else
				break;
		}
	}
	void show()
	{
		for(int i=0;i<n;i++)
			cout<<heap[i]<<endl;
	}
};



#endif /* MINHEAP_H_ */
