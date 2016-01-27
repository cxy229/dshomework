#include "MinHeap.h"
#include<iostream>
using namespace std;

MinHeap::MinHeap()
{
	heap = new Edge[maxsize];
	cursize = 0;
	maxsize = 100;
}

MinHeap::MinHeap(int maxsize)
{
	this->maxsize = maxsize;
	cursize = 0;
	heap = new Edge[maxsize];
}

//建堆,传入数组及其元素最大下标
bool MinHeap::Heap(Edge a[], int num)
{
	//cout << "Heap:" << endl;
	//如果传入的数组元素比堆数组最大值大，则无法建堆
	if (num > maxsize)
		return false;
	//把传入的数组依次赋至堆数组
	for (int i = 0; i <= num; i++)
		heap[i] = a[i];
	cursize = num;
	//由最后一个有孩子节点的结点开始依次向上建堆
	for (int j = (cursize - 1) / 2; j >= 0; j--)
		shiftdown(j);//确保以此节点为根节点的树为最小堆
//	print();
	return true;
}

//确保以此节点为根节点的树为最小堆
void MinHeap::shiftdown(int i)
{
	cout << "shiftdown(0):" << endl;
	print();
	int k = 2 * i + 1;//左孩子下标
	Edge temp = heap[i];//保存父节点
	while (i <= (cursize - 1) / 2)
	{
		//如果此节点的右孩子存在且比左孩子小
		if (k + 1 <= cursize&&heap[k + 1] < heap[k])
			k++;
		if (temp>heap[k])//父节点值大于孩子节点最小的那个,交换值
		{
			heap[i] = heap[k];
			i = k;
			k = 2 * k + 1;
		}
		else
			break;
	}
	heap[i] = temp;
	cout << "shiftdown(0)(0):" << endl;
	print();
}

MinHeap::~MinHeap()
{
	//if (heap)
	//delete heap;
}

bool MinHeap::insert(Edge e)
{
	//cout << "insert:" << endl;
	if (cursize > maxsize)
	{
		cout << "堆已满，无法插入！" << endl;
		return false;
	}
	heap[cursize] = e;
	cursize++;
	for (int h = cursize-1; h > 0; h--)
		shiftup(h);
//	print();
	return true;
}

//向上调整
void MinHeap::shiftup(int i)
{
	int h = (i - 1) / 2;//父节点下标
	Edge temp = heap[i];//记录元素值
	while (i > 0)
	{//此节点值小于父节点，交换
		if (temp < heap[h])
		{
			heap[i] = heap[h];
			i = h;
			h = (i - 1) / 2;
		}
		else
			break;
	}
	heap[i] = temp;
}

//删除堆顶元素
Edge MinHeap::delroot()
{
//	cout << "delroot:" << endl;
	Edge i = heap[0];
//	cout << "delroot:" << i << endl;
	//把树的最后一个元素值赋至树根
	heap[0] = heap[cursize];
	cursize--;
	//向下保证是最小堆
	shiftdown(0);
	return i;
}

bool MinHeap::isEmpty()
{
	if (cursize < 0)
		return true;
	return false;
}

//输出堆里所有值
void MinHeap::print()
{
	for (int i = 0; i < cursize; i++)
		cout << heap[i] << " ";
	cout << endl;
}
