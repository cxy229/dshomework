//============================================================================
// Name        : dsHW5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
class LinkNode{
public:
	T data;
	LinkNode<T>* link;
	LinkNode(const T&el,LinkNode<T>* ptr = 0){
		data = el;
		link = ptr;
	}
};

template<class T>
class LinkList{
private:
	LinkNode<T> *head,*tail;
	LinkNode<T> *prevPtr,*currPtr;
	int position;
public:
	LinkList(){
		head = NULL;
		tail = NULL;
		prevPtr = NULL;
		currPtr = NULL;
		position = 0;
	}
	~LinkList(){
		Clear();
	}
	LinkNode<T>* getHead(){
		return head;
	}
	void setHead(LinkNode<T>* t){
			head = t;
		}
	void Print(){
		if(head == NULL){
			cout<<"link is empty"<<endl;
			return;
		}else{
			for(currPtr = head;currPtr!=NULL;){
				cout<<currPtr->data<<" ";
				prevPtr = currPtr;
				currPtr = prevPtr->link;
			}
			cout<<endl;
			return;
		}
	}
	void Clear(){
		if(head==NULL){
			return;
		}else{
			for(currPtr = head;currPtr!=NULL;){
					prevPtr = currPtr;
					currPtr = prevPtr->link;
					delete prevPtr;
				}
		}
	}
	LinkNode<T>* setPos(int pos){
		if(pos<=-1){
			return head;
		}
		int count = 0;
		LinkNode<T>* p = head->link;
		while(p!= NULL && count<pos){
			p = p->link;
			count++;
		}
		return p;
	}
//	bool insertPos(const int i,LinkNode<T>* item){
//		LinkNode<T> *p,*q;
//		if((p = setPos(i-1))==NULL){
//				cout<<"insert illegal"<<endl;
//				return false;
//		}
//		p
//
//		q = new LinkNode<T>(value,p->link);
//		p->link = q;
//		if(p == tail)
//			tail = q;
//		return true;
//	}
	void insertTail(const T value){
		LinkNode<T> *q;
		if(head == NULL){
			q = new LinkNode<T>(value,NULL);
			head = q;
			tail = q;
			return;
		}else if(tail == NULL){
			cout<<"illegal"<<endl;
			return;
		}else{
			q = new LinkNode<T>(value,NULL);
			tail->link = q;
			tail = q;
			return;
		}
	}
//	T getMax(){
//		if(head == NULL){
//			cout<<"list is empty"<<endl;
//			return 0;
//		}else{
//			T max;
//			currPtr = head;
//			max = head->data;
//			for(;currPtr!=NULL;){
//				if(max<(currPtr->data)){
//					max = currPtr->data;
//				}
//				currPtr = currPtr->link;
//			}
//			return max;
//		}
//	}
	int len(){
		int len=0;
		currPtr = head;
		for(;currPtr!=NULL;){
			len++;
			currPtr = currPtr->link;
		}
		return len;
	}
	void reverse(){
			if(head==NULL){
				return;
			}else{
				prevPtr = NULL;
				currPtr = head;
				LinkNode<T> *t,*tt;
				tt = head;
				for(;currPtr!=NULL;){
					t = currPtr->link;
					currPtr->link = prevPtr;
					prevPtr = currPtr;
					currPtr = t;
				}
				head = tail;
				tail = tt;
			}
		}
};
template<class T>
LinkNode<T>* merge(LinkList<T>* a,LinkList<T>* b){
	a->reverse();b->reverse();
	LinkNode<T>* aptr,*bptr,*t,*apreptr=NULL;
	aptr = a->getHead();
	bptr = b->getHead();
	int flag = 0;
	for(;bptr!=NULL;){
		if(aptr==NULL){
			aptr = bptr;
			bptr = bptr->link;
			aptr = NULL;
			continue;
		}
		if(aptr->data > bptr->data){
			flag++;
			for(;;){
				apreptr = aptr;
				aptr = aptr->link;
				if(aptr==NULL){
					aptr = bptr;
					bptr = bptr->link;
					aptr = NULL;
					break;
				}
				if(aptr->data < bptr->data){
					t = bptr;
					bptr = bptr->link;
					apreptr->link = t;
					t->link = aptr;
					apreptr = t;
					break;
				}
			}
		}else if(flag==0){
			a->setHead(b->getHead());
			bptr = bptr->link;
			t = a->getHead();
			t->link = aptr;
			flag++;
		}else{
			apreptr->link = bptr;
			t = bptr;
			bptr = bptr->link;
			t->link = aptr;
			apreptr = bptr;
		}
	}
	return a->getHead();
}
int main() {
	LinkList<int> linkA,linkB,linkC;
	linkA.insertTail(0);linkA.insertTail(1);linkA.insertTail(2);linkA.insertTail(3);linkA.insertTail(7);
	linkB.insertTail(5);linkB.insertTail(6);//linkB.insertTail(2);linkB.insertTail(3);linkB.insertTail(7);
	linkA.Print();
	linkB.Print();
	merge(&linkA,&linkB);
	linkA.Print();
	return 0;
}
