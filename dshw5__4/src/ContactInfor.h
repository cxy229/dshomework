/*
 * ContactInfor.h
 *
 *  Created on: Dec 30, 2015
 *      Author: cxy229
 */

#ifndef CONTACTINFOR_H_
#define CONTACTINFOR_H_


#include<iostream>
#include<string>
using namespace std;

class ContactInfor
{
	friend ostream& operator<<(ostream& out, ContactInfor& c);
public:
	string name;
	string phoneNum;
	string email;
public:
	ContactInfor(){}
	ContactInfor(string n,string p,string e);
	~ContactInfor(){}
	string getName();
	string getphoneNum();
	string getemail();
	//void setphoneNum(string p);
	//void setemail(string e);
	int getKey();
	bool empty();
	bool operator==(ContactInfor& c);
	bool operator<(ContactInfor& c);
};
ostream& operator<<(ostream& out, ContactInfor& c)
{
	out << c.name << " " << c.phoneNum << " " << c.email << endl;
	return out;
}
ContactInfor::ContactInfor(string n, string p, string e)
{
	name = n;
	phoneNum = p;
	email = e;
}
string ContactInfor::getName()
{
	return name;
}
string ContactInfor::getphoneNum()
{
	return phoneNum;
}
string ContactInfor::getemail()
{
	return email;
}
/*void ContactInfor::setphoneNum(string p)
{
	phoneNum = p;
}
void ContactInfor::setemail(string e)
{
	email = e;
}*/
int ContactInfor::getKey()
{//键值是名字所有字母ASCII码的和
	string nm = name;
	int l = nm.length();
	int sum = 0;
	for (int i = 0; i < l; i++)
	{
		sum = sum + (int)nm[i];
	}
	return sum;
}
bool ContactInfor::empty()
{
	if (name.empty())
		return true;
	return false;

}
bool ContactInfor::operator==(ContactInfor& c)
{
	if (name == c.name&&phoneNum == c.phoneNum&&email == c.email)
		return true;
	return false;
}
bool ContactInfor::operator<(ContactInfor& c)
{
	if (name < c.name)
		return true;
	return false;
}


#endif /* CONTACTINFOR_H_ */
