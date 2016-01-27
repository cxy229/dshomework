
#include <iostream>
using namespace std;

template<class T>        //再定义一个模板  写双链表
class DoubleNode
{
public:
	T element;
	DoubleNode* prev;
	DoubleNode* next;
	DoubleNode(const T& theElement,DoubleNode* thePrev=NULL,DoubleNode* theNext=NULL)
		       :element(theElement),prev(thePrev),next(theNext) {}
	//这里已经创建了一个双链表
};

template<class T>
class DoubleLinkList
{
private:
	DoubleNode<T>* head;
	DoubleNode<T>* tail;
	DoubleNode<T>* currPtr,*prevPtr;
	int size;
public:
	DoubleLinkList():head(),tail(),size(0) {}
	~DoubleLinkList() {Clear();}
	int Size() {return size;}   //返回元素个数
	bool isempty() {return size==0?true:false; }
	DoubleNode<T>* getTail(){return tail;}
	void Clear()
	{
		//从链表头到链表尾的方式逐个删除
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
		//如果链表本来就为空，就没必要再进for循环了
	}
	DoubleNode<T>* GetPointAt(int pos)
	{
		DoubleNode<T>* pNode=NULL;
		if (pos<=0 || pos>size)
			std::cout<<"out of range"<<std::endl;
		else
		{
			pNode=head;
			for (int i=1;i<=pos-1;++i)
				pNode=pNode->next;
		}
		return pNode;
	}
	void Print(){
			if(head == NULL){
				cout<<"link is empty"<<endl;
				return;
			}else{
				for(currPtr = head;currPtr!=NULL;){
					cout<<currPtr->element<<" ";
					prevPtr = currPtr;
					currPtr = prevPtr->next;
				}
				cout<<endl;
				return;
			}
		}
	void AddBack(T val)
		{
			DoubleNode<T>* pNode=new DoubleNode<T>(val);
			if (isempty())
			{
				head=pNode;
				tail=pNode;
			}
			else
			{
				tail->next=pNode;
				pNode->prev=tail;
				tail=pNode;
			}
			size++;
		}
	bool RemoveAt(int pos)
		{
			DoubleNode<T>* pNode=NULL;
			if (isempty())
			{
				std::cout<<"the link list is empty"<<std::endl;
				return false;
			}
			if (pos<=0 || pos>size)
			{
				std::cout<<"out of range"<<std::endl;
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
				head->prev=NULL;
				delete pNode;
			}
			else
			{
				DoubleNode<T>* pPreNode=GetPointAt(pos-1);
				pNode=pPreNode->next;
				if (pos==size)
				{
					pPreNode->next=NULL;
					tail=pPreNode;
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
};
template<class T>
void change(DoubleLinkList<T>* dllptr){
	int len = dllptr->Size();
	DoubleNode<T> *tptr = dllptr->getTail();
	T tt;
	for(;len>1;len--){
		if(len%2==0){
			tt=tptr->element;
			tptr = tptr->prev;
			dllptr->RemoveAt(len);
			dllptr->AddBack(tt);
		}else{
			tptr = tptr->prev;
		}

	}
}
int main() {
	DoubleLinkList<int> dll;
	dll.AddBack(1);dll.AddBack(2);dll.AddBack(3);dll.AddBack(4);dll.AddBack(5);dll.AddBack(6);
	dll.Print();
	change(&dll);
	dll.Print();
	return 0;
}
