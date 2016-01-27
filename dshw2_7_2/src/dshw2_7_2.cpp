//============================================================================
// Name        : dshw2_7_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <queue>
#define Time 12
#define ArrayTime 2
#define ServeTime 4
template <class T>
class LinkNode
{
public:
	T data;
	LinkNode<T> *link;
	LinkNode(const T&el = 0,LinkNode<T> *ptr = 0){
		data = el;
		link = ptr;
	}
};

template <class T>
class LinkList{
private:
	int count;
	LinkNode<T> *head, *tail;  // 表头和表尾指针
	LinkNode<T> *prevPtr, *currPtr;   //  记录表当前遍历位置的指针，由插入和删除操作更新
public:
 	LinkList<T>(){
 		prevPtr = NULL;
 		currPtr = NULL;
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void add(const T value);
	void creat();   //   创造链表
	void show();     // 显示链表
	bool insertPos(const int i,const T value);
	LinkNode<T>* setPos(int pos);  // 返回指定位置pos的指针
	int getSize();   // 链表中的节点个数
};
template <class T>
int LinkList<T>::getSize()
{
	return count;
}

template <class T>
void LinkList<T>::add(const T value)
{
	count++;
	LinkNode<T> *p;
	if(head == NULL){
		head = new LinkNode<T>;  // 头结点
		head->link = NULL;
		tail = head;        //  尾指针指向头结点

		p = new LinkNode<T>;        //生成新节点
		p->data = value;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
	}
	else{
		p = new LinkNode<T>;        //生成新节点
		p->data = value;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
	}
}
template <class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
	count++;
	LinkNode<T> *p,*q;
	if((p = setPos(i-1))  == NULL){   // p是第i个节点的前驱
		cout<<"插入操作不允许"<<endl;
		return false;
	}
	q = new LinkNode<T>(value,p->link);
	p->link = q;
	if(p == tail){
		tail = q;    //  在表尾进行插入操作
	}
	return true;
}
template <class T>
LinkNode<T>* LinkList<T>::setPos(int pos)
{
	if(pos == -1){  //  i为-1则定位到头结点
		return NULL;
	}
	int count = 0;
	LinkNode<T> *p = head->link;
	while(p != NULL && count < pos){
		p = p->link;
		count++;
	}
	return p;   //  指向第i个节点， 当链表长度小于i时返回NULL
}

template <class T>
void LinkList<T>::creat()
{
	head = new LinkNode<T>;  // 头结点
	head->link = NULL;
	tail = head;        //  尾指针指向头结点
	T i;
	LinkNode<T> *p;
	do{
		cin>>i;
		count++;
		p = new LinkNode<T>;        //生成新节点
		p->data = i;
		tail->link = p;     //把新节点加到以生成的节点的后面
		tail = p;           //尾指针指向新生成的节点
    }while(getchar() != '\n');
	tail->link = NULL;    //尾节点下一个指向为NULL
}
template <class T>
void LinkList<T>::show()
{
	LinkNode<T> *p = head;
	if(head->link == NULL){
        cout<<"无任何数据,请创建链表"<<endl;
        creat();
    }
    else{
		p = p->link;     //跳过头结点
		cout<<"show： ";
    do{
        cout<<p->data<<"  ";
        p = p->link;
        }while(p != NULL);
    cout<<endl;
    }
}
class User
{

public:
	string type;
	int id;
	int isWait;
	User(){
		id = 0;
		isWait = 1;
	}
	User(int i){
		id = i;
		isWait = 1;
	}
	void getServed(){
		isWait = 0;
	}
};

class NormalUser:public User
{
public:
	NormalUser(int i):User(i){
		id = i;
		isWait = 1;
		type = "NormalUser";
	}
	NormalUser(){
		isWait = 1;
		type = "NormalUser";
	}
};

class VIPUser:public User
{
public:
	VIPUser(int i):User(i){
		id = i;
		isWait = 1;
		type = "VIPUser";
	}
	VIPUser(){
		isWait = 1;
		type = "VIPUser";
	}
};

class OfficialUser:public User
{
public:
	OfficialUser(int i):User(i){
		id = i;
		isWait = 1;
		type = "OfficialUser";
	}
	OfficialUser(){
		isWait = 1;
		type = "OfficialUser";
	}
};

class Window
{
public:
	int id;
	User client;
	bool isBusy;
	Window(){
		id = -1;
		isBusy = 0;
	}
	Window(int i){
		id = i;
		isBusy = 0;
	}
	void HandleUser(){
		if(client.isWait == 0){
			isBusy = 1;
		}
		else{
			isBusy = 0;
		}
	}
};

