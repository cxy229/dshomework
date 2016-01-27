#include<iostream>
#include"ThreadBinaryTree.h"
using namespace std;
int main()
{
	ThreadBinaryTree<int> tree;
	cout<<"创建全完二叉树： "<<endl;
	tree.creat();
	tree.InThread(tree.getRoot());
	tree.InOrder(tree.getRoot());
	//tree.levelOrder(tree.getRoot());
	cout<<endl;
	ThreadBinaryTreeNode<int> *node = tree.getRoot()->leftChild;
	cout<<"结点的前驱为 ： "<<tree.search_qianqu(node)->getValue()<<endl;
	cout<<"结点的后继为 ： "<<tree.search_houji(node)->getValue()<<endl;
	return 0;
}
