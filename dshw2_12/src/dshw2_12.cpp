//============================================================================
// Name        : dshw2_12.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<stack>

void converse(int n){
	stack<int> res;
	for(int i=2;i<=9;i++){
		int tn = n;
		for(;tn!=0;){
			res.push(tn%i);
			tn = tn/i;
		}
		cout<<"转为"<<i<<"进制:";
		for(;!res.empty();){
			cout<<res.top();
			res.pop();
		}
		cout<<endl;
	}

}

int main() {
	converse(9);
	return 0;
}