class NormalBankWindow:public Window
{
public:
	string type;
	NormalBankWindow(){
		isBusy = 0;
		type = "NormalBankWindow";
	}
	NormalBankWindow(int i):Window(i){
		id = i;
		isBusy = 0;
		type = "NormalBankWindow";
	}
};

class VIPBankWindow:public Window
{
public:
	string type;
	VIPBankWindow(){
		isBusy = 0;
		type = "VIPBankWindow";
	}
	VIPBankWindow(int i):Window(i){
		id = i;
		isBusy = 0;
		type = "VIPBankWindow";
	}
};

class OfficialBankWindow:public Window
{
public:
	string type;
	OfficialBankWindow(){
		isBusy = 0;
		type = "OfficialBankWindow";
	}
	OfficialBankWindow(int i):Window(i){
		id = i;
		isBusy = 0;
		type = "OfficialBankWindow";
	}
};

class Simulater
{
private:
	int id_user;
	int id_win;
	//  每个窗口的队列
	queue<NormalUser> NormalUserQueue;
	queue<VIPUser> VIPUserQueue;
	queue<OfficialUser> OfficialUserQueue;
	//  每个类型的窗口
	LinkList<NormalBankWindow> nbw;
	LinkList<VIPBankWindow> vbw;
	LinkList<OfficialBankWindow> obw;
public:
	void display();
	void simulateCustomerEnter(int i,int j,int k);  //  模拟三种不同类型的用户进入
	void simulateCallCustomer(int time);        //
	Simulater(int i,int j,int k){        //  在构造函数中创建每个窗口的个数
		int jj,kk;
		id_win = 0;
		id_user = 0;
		NormalBankWindow *NBW;
		VIPBankWindow *VNW;
		OfficialBankWindow *OBW;
		for(; id_win < i;id_win++){
			NBW = new NormalBankWindow(id_win);
			nbw.add(*NBW);
		}
		for(jj = 0; jj < j;jj++){
			VNW = new VIPBankWindow(id_win++);
			vbw.add(*VNW);
		}
		for(kk = 0; kk < k;kk++){
			OBW = new OfficialBankWindow(id_win++);
			obw.add(*OBW);
		}
	}
};

void Simulater::simulateCustomerEnter(int i, int j, int k)
{
	 int ii,jj,kk;
	 NormalUser *NU;
	 VIPUser *VU;
	 OfficialUser *OU;
	 for(ii = 0; ii < i;ii++){
		NU = new  NormalUser(id_user++);
		NormalUserQueue.push(*NU);
	 }
	 for(jj = 0; jj < j;jj++){
		VU = new  VIPUser(id_user++);
		VIPUserQueue.push(*VU);
	 }
	 for(kk = 0; kk < k;kk++){
		OU = new  OfficialUser(id_user++);
		OfficialUserQueue.push(*OU);
	 }
}

void Simulater::display()
{
	int i;
	for(i = 0;i < nbw.getSize();i++){
		cout<<"窗口：id"<<nbw.setPos(i)->data.id<<"   ";
		cout<<nbw.setPos(i)->data.type<<"   ";
		if(nbw.setPos(i)->data.isBusy == 1){
			cout<<"正在服务"<<endl;
			cout<<"客户：id"<<nbw.setPos(i)->data.client.id<<"   ";
			cout<<nbw.setPos(i)->data.client.type<<endl;
		}
		else{
			cout<<"无服务"<<endl;
		}
		cout<<endl;
	}
	for(i = 0;i < vbw.getSize();i++){
		cout<<"窗口：id"<<vbw.setPos(i)->data.id<<"   ";
		cout<<vbw.setPos(i)->data.type<<"   ";
		if(vbw.setPos(i)->data.isBusy == 1){
			cout<<"正在服务"<<endl;
			cout<<"客户：id"<<vbw.setPos(i)->data.client.id<<"   ";
			cout<<vbw.setPos(i)->data.client.type<<endl;
		}
		else{
			cout<<"无服务"<<endl;
		}
		cout<<endl;
	}
	for(i = 0;i < obw.getSize();i++){
		cout<<"窗口：id"<<obw.setPos(i)->data.id<<"   ";
		cout<<obw.setPos(i)->data.type<<"   ";
		if(obw.setPos(i)->data.isBusy == 1){
			cout<<"正在服务"<<endl;
			cout<<"客户：id"<<obw.setPos(i)->data.client.id<<"   ";
			cout<<obw.setPos(i)->data.client.type<<endl;
		}
		else{
			cout<<"无服务"<<endl;
		}
		cout<<endl;
	}
	cout<<"等待用户："<<endl;
		cout<<"普通用户   "<<"VIP用户   "<<"对公用户   "<<endl;
		cout<<"   "<<NormalUserQueue.size()<<"          "
			<<VIPUserQueue.size()<<"          "
			<<OfficialUserQueue.size()<<endl;
}

