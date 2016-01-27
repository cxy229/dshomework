/*
 * HosPartNode.h
 *
 *  Created on: Dec 4, 2015
 *      Author: cxy229
 */

#ifndef HOSPARTNODE_H_
#define HOSPARTNODE_H_

#include<iostream>
#include<string>
using namespace std;

class HosPartNode
{
private:
	int num;//数量
	string name;//名字
public:
	HosPartNode(){
		num = 0;
	}
	HosPartNode(int n,string _name){
		num = n;
		name = _name;
	}
	string getName(){
		return name;
	}
	int getNum(){
		return num;
	}
	void setName(string na){
		name = na;
	}
	void setNum(int n){
		num = n;
	}
	friend ostream& operator<< (ostream &os,HosPartNode &node);
};

ostream& operator<< (ostream &os,HosPartNode &node)
{
	os<<node.getName()<<"   "<<node.getNum()<<endl;
	return os;
}



#endif /* HOSPARTNODE_H_ */
