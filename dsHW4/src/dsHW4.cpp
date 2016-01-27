
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
//	int len(){
//		int len=0;
//		currPtr = head;
//		for(;currPtr!=NULL;){
//			len++;
//			currPtr = currPtr->link;
//		}
//		return len;
//	}
};
int getMax(const LinkNode<int>* p,int flag=0,int max=0){

	if (flag == 0){
		max = p->data;
		return getMax(p->link,1,max);
	}
	if(p == NULL){
		return max;
	}
	if(max<p->data){
		max = p->data;
	}
	return getMax(p->link,1,max);
}
int getLen(const LinkNode<int>* p,int len=0){
	if(p == NULL){
		return len;
	}
	len++;
	return getLen(p->link,len);
}
int getSum(const LinkNode<int>* p,int sum=0){
	if(p == NULL){
		return sum;
	}
	sum += p->data;
	return getSum(p->link,sum);
}
float getAve(const LinkNode<int>* p){
	int len = getLen(p);
	if(len <=0){
		return 0;
	}else{
		return getSum(p)/(len*1.0);
	}
}
int main() {
	LinkList<int> link;
	link.insertTail(0);link.insertTail(1);link.insertTail(2);link.insertTail(100);link.insertTail(4);
	link.Print();
	cout<<"最大值:"<<getMax(link.getHead())<<endl;
	cout<<"结点个数:"<<getLen(link.getHead())<<endl;
	cout<<"平均值:"<<getAve(link.getHead())<<endl;
	return 0;
}
