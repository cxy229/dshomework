//============================================================================
// Name        : datastructHW.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class List{};

template <class T>
class ArrayList:public List<T>
{
public:
	ArrayList(const int size){
		maxSize = size;
		arrayList = new T[maxSize];
		curLen = 0;
		position = 0;
	}
	~ArrayList(){
		delete []arrayList;
	}
	bool Append(const T value){
		if(curLen+1<=maxSize){
			arrayList[curLen] = value;
			curLen++;
			return true;
		}else{
			return false;
		}
	}
	void Print(){
		if(curLen==0){
			cout<<"None";
		}
		for(int i=0;i<curLen;i++){
			cout<<arrayList[i]<<" ";
		}
		cout<<endl;
	}
	T delMin(){
		if(curLen>0){
			T min = arrayList[0];
			for(int i=0;i<curLen;i++){
				if (min>arrayList[i]){
					min = arrayList[i];
				}
			}
			for(int i = 0;i<curLen;i++){
				if (arrayList[i]==min){
					arrayList[i]=arrayList[curLen-1];
					curLen--;
					i--;
				}
			}
			return min;
		}else{
			cout<<"The list is empty!"<<endl;
			return 0;
		}
	}
	bool Delete(const int p){
		if(curLen <= 0){
			cout<<"list empty"<<endl;
			return false;
		}
		if(p<0||p>curLen-1){
			cout<<"Delete is illegal"<<endl;
			return false;
		}
		for(int i=p;i<curLen-1;i++){
			arrayList[i]=arrayList[i+1];
		}
		curLen--;
		return true;
	}
	bool deleteValue(const T value){
		if(curLen <= 0){
			return false;
		}else{
			for(int i = 0;i<curLen;i++){
				if(arrayList[i]==value){
					Delete(i);
					i--;
				}
			}
			return true;
		}
	}
	bool deleteRange(const T min,const T max){
		if(curLen <= 0){
					return false;
			}else{
					for(int i = 0;i<curLen;i++){
						if(arrayList[i]>=min && arrayList[i]<=max){
							Delete(i);
							i--;
						}
					}
					return true;
			}
	}
private:
	T *arrayList;
	int maxSize;
	int curLen;
	int position;
};

int main() {
	ArrayList<int> a(20);
	a.Append(1);a.Append(2);a.Append(0);a.Append(0);a.Append(1);
	a.Print();
//	a.delMin();//1
//	a.deleteValue(0);//2
	a.deleteRange(0,1);
	a.Print();
	return 0;
}
