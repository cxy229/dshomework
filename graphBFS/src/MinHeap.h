/*
 * MinHeap.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#pragma once
#include"Graph.h"
class MinHeap
{
private:
	Edge* heap;//存放堆元素
	int cursize;//当前数组最大下标
	int maxsize;//数组允许元素最大下标
public:
	MinHeap();
	MinHeap(int maxsize);
	bool Heap(Edge a[], int num);//建堆,传入数组及其元素最大下标
	void shiftdown(int i);//向下建堆
	~MinHeap();
	bool insert(Edge e);
	void shiftup(int i);//向上建堆
	Edge delroot();//删除堆顶元素
	bool isEmpty();
	void print();//输出堆里所有值
};



#endif /* MINHEAP_H_ */
