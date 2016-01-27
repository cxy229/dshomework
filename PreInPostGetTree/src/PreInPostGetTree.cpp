/*
 * PreInPostGetTree.cpp
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#include <iostream>
using namespace std;
#include <string>
#include "BinaryTree.h"

int main(){
	string preString = "abdgcef";
	string inString = "dgbaecf";
	string postString = "gdbefca";
	BinaryTree<char> bintree;
	bintree.setRoot(bintree.PreInGetTree(preString,inString,bintree.getRoot()));//前序中序生成二叉树
	cout<<"前序中序生成的二叉树后序为：";bintree.postOrder(bintree.getRoot());
	cout<<endl;

	bintree.setRoot(bintree.InPostGetTree(inString,postString,bintree.getRoot()));//前序中序生成二叉树
	cout<<"中序后序生成的二叉树前序为：";bintree.preOrder(bintree.getRoot());
	cout<<endl;
	return 0;
}


