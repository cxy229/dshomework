//============================================================================
// Name        : kmp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>

int KmpSearch(char* s, char* p) {
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	int next[20];
	next[0] = -1;
	int k = -1;
	while (j < pLen - 1) {                 //获得next数组
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k]) {
			++k;
			++j;
			next[j] = k;
		} else {
			k = next[k];
		}
	}

	while (i < sLen && j < pLen) {                       //匹配
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else {
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
			//next[j]即为j所对应的next值
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}
int main() {
	char *s = "bbc abcdab abcdabcdabde";
	char *p = "abcdabd";
	cout<<KmpSearch(s,p)<<endl;
	return 0;
}
