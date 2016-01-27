/*
 * HuffmanTree.h
 *
 *  Created on: Dec 11, 2015
 *      Author: cxy229
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include <iostream>
#include "MinHead.h"
#include <string>
#include <map>
using namespace std;

template <class T>
class HuffmanTree;

template <class T>
class HuffmanTreeNode
{
    int weight;
    T data;
    HuffmanTreeNode<T> * left;
    HuffmanTreeNode<T> * right;
public:
    HuffmanTreeNode();
    void set(int w, T d);
    bool isLeaf(){
    	if(left==NULL&&right==NULL){
    		return true;
    	}else{
    		return false;
    	}
    }
	bool operator < (HuffmanTreeNode<T> & a);
    bool operator > (HuffmanTreeNode<T> & a);
    bool operator == (HuffmanTreeNode<T> & a);
  //  void operator = (Node<T> & a);
    void operator = (HuffmanTreeNode<T> & a);
    friend class HuffmanTree<T>;
};
template <class T>
HuffmanTreeNode<T>::HuffmanTreeNode()
{
    weight = 0;
    left = NULL;
    right = NULL;
}
template <class T>
void HuffmanTreeNode<T>::set(int w, T d)
{
    weight = w;
    data = d;
}
template <class T>
bool HuffmanTreeNode<T>::operator > (HuffmanTreeNode<T> & a)
{
    if(this->weight > a.weight)
        return true;
    return false;
}
template <class T>
bool HuffmanTreeNode<T>::operator < (HuffmanTreeNode<T> & a)
{
    if(this->weight < a.weight)
        return true;
    return false;
}
template <class T>
void HuffmanTreeNode<T>::operator = (HuffmanTreeNode<T> & a)
{
    weight = a.weight;
    data = a.data;
    left = a.left;
    right = a.right;
}
template <class T>
bool HuffmanTreeNode<T>::operator == (HuffmanTreeNode<T> &a)
{
    if(data == a.data)
        return true;
    return false;
}
template <class T>
class HuffmanTree
{
    HuffmanTreeNode<T>* root;
    //Node<T>* merge(Node<T>* &root1, Node<T>* &roo2);    //合并两树
public:
    map<T,string> codes;
    HuffmanTree();
    HuffmanTreeNode<T>* getroot(){
    	return root;
    }
    //权重数组w, 元素数组arr，元素个数n，该类型元素的空白符blank
    void setTree(int* w, T* arr, int n, T blank);
    bool empty();
    bool leaf(HuffmanTreeNode<T>* pCur);
    HuffmanTreeNode<T>* get_root();
    void encode(HuffmanTreeNode<T>* pCur,string code);
    string coding(T ele);      //编码
    string uncoding(string code);   //解码

    void clear(HuffmanTreeNode<T>* pCur);

    ~HuffmanTree();
};
template <class T>
HuffmanTree<T>::HuffmanTree()
{
    root = NULL;
}
template <class T>
void HuffmanTree<T>::setTree(int* w, T* arr, int n, T blank)
{
	if(w == NULL || arr == NULL || n <= 0)
		return ;
	 int i;
	 HuffmanTreeNode<T>* h_node = new HuffmanTreeNode<T>[n];
    for(i = 0; i < n; i++)
    {
        h_node[i].set(w[i],arr[i]);
    }

	MinHead< HuffmanTreeNode<T> > node_heap(h_node, n, n);
	node_heap.build();//筛选法构建最小堆
    root = NULL;

	while(true){
		HuffmanTreeNode<T>  *node = new HuffmanTreeNode<T>;
		node->right = new HuffmanTreeNode<T>(node_heap.top());
		node_heap.pop();
		node->left = new HuffmanTreeNode<T>(node_heap.top());
		node_heap.pop();
		node->weight =  node->left->weight + node->right->weight;
		node->data = blank;
		if(node_heap.empty()){
			root = node;
			break;
		}
		node_heap.insert(*node);
	}
}
template <class T>
string HuffmanTree<T>::coding(T ele)   //编码
{
	return codes[ele];
    }

template <class T>
void HuffmanTree<T>::encode(HuffmanTreeNode<T>* pCur,string code){
	if(pCur->isLeaf()){
		codes[pCur->data] = code;
		return;
	}
	encode(pCur->left,code+'0');
	encode(pCur->right,code+'1');
}

template <class T>
string HuffmanTree<T>::uncoding(string code)   //译码
{
    int len = code.length();
    string words;
    HuffmanTreeNode<T>* pCur = root;
	int i;
    for(i = 0; i < len; i++)
    {
        if(code[i] == '0')
            pCur = pCur->left;
        else if(code[i] == '1')
            pCur = pCur->right;
        else
        {
            cout<<"can't recognize！"<<endl;
            pCur = root;
        }
        if(pCur->isLeaf())
        {
            words += pCur->data;
            pCur = root;
        }
    }
    return words;
}
template <class T>
bool HuffmanTree<T>::empty()
{
    if(root==NULL)
        return true;
    return false;
}
template <class T>
bool HuffmanTree<T>::leaf(HuffmanTreeNode<T>* pCur)
{
    if(pCur->left==NULL && pCur->right==NULL)
        return true;
    return false;
}
template <class T>
HuffmanTreeNode<T>* HuffmanTree<T>::get_root()
{
    return root;
}
template <class T>
void HuffmanTree<T>::clear(HuffmanTreeNode<T>* pCur)
{
    HuffmanTreeNode<T>* pDel = pCur;
    while(pCur!=NULL)
    {
        if(pCur->left)
        {
            delete pCur->left;
            pCur->left = NULL;
        }
        pDel = pCur;
        pCur = pCur->right;
        delete pDel;
    }
}
template <class T>
HuffmanTree<T>::~HuffmanTree()
{
    clear(root);
}
#endif /* HUFFMANTREE_H_ */