void Simulater::simulateCallCustomer(int time)   //  模拟叫号
{
	int i;
	if(time % ServeTime == 0 && time != 0){   // 每过ServeTime 遍历所有窗口结束服务
		for(i = 0;i < nbw.getSize();i++){
			if(nbw.setPos(i)->data.isBusy == 1){
				nbw.setPos(i)->data.isBusy = 0;
			}
		}
		for(i = 0;i < vbw.getSize();i++){
			if(vbw.setPos(i)->data.isBusy == 1){
				vbw.setPos(i)->data.isBusy = 0;
			}
		}
		for(i = 0;i < obw.getSize();i++){
			if(obw.setPos(i)->data.isBusy == 1){
				obw.setPos(i)->data.isBusy = 0;
			}
		}
	}
	for(i = 0;i < nbw.getSize();i++){		// 普通窗口遍历
		if(nbw.setPos(i)->data.isBusy == 0){    //  如果该窗口没有正在处理用户时 开始处理当前用户
			if(NormalUserQueue.empty() == 0){		//  如果普通队列不为空时
				NormalUserQueue.front().getServed();
				nbw.setPos(i)->data.client =   NormalUserQueue.front();      //  将当前窗口的状态改变
				nbw.setPos(i)->data.HandleUser();
				NormalUserQueue.pop();
			}
			else{   //  如果普通队列为空时则结束遍历
				break;
			}
		}
	}
	for(i = 0;i < vbw.getSize();i++){		// VIP窗口遍历
		if(vbw.setPos(i)->data.isBusy == 0){    //  如果该窗口没有正在处理用户时 开始处理当前用户
			if(VIPUserQueue.empty() == 0){		//  如果VIP队列不为空时
				VIPUserQueue.front().getServed();
				vbw.setPos(i)->data.client =   VIPUserQueue.front();      //  将当前窗口的状态改变
				vbw.setPos(i)->data.HandleUser();
				VIPUserQueue.pop();
			}
			else{   //  如果VIP队列为空时则VIP窗口开始处理普通用户
				if(NormalUserQueue.empty() == 0){		//  如果普通队列不为空时
					NormalUserQueue.front().getServed();
					vbw.setPos(i)->data.client =   NormalUserQueue.front();      //  将当前窗口的状态改变
					vbw.setPos(i)->data.HandleUser();
					NormalUserQueue.pop();
				}
			}
		}
	}
	for(i = 0;i < obw.getSize();i++){		// 对公窗口遍历
		if(obw.setPos(i)->data.isBusy == 0){    //  如果该窗口没有正在处理用户时 开始处理当前用户
			if(OfficialUserQueue.empty() == 0){		//  如果VIP队列不为空时
				OfficialUserQueue.front().getServed();
				obw.setPos(i)->data.client =   OfficialUserQueue.front();      //  将当前窗口的状态改变
				obw.setPos(i)->data.HandleUser();
				OfficialUserQueue.pop();
			}
			else{   //  如果VIP队列为空时则VIP窗口开始处理普通用户
				if(NormalUserQueue.empty() == 0){		//  如果普通队列不为空时
					NormalUserQueue.front().getServed();
					obw.setPos(i)->data.client =   NormalUserQueue.front();      //  将当前窗口的状态改变
					obw.setPos(i)->data.HandleUser();
					NormalUserQueue.pop();
				}
			}
		}
	}
}

int main()
{
	int i;
	int time = 12;
	Simulater simulater(3,1,1);
	int normalCustomer;
	int vipCustomer;
	int officialCustomer;

	for(i = 0;i <= time;i = i +  ArrayTime){
		cout<<"第"<<i<<"秒 ： "<<endl;
		cout<<"请输入此时进入银行的三种客户 ： "<<endl;
		cin>>normalCustomer;
		cin>>vipCustomer;
		cin>>officialCustomer;
		simulater.simulateCustomerEnter(normalCustomer,vipCustomer,officialCustomer);
		simulater.simulateCallCustomer(i);
		simulater.display();
	}


	return 0;
}
