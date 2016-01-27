//============================================================================
// Name        : dshw18.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>

int search(char* t,char* p){
	int tlen = strlen(t);
	int plen = strlen(p);
	int ti = tlen-1;
	int pi = plen-1;
	if(tlen<plen){return -1;}  //目标比模式还短
	for(;ti>=0 && pi>=0;){    //从尾部开始匹配
		if(t[ti]==p[pi]){
			ti--;
			pi--;
		}else{
			ti = ti+plen-pi-2;
			pi = plen-1;
		}
	}
	if(pi==-1){
		return ti+1;
	}else{
		return -1;
	}
}
int main() {
	char *str = "abcabcabcdabde";
	char *substr = "abc";
	cout<<search(str,substr)<<endl;
	return 0;
}
