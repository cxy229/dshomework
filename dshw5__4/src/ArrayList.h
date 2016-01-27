/*
 * ArrayList.h
 *
 *  Created on: Dec 30, 2015
 *      Author: cxy229
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include"ContactInfor.h"
#include<string>
using namespace std;
class ArrayList
{
	friend ostream& operator<<(ostream& out, ArrayList& a);
private:
	ContactInfor* list;
	int maxsize;
	int cursize;
public:
	ArrayList();
	ArrayList(int size);
	~ArrayList();
	int length();
	int setSursize();//当前长度-1,subCursize()
	int maxlength();
	bool Insert(int pos, ContactInfor contact);
	int Search(string name1);
	ContactInfor operator[](int i);
};

ArrayList::ArrayList()
{
	maxsize = 100;
	cursize = 0;
	list = new ContactInfor[maxsize];
}

ArrayList::ArrayList(int size)
{
	maxsize = size;
	cursize = 0;
	list = new ContactInfor[maxsize];
}

ArrayList::~ArrayList()
{
	if (list)
		delete[]list;
}

ostream& operator<<(ostream& out, ArrayList& a)
{
	for (int i = 0; i < a.length(); i++)
		out << a.list[i] << endl;
	return out;
}

int ArrayList::length()
{
	return cursize;
}

int ArrayList::setSursize()
{
	cursize--;
	return cursize;
}

int ArrayList::maxlength()
{
	return maxsize;
}

bool ArrayList::Insert(int pos, ContactInfor contact)
{
	if (cursize == maxsize)
	{
		return false;
	}
	else
	{
		for (int i = cursize - 1; i >= pos; i--)
		{
			list[i + 1] = list[i];
		}
		list[pos] = contact;
		cursize++;
		return true;
	}
}

int ArrayList::Search(string name1)
{
	int i = length();
	int j = 0;
	while (j < i)
	{
		if (list[j].getName() == name1)
			return j;
		j++;
	}
	return -1;
}

ContactInfor  ArrayList::operator[](int i)
{
	return list[i];
}



#endif /* ARRAYLIST_H_ */
