/*
 * ThreadBinaryTreeNode.h
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#ifndef THREADBINARYTREENODE_H_
#define THREADBINARYTREENODE_H_
#include<iostream>
using namespace std;

template <class T>
class ThreadBinaryTreeNode
{
public:
	int leftTag, rightTag;      //左右标志位
	ThreadBinaryTreeNode<T> * leftChild;    //前驱或左子树
	ThreadBinaryTreeNode<T> * rightChild;   //后继或右子树
	T element;        //节点数据域
public:
	ThreadBinaryTreeNode(){
		leftChild = NULL;
		rightChild = NULL;
		leftTag = 0;
		rightTag = 0;
	}
	ThreadBinaryTreeNode(const T& ele){   //构造函数
		element = ele;
		leftChild = NULL;
		rightChild = NULL;
		leftTag = 0;
		rightTag = 0;
	}
	ThreadBinaryTreeNode(const T &ele,ThreadBinaryTreeNode<T> *l,ThreadBinaryTreeNode<T> *r){
		element = ele;
		leftChild = l;
		rightChild = r;
		leftTag = 0;
		rightTag = 0;
	}
	ThreadBinaryTreeNode<T>* getLeftChild() const{
		return leftChild;
	}
	ThreadBinaryTreeNode<T>* getRightChild() const{
		return rightChild;
	}
	void setLeftChild(ThreadBinaryTreeNode<T> * l){
		leftChild = l;
	}
	void setRightChild(ThreadBinaryTreeNode<T> * r){
		rightChild = r;
	}
	T getValue() const{   //返回该节点的数据值
		return element;
	}
	void setValue(const T &val){   //设置该节点的数据域的值
		element = val;
	}
};


#endif /* THREADBINARYTREENODE_H_ */
