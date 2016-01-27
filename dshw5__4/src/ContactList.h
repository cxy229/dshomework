/*
 * ContactList.h
 *
 *  Created on: Dec 30, 2015
 *      Author: cxy229
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#include"ArrayList.h"
#include"HashTable.h"
#include"ContactInfor.h"
#include<string>
using namespace std;
class ContactList
{
private:
	ArrayList contacts;
	HashTable contactsTable;
	int blockInfor[26][2];//存放分块查找中块的起点和终点
public:
	ContactList();
	ContactList(int size);
	~ContactList();
	bool addContact(string name1,string phonenum1,string email1);
	bool updateContact(string name1, string phonenum1, string email1);
	bool delContact(string name1);
	int blockQuery(string name1);//分块查询
	int Search(string name1,int start,int end);
	int hashQuery(string name1);//散列查询
	void showList();
};

ContactList::ContactList():contacts(100), contactsTable(100)
{
}

ContactList::ContactList(int size) :contacts(size), contactsTable(size)
{
}

ContactList::~ContactList()
{
}

bool ContactList::addContact(string name1, string phonenum1, string email1)
{
	if (contacts.length()==contacts.maxlength())
	{
		cout << "通讯录已满" << endl;
		return false;
	}
	else
	{
		int pos = 0;//插入位置
		ContactInfor contact(name1, phonenum1, email1);
		//先找到加入位置
		while (pos < contacts.length())
		{
			if (contacts[pos].getName() < name1)
				pos++;
			else if (contacts[pos].getName() == name1)
			{
				cout << "此联系人已存在" << endl;
				return false;
			}
			else//此时已找到插入位置（需要移动后面的联系人信息）
			{
				contacts.Insert(pos, contact);
				cout << "showList():" << endl;
				showList();
				return true;
			}
		}
		//不需要移动后面的联系人信息
		contacts.Insert(pos, contact);
		cout << "showList():" << endl;
		showList();
		return true;
	}
}

bool ContactList::updateContact(string name1, string phonenum1, string email1)
{
	//先找到联系人所在位置
	int i=contacts.Search(name1);
	if (i != -1)//存在此联系人
	{/*
		//contacts[i].setphoneNum(phonenum1);
		//contacts[i].setemail(email1);
		contacts[i].phoneNum = phonenum1;
		cout << contacts[i].email << endl;
		contacts[i].email = email1;
		cout << contacts[i].email << endl;
		cout << email1 << endl;
		cout << "showList():" << endl;
		showList();*/
		//若存在此联系人，则先删除再加入
		delContact(name1);
		addContact(name1, phonenum1, email1);
		return true;
	}
	else
	{//联系人不存在时把它加入到列表中
		cout << "此联系人不存在" << endl;
		addContact(name1, phonenum1, email1);
		return false;
	}
}

bool ContactList::delContact(string name1)
{
	int i = contacts.Search(name1);
	int j = contacts.length();
	if (i != -1&&i<j-1)//存在此联系人&&不在列表最后位子
	{//后面联系人依次前移
		for (int k = i; k < j - 1; k++)
		{
			contacts[k] = contacts[k + 1];
		}
		cout << "showList():" << endl;
		showList();
		return true;
	}
	if (i == j - 1)//在列表最后位子
	{//当前长度-1即可
		contacts.setSursize();
		cout << "showList():" << endl;
		showList();
		return true;
	}
	return false;
}

int ContactList::blockQuery(string name1)
{
	//建立索引表
	int start = 0;
	int end = 0;//下标
	int i = 97;//小写字母a的ASCII值
	int I = 65;//大写字母A的ASCII值
	for (int j = 0; j < 26; j++)
	{
		if (i < 123 || I < 91)
		{
			while ((int)contacts[end].getName()[0] == i)//首字母是a的话则++
				end++;
			while ((int)contacts[end].getName()[0] == I)//首字母是A的话则++
				end++;
			blockInfor[j][0] = start;
			blockInfor[j][1] = end - 1;//end<start说明没有与该首字母对应的联系人
			start = end;
			i++;
			I++;
		}
	}
	//折半查找
	int k = 0;
	if ((int)name1[0] < 97)
		k = (int)name1[0] - 65;//该字母对应的散列表中的位置
	else
		k = (int)name1[0] - 97;
	int low = blockInfor[k][0];//最小下标
	int high = blockInfor[k][1];//最大下标
	int r=Search(name1, low, high);
	return r;
}

int ContactList::Search(string name1, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;//中间节点下标
		if (contacts[mid].getName() == name1)//找到该联系人
		{
			return mid;
		}
		else if (contacts[mid].getName() < name1)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << "contacts 数组中不存在" << name1 << endl;
	return -1;
}

int ContactList::hashQuery(string name1)
{
	//首先将ArrayList中的联系人复制到contactsTable中即依次插入
	int i = contacts.length();
	int j = 0;
	while (j<i)
	{
		contactsTable.hashInsert(contacts[j]);
		j++;
	}
	//查找
	int h=contactsTable.hashSearch(name1);
	return h;
}

void ContactList::showList()
{
	cout << contacts << endl;
}




#endif /* CONTACTLIST_H_ */
