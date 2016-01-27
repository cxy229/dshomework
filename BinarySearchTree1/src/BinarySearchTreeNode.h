/*
 * BinarySearchTreeNode.h
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#ifndef BINARYSEARCHTREENODE_H_
#define BINARYSEARCHTREENODE_H_
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
#include<queue>
template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTreeNode{
    friend class BinarySearchTree<T>;
private:
    T element;
    BinarySearchTreeNode<T>* leftChild;
    BinarySearchTreeNode<T>* rightChild;
public:

    BinarySearchTreeNode();
    BinarySearchTreeNode(const T& ele);
    BinarySearchTreeNode(const T&ele,BinarySearchTreeNode<T>* l,BinarySearchTreeNode<T>* r);

    BinarySearchTreeNode<T>* getLeftChild() const;
    BinarySearchTreeNode<T>* getRightChild() const;
    void setLeftChild(BinarySearchTreeNode<T>* l);
    void setRightChild(BinarySearchTreeNode<T>* r);
    T getValue() const;
    void setValue(const T& val);
    bool isLeaf() const;
};
template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(){
	leftChild = NULL;
	rightChild = NULL;
}
template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T& ele){
	element = ele;
	leftChild = NULL;
	rightChild = NULL;
}
template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T& ele,BinarySearchTreeNode<T>* l,BinarySearchTreeNode<T>* r){
	element = ele;
	leftChild = l;
	rightChild = r;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::getLeftChild() const{
	return leftChild;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::getRightChild() const{
	return rightChild;
}
template <class T>
void BinarySearchTreeNode<T>::setLeftChild(BinarySearchTreeNode<T>* l){
	leftChild = l;
}
template <class T>
void BinarySearchTreeNode<T>::setRightChild(BinarySearchTreeNode<T>* r){
	rightChild = r;
}
template <class T>
T BinarySearchTreeNode<T>::getValue() const{
	return element;
}
template <class T>
void BinarySearchTreeNode<T>::setValue(const T& val){
	element = val;
}
template <class T>
bool BinarySearchTreeNode<T>::isLeaf() const{
	if(leftChild==NULL && rightChild==NULL){
		return true;
	}else{
		return false;
	}
}
#endif /* BINARYSEARCHTREENODE_H_ */
