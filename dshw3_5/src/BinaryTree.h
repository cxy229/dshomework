/*
 * BinaryTree.h
 *
 *  Created on: Nov 17, 2015
 *      Author: cxy229
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;
#include<queue>
#include<stack>

template <class T>
class BinaryTree{
private:
    BinaryTreeNode<T>* root;
    int n0,n1,n2;
    int high;//高度
    int width;//最大宽度
public:
    BinaryTree();//构造函数 同时创建二叉树
    BinaryTree(BinaryTreeNode<T>* rt);
    ~BinaryTree();

    BinaryTreeNode<T>* createTree(BinaryTreeNode<T>* root);
    void visit(BinaryTreeNode<T>* root);

    bool isEmpty() const;
    BinaryTreeNode<T>* getRoot() const;
    BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* current) const;
    BinaryTreeNode<T>* getLeftSubling(BinaryTreeNode<T>* current) const;
    BinaryTreeNode<T>* getRightSubling(BinaryTreeNode<T>* current) const;

    void breadthFirstOrder(BinaryTreeNode<T>* root);
    void preOrder(BinaryTreeNode<T>* root);
    void preOrderWithoutRecusion(BinaryTreeNode<T>* root);
    void inOrder(BinaryTreeNode<T>* root);
    void postOrder(BinaryTreeNode<T>* root);
    void levelOrder(BinaryTreeNode<T>* root);
    void deleteBinaryTree(BinaryTreeNode<T>* root);
    void count0(BinaryTreeNode<T>* root){
        if(root != NULL){
        	if(root->leftChild==NULL&&root->rightChild==NULL){
        	   	n0++;
        	}
            if((root->leftChild==NULL&&root->rightChild!=NULL)||(root->leftChild!=NULL&&root->rightChild==NULL)){
            	n1++;
            }
        	if(root->leftChild!=NULL&&root->rightChild!=NULL){
        	   	n2++;
        	}
            count0(root->leftChild);
            count0(root->rightChild);
        }
    }
    void count(){
    	n0 = n1 = n2 = 0;
    	count0(root);
    	cout<<"度为0："<<n0<<endl;
    	cout<<"度为1："<<n1<<endl;
    	cout<<"度为2："<<n2<<endl;
    }
	 int getHigh(BinaryTreeNode<T> *root){
		 int left = 0,right = 0;
		 if(root != NULL){
			 if((left=getHigh(root->leftChild)) > (right = getHigh(root->rightChild))){
				high = left + 1;
			 }
			 else{
				 high = right + 1;
			 }
		 }
		 else{
			high = 0;
		 }
		 return high;
	 }
	 int getWidth(BinaryTreeNode<T> *root,int i = 0){
		 int static widths[20] = {0};      //向量存放各层结点数

		 if(root != NULL){
			i++;
			widths[i]++;
			if(widths[i] > width){
				width = widths[i];
			}
			getWidth(root->leftChild,i);
			getWidth(root->rightChild,i);
		 }
		 else{
			return 0;
		 }
		 return width;
	 }
	 T getMax0(BinaryTreeNode<T>* rt,T max){
		 if(rt!=NULL){
			 if(max<rt->element){
				 max = rt->element;
			 }
			 max = getMax0(rt->leftChild,max);
			 max = getMax0(rt->rightChild,max);
		 }
		 return max;
	 }
	 T getMax(BinaryTreeNode<T>* rt){  //获取最大值
		 return getMax0(getRoot(),rt->element);  //初始化max
	 }
	 void swop0(BinaryTreeNode<T>* root,stack<BinaryTreeNode<T>*> *sta){ //所有结点的指针放入一个栈中
	     if(root != NULL){
	    	 sta->push(root);
	    	 swop0(root->leftChild,sta);
	    	 swop0(root->rightChild,sta);
	     }
	 }
	 void swop(BinaryTreeNode<T>* root){
		 stack<BinaryTreeNode<T>*> sta;
		 swop0(root,&sta);
		 BinaryTreeNode<T> *node=NULL,*t=NULL;
		 while(!sta.empty()){   //交换每个结点的左右指针域
			 node = sta.top();
			 t = node->leftChild;
			 node->leftChild = node->rightChild;
			 node->rightChild = t;
			 sta.pop();
		 }
	 }
	  void clearLeaf(BinaryTreeNode<T> *root){  //
		if(root != NULL ){
			if( root->leftChild != NULL ){
				if(root->leftChild->isLeaf()){
				 root->leftChild  = NULL;
				}
			 }
			 if(root->rightChild != NULL){
				 if(root->rightChild->isLeaf()){
					 root->rightChild  = NULL;
				 }
			 }
			if(root->leftChild)
				clearLeaf(root->leftChild);
			 if(root->rightChild)
				clearLeaf(root->rightChild);
		 }
	 }
};
template <class T>
BinaryTree<T>::BinaryTree(){
	n0 = 0;
	n1 = 0;
	n2 = 0;
	high = 0;
	width = 0;
	BinaryTreeNode<T>* rt = NULL;
	root = createTree(rt);
}
template <class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* rt){
	n0 = 0;
	n1 = 0;
	n2 = 0;
	high = 0;
	width = 0;
	root = rt;
}
template <class T>
BinaryTree<T>::~BinaryTree(){
	root = NULL;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::createTree(BinaryTreeNode<T>* root){
	char ele;
	cout<<"请按先序输入结点数据（'#'表示该结点为空）：";
	cin>>ele;			//按先序建立二叉树
	if(ele == '#')
	{
		root = NULL;	//置为NULL后结束
		return root;
	}
	root = new(BinaryTreeNode<T>);
	root->element = ele;
	root->leftChild = createTree(root->leftChild);
	root->rightChild = createTree(root->rightChild);
	return root;
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* root){
	cout<<root->element;
}
template <class T>
bool BinaryTree<T>::isEmpty() const{
	if (root == NULL){
		return true;
	}else{
		return false;
	}
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const{
	return root;
}
//template <class T>
//BinaryTreeNode<T>* BinaryTree<T>::getParent(BinaryTreeNode<T>* current) const{
//	return root;
//}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getLeftSubling(BinaryTreeNode<T>* current) const{
	return current->leftChild;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRightSubling(BinaryTreeNode<T>* current) const{
	return current->rightChild;
}
template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root){
    using std::queue;
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;

    if (pointer)
        nodeQueue.push(pointer);
    while(!nodeQueue.empty()){
        pointer = nodeQueue.front();
        visit(pointer);
        nodeQueue.pop();
        if(pointer->leftChild)
            nodeQueue.push(pointer->leftChild);
        if(pointer->rightChild)
            nodeQueue.push(pointer->rightChild);
    }
}
template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root){
    if(root != NULL){
        visit(root);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}
template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root){
	if(root != NULL){
		inOrder(root->leftChild);
		visit(root);
		inOrder(root->rightChild);
	}
}
template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root){
	if(root != NULL){
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		visit(root);
	}
}

#endif /* BINARYTREE_H_ */
