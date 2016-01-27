//============================================================================
// Name        : dshw3_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "BinaryTree.h"

int main() {
	BinaryTree<char> bintree;
	if(bintree.isCompBinaryTree(bintree.getRoot())){
		cout<<"是完全二叉树"<<endl;
	}else{
		cout<<"不是完全二叉树"<<endl;
	}
	return 0;
}
