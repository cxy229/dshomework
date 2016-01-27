//============================================================================
// Name        : ArrayStack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

template <class T>
class ArrayStack
{
private:
	int maxSize;
	int top;
	T *st;
public:
	ArrayStack(int size){
		maxSize = size;
		top = -1;
		st = new T[maxSize];
	}
	ArrayStack(){
		maxSize = 0;
		st = NULL;
		top = -1;
	}
	~ArrayStack(){
		delete [] st;
	}
	void clear(){     //  清空栈的内容
		top = -1;
	}
	bool Push(const T item){       //　入栈
		if(top == maxSize -1){
			cout<<"栈满溢出。"<<endl;
			return false;
		}
		else{
			st[++top] = item;
			return true;
		}
	}
	bool Pop(T & item){           // 出栈
		if(top == -1){
			cout<<"栈为空."<<endl;
			return false;
		}
		else{
			item = st[top--];
			return true;
		}
	}
	bool Top(T & item){          // 读取栈顶元素 但不删除
		if(top == -1){
			cout<<"栈为空."<<endl;
			return false;
		}
		else{
			item = st[top];
			return true;
		}
	}
};

int main()
{
	return 0;
}
