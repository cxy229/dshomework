//============================================================================
// Name        : dsHW3.cpp
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

int main() {
	LinkList<int> link;
	link.insertTail(0);link.insertTail(1);link.insertTail(2);link.insertTail(3);link.insertTail(4);
	link.Print();
	link.reverse();
	link.Print();
	return 0;
}
