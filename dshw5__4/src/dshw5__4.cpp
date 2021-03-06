#include<iostream>
#include"ContactList.h"
#include<string>
using namespace std;
int main()
{
	ContactList list(100);
	string name;
	string phoneNum;
	string email;
	int h = 0;
	cout<< "新建请按1" << endl
		<< "删除请按2" << endl
		<< "修改联系人信息请按3" << endl
		<< "分块查找联系人请按4" << endl
		<< "散列查找联系人请按5" << endl
		<< "不想进行操作请直接按0" << endl;
	cin >> h;
	while (h != 0)
	{
		if (h == 1)
		{
			int i = 1;
			while (i != 0)
			{
				cout << "请输入姓名(英文):";
				cin >> name;
				cin.sync(); //清空输入流
				cout << "请输入电话号:";
				cin >> phoneNum;
				cin.sync();
				cout << "请输入邮箱:";
				cin >> email;
				cin.sync();
				list.addContact(name, phoneNum, email);
				cout << "继续添加请按1,不再添加请按0:";
				cin >> i;
			}
		}
		else if (h == 2)
		{
			cout << "你想删除哪个联系人？输入姓名即可:";
			cin >> name;
			list.delContact(name);
		}
		else if (h == 3)
		{
			cout << "想要更新谁的信息?:"<<endl;
			cout << "请输入姓名(英文):";
			cin >> name;
			cin.sync(); //清空输入流
			cout << "请输入电话号:";
			cin >> phoneNum;
			cin.sync();
			cout << "请输入邮箱:";
			cin >> email;
			cin.sync();
			list.updateContact(name, phoneNum, email);
		}
		else if (h == 4)
		{
			cout << "请输入想要查找的联系人姓名:";
			cin >> name;
			cin.sync(); //清空输入流
			int i=list.blockQuery(name);
			cout << "分块查找结果为:" << name << "在第" << i << "个" << endl;
		}
		else if (h == 5)
		{
			cout << "请输入想要查找的联系人姓名:";
			cin >> name;
			cin.sync(); //清空输入流
			int i = list.hashQuery(name);
			cout << "散列查找结果为:" << name << "在第" << i << "个" << endl;
		}else if(h == 6){
			list.showList();
		}
		cout << "想要继续体验？" << endl
			<< "新建请按1" << endl
			<< "删除请按2" << endl
			<< "修改联系人信息请按3" << endl
			<< "分块查找联系人请按4" << endl
			<< "散列查找联系人请按5" << endl
			<< "打印通讯录列表请按6" << endl
			<< "不想进行操作请直接按0" << endl;
		cin >> h;
	}
	return 0;
}
