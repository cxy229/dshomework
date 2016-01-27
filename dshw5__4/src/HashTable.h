/*
 * HashTable.h
 *
 *  Created on: Dec 30, 2015
 *      Author: cxy229
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include"ContactInfor.h"
#include <iostream>
using namespace std;
class HashTable
{
private:
	int* HS;
	int maxsize;
	int cursize;
	int hash(int key);//用来算散列后的值
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	int operator[](int i);
	bool hashInsert(ContactInfor key);
	int hashSearch(string name1);
	bool hashDelete(ContactInfor key);
};

HashTable::HashTable()
{
	maxsize = 100;
	cursize = 0;
	HS = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
		HS[i] = 0;//用于判断数组元素是否为空,0表示空,否则不空
}


HashTable::~HashTable()
{
	if (HS)
		delete[] HS;
}

HashTable::HashTable(int size)
{
	maxsize = size;
	cursize = 0;
	HS = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
		HS[i] = 0;
}

int HashTable::hash(int key)
{
	return key % maxsize;//求余法
}

int HashTable::operator[](int i)
{
	return HS[i];
}

bool HashTable::hashInsert(ContactInfor key)
{
	if (cursize == maxsize)
		return false;
	else
	{
		int pos =hash( key.getKey());//该数值本应在的位置下标
		while (HS[pos] != 0)
		{
			if (HS[pos] == key.getKey())
			{
				cout << "数据重复" << endl;
				return false;
			}
			pos++;
			if (pos > maxsize - 1)
				pos = 0;//散列表是循环的，可以由最后又一个+1调到第一个
		}
		HS[pos] = key.getKey();
		cursize++;
		return true;
	}
}

int HashTable::hashSearch(string name1)
{
	string nm = name1;
	int l = nm.length();
	int sum = 0;
	for (int i = 0; i < l; i++)
	{
		sum = sum + (int)nm[i];
	}
	int pos = hash(sum);//该数值本应在的位置下标
	while (HS[pos] != 0)
	{
		if (HS[pos] == sum)
			return pos;
		pos++;
		if (pos > maxsize - 1)
			pos = 0;
	}
	cout << sum << "不存在" << endl;
	return -1;
}

bool HashTable::hashDelete(ContactInfor key)
{
	int pos = hash(key.getKey());//该数值本应在的位置下标
	while (HS[pos] != 0)
	{
		if (HS[pos] == key.getKey())
		{
			HS[pos] = 0;
			cursize--;
			return true;
		}
		pos++;
		if (pos > maxsize - 1)
			pos = 0;
	}
	cout << key.getKey() << "不存在,无法删除" << endl;
	return false;
}



#endif /* HASHTABLE_H_ */
