/*
 * hCode.h
 *
 *  Created on: Dec 4, 2015
 *      Author: cxy229
 */

#ifndef HCODE_H_
#define HCODE_H_
#include <iostream>
using namespace std;
#include <string>

class HCode{
public:
	int colorLen;
	int maxLen;
	string code;

	HCode();//构造函数
	~HCode();//析构函数
	int GetCodeLen();
	bool GetCodeAt(int inidx);
//	void AddBit(int);
};




#endif /* HCODE_H_ */
