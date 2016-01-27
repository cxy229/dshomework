/*
 * BinaryTreeNode.h
 *
 *  Created on: Nov 17, 2015
 *      Author: cxy229
 */

#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_
#include "BinaryTree.h"
#include <iostream>
using namespace std;
#include<queue>
template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode{
    friend class BinaryTree<T>;
private:
    T element;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;
public:

    BinaryTreeNode();
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T&ele,BinaryTreeNode<T>* l,BinaryTreeNode<T>* r);

    BinaryTreeNode<T>* getLeftChild() const;
    BinaryTreeNode<T>* getRightChild() const;
    void setLeftChild(BinaryTreeNode<T>* l);
    void setRightChild(BinaryTreeNode<T>* r);
    T getValue() const;
    void setValue(const T& val);
    bool isLeaf() const;
};
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(){
	leftChild = NULL;
	rightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele){
	element = ele;
	leftChild = NULL;
	rightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele,BinaryTreeNode<T>* l,BinaryTreeNode<T>* r){
	element = ele;
	leftChild = l;
	rightChild = r;
}
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() const{
	return leftChild;
}
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() const{
	return rightChild;
}
template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* l){
	leftChild = l;
}
template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* r){
	rightChild = r;
}
template <class T>
T BinaryTreeNode<T>::getValue() const{
	return element;
}
template <class T>
void BinaryTreeNode<T>::setValue(const T& val){
	element = val;
}
template <class T>
bool BinaryTreeNode<T>::isLeaf() const{
	if(leftChild==NULL && rightChild==NULL){
		return true;
	}else{
		return false;
	}
}

#endif /* BINARYTREENODE_H_ */
