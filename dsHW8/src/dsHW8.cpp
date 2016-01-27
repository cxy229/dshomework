//============================================================================
// Name        : dsHW8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>        //定义一个模板  写双链表
class DoubleNode
{
public:
	T element;
	DoubleNode* prev;
	DoubleNode* next;
	DoubleNode(const T& theElement,DoubleNode* thePrev=NULL,DoubleNode* theNext=NULL)
		       :element(theElement),prev(thePrev),next(theNext) {}

};

	template<class T>
	class CircleDoubleLinkList          //双链表类的定义
	{
	private:
		DoubleNode<T>* head;           //链表头指针
		DoubleNode<T>* tail;           //链表尾指针
		int size;             //元素个数
		DoubleNode<T>* GetPointAt(int pos)
		{
			DoubleNode<T>* pNode=NULL;
			if (pos<=0 || pos>size)
				std::cout<<"out of range."<<std::endl;   //链表当前位置越界,异常
			else
			{
				pNode=head;            //当前位置满足条件,则一开始在链表头
				for (int i=1;i<=pos-1;++i)
					pNode=pNode->next;
			}
			return pNode;
		}
	public:
		CircleDoubleLinkList():head(),tail(),size(0) {}
		~CircleDoubleLinkList() {Clear();}
		void Clear()
			{
				const int nums=Size();
				if (!isempty())
				{
					for (int k=1;k<=nums;++k)
					{
						DoubleNode<T>* temp=head->next;
						delete head;
						head=temp;
						size--;
					}
				}
			}
		int Size() {return size;}        //返回元素个数
		bool isempty()  {return size==0?true:false; }  //返回链表是否为空
		int Find(T val)
		{
			int pos=1;    //从1号位，也就是链表首开始
			DoubleNode<T>* findNode=head;
			do
			{
				if (findNode->element==val)
					return pos;
				findNode=findNode->next;
				pos++;
			}
			while (findNode!=head);
			std::cout<<"we can't find it.return -1"<<std::endl;
			return -1;
		}
		void Print()
		{
			DoubleNode<T>* findNode=head;
			do
			{
				cout<<findNode->element<<" ";
				findNode=findNode->next;
			}
			while (findNode!=head);
			cout<<endl;
		}
		bool RemoveAt(int pos)
		{
			DoubleNode<T>* pNode=NULL;
			if (isempty())
			{
				cout<<"the link list is empty"<<endl;
				return false;
			}
			if (pos<=0 || pos>size)
			{
				cout<<"out of range"<<endl;
				return false;
			}
			if (size==1)
			{
				Clear();
			}
			if (pos==1)
			{
				pNode=head;
				head=head->next;
				head->prev=tail;
				tail->next=head;
				delete pNode;
			}
			else
			{
				DoubleNode<T>* pPreNode=GetPointAt(pos-1);
				pNode=pPreNode->next;
				if (pos==size)
				{
					pPreNode->next=head;
					tail=pPreNode;
					head->prev=tail;
					tail->next=head;
				}
				else
				{
					pPreNode->next=pNode->next;
					pNode->next->prev=pPreNode;
				}
				delete pNode;
			}
			size--;
			return true;
		}
		void AddBack(T val)
		{
			DoubleNode<T>* pNode=new DoubleNode<T>(val);
			if (isempty())
			{
				head=pNode;
				tail=pNode;
				tail->next=head;
				head->prev=tail;
			}
			else
			{
				tail->next=pNode;
				pNode->prev=tail;
				tail=pNode;
				tail->next=head;
				head->prev=tail;
			}
			size++;
		}
};

int main() {
	CircleDoubleLinkList<int> dll;
	dll.AddBack(1);dll.AddBack(2);dll.AddBack(3);dll.AddBack(4);dll.AddBack(5);dll.AddBack(6);
	dll.Print();
	dll.RemoveAt(dll.Find(4));
	dll.Print();
	return 0;
}
