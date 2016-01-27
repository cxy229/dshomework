//============================================================================
// Name        : dshw17.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int Strcmp(char* s1, char* s2) {  //相等返回0 s1大返回1 s2大返回-1
	int count = 0;
	while (s1[count] != '\0' && s2[count] != '\0') {
		if (s1[count] > s2[count]) {
			return 1;
		} else if (s1[count] < s2[count]) {
			return -1;
		}
		count++;
	}
	if (s1[count] == '\0' && s2[count] != '\0') {
		return -1;
	} else if (s1[count] != '\0' && s2[count] == '\0') {
		return 1;
	}
	return 0;
}
int main() {
	char* s = "abcdefgh";
	char* t = "abcdeghf";
	if(Strcmp(s,t)==0){
		cout<<"s=t"<<endl;
	}else if(Strcmp(s,t)==1){
		cout<<"s>t"<<endl;
	}else{
		cout<<"s<t"<<endl;
	}
	return 0;
}
