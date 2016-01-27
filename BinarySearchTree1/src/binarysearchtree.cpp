/*
 * binarysearchtree.cpp
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

int main(){
	char* s = "badc";
	BinarySearchTree<char> bst;
	for(int i = 0;s[i]!='\0';i++)  bst.insertNode(s[i]); //生成二叉搜索树
	cout<<"中序遍历结果：";bst.inOrder(bst.getRoot());
	cout<<endl;
	char c;
	cout<<"输入要查找的字符：";cin>>c;
	cout<<bst.search(bst.getRoot(),c)->getValue();//查找
	cout<<endl;
	cout<<"输入要插入的字符：";cin>>c;
	bst.insertNode(c);
	cout<<"中序遍历结果：";bst.inOrder(bst.getRoot());
	cout<<endl;
	char d;
	cout<<"输入要删除的字符：";cin>>d;
	bst.deleteByCopying(bst.root,d);
	cout<<"中序遍历结果：";bst.inOrder(bst.getRoot());
	return 0;
}

