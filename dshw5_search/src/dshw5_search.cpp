#include<iostream>
using namespace std;

int Search(int *a,int n,int key)//顺序查找
{
	for(int i=0;i<n;i++)
		if(key==a[i])
			return i;
	return -1;
}

int BiSearch(int *a,int n,int key)//折半查找
{
	int left=0,right=n-1;
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==key)
			return mid;
		else if(key>a[mid])
			left=mid+1;
		else
			right=mid-1;
	}

	return -1;
}

int main()
{
	int a[6]={0,1,2,3,4,5};
	int num;
	int key;

	cout<<"原数组为 ："<<endl;
	for(int i=0;i<6;i++)
		cout<<a[i]<<",";
	cout<<endl;

	cout<<endl<<"顺序查找  请输入要查找Key"<<endl;
	cin>>key;
	num=Search(a,6,key);
	if(num==-1)
		cout<<"数组中无此元素"<<endl;
	else
		cout<<"数组中该元素下标为 ："<<num<<endl;

	cout<<"折半查找  请输入要查找Key"<<endl;
	cin>>key;
	num=BiSearch(a,6,key);
	if(num==-1)
		cout<<"数组中无此元素"<<endl;
	else
		cout<<"数组中该元素下标为 ："<<num<<endl;
	return 0;
}
