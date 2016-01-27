/*
 * huffmanTree.h
 *
 *  Created on: Dec 4, 2015
 *      Author: cxy229
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include <iostream>
using namespace std;
#include "minHead.h"

template <class T>
class HuffmanTreeNode{
public:
	T element;
	HuffmanTreeNode<T>* leftChild;
	HuffmanTreeNode<T>* rightChild;
	HuffmanTreeNode(){
		leftChild = NULL;
		rightChild = NULL;
	}
};

template <class T>
class HuffmanTree{
private:
	HuffmanTreeNode<T>* root;//树根
	void MergeTree(HuffmanTreeNode<T> &ht1,HuffmanTreeNode<T> &ht2,HuffmanTreeNode<T>* parent);//合并
	void DeleteTree(HuffmanTreeNode<T>* root);//删除
public:
	HuffmanTree(T weight[],int n);//构造
	virtual ~HuffmanTree(){//析构
		DeleteTree(root);
	}
};
template<class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n)
{
	//定义最小值堆
	MinHeap<HuffmanTreeNode<T>> heap(n);
	HuffmanTreeNode<T> *parent, firstchild,secondchild;
	HuffmanTreeNode<T>* NodeList=new HuffmanTreeNode<T>[n];
	int i;
	for(i=0;i<n;i++){
	NodeList[i].element=weight[i];
	NodeList[i].parent=NodeList[i].left=NodeList[i].right=NULL;
	heap.Insert(NodeList[i]);//向堆中添加元素
	}//end for
	for(i=0;i<n-1;i++)
			{//通过n-1次合并建立Huffman树
	 	     parent=new HuffmanTreeNode<T>;
			 firstchild=heap.RemoveMin();       //选择权值最小的结点
			 secondchild=heap.RemoveMin();   //选择权值次小的结点
			 //合并权值最小的两棵树
	 		 MergeTree(firstchild,secondchild,parent);
	             heap.Insert(*parent);                     //把parent插入到堆中去
			 root=parent;                                    //建立根结点
			}//end for
		delete []NodeList;
	}
#endif /* HUFFMANTREE_H_ */
