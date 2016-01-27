/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinarySearchTreeNode.h"
#include <iostream>
using namespace std;
#include<queue>
#include<stack>

template <class T>
class BinarySearchTree{
private:
    int n0,n1,n2;
    int high;//高度
    int width;//最大宽度
public:
    BinarySearchTreeNode<T>* root;
    BinarySearchTree();//构造函数 同时创建二叉树
    BinarySearchTree(BinarySearchTreeNode<T>* rt);
    ~BinarySearchTree();

    BinarySearchTreeNode<T>* createTree(BinarySearchTreeNode<T>* root);
    void visit(BinarySearchTreeNode<T>* root);

    bool isEmpty() const;
    BinarySearchTreeNode<T>* getRoot() const;
    BinarySearchTreeNode<T>* getParent(BinarySearchTreeNode<T>* current) const;
    BinarySearchTreeNode<T>* getLeftSubling(BinarySearchTreeNode<T>* current) const;
    BinarySearchTreeNode<T>* getRightSubling(BinarySearchTreeNode<T>* current) const;

    void breadthFirstOrder(BinarySearchTreeNode<T>* root);
    void preOrder(BinarySearchTreeNode<T>* root);
    void preOrderWithoutRecusion(BinarySearchTreeNode<T>* root);
    void inOrder(BinarySearchTreeNode<T>* root);
    void postOrder(BinarySearchTreeNode<T>* root);
    void levelOrder(BinarySearchTreeNode<T>* root);
    void deleteBinarySearchTree(BinarySearchTreeNode<T>* root);
    void count0(BinarySearchTreeNode<T>* root){
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
	 int getHigh(BinarySearchTreeNode<T> *root){
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
	 int getWidth(BinarySearchTreeNode<T> *root,int i = 0){
		 int static widths[20] = {0};      //向量存放各层结点数
		 //int static i = 0;       // 层数

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
	 T getMax0(BinarySearchTreeNode<T>* rt,T max){
		 if(rt!=NULL){
			 if(max<rt->element){
				 max = rt->element;
			 }
			 max = getMax0(rt->leftChild,max);
			 max = getMax0(rt->rightChild,max);
		 }
		 return max;
	 }
	 T getMax(BinarySearchTreeNode<T>* rt){  //获取最大值
		 return getMax0(getRoot(),rt->element);  //初始化max
	 }
	 void swop0(BinarySearchTreeNode<T>* root,stack<BinarySearchTreeNode<T>*> *sta){ //所有结点的指针放入一个栈中
	     if(root != NULL){
	    	 sta->push(root);
	    	 swop0(root->leftChild,sta);
	    	 swop0(root->rightChild,sta);
	     }
	 }
	 void swop(BinarySearchTreeNode<T>* root){
		 stack<BinarySearchTreeNode<T>*> sta;
		 swop0(root,&sta);
		 BinarySearchTreeNode<T> *node=NULL,*t=NULL;
		 while(!sta.empty()){   //交换每个结点的左右指针域
			 node = sta.top();
			 t = node->leftChild;
			 node->leftChild = node->rightChild;
			 node->rightChild = t;
			 sta.pop();
		 }
	 }
	  void clearLeaf(BinarySearchTreeNode<T> *root){  //
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

		/*
			广度优先搜索整个二叉树，
			一旦找一个节点只不含有子节点或者只含有一个左子节点，
			那么后续的所有节点都必须是叶子节点。
			否则，该树就不是完全二叉树。
		*/
		bool isCompBinarySearchTree(BinarySearchTreeNode<T> *root){
		bool bflag = false;
		queue<BinarySearchTreeNode<T>*> nodeQueue;      //用队列来存放将要访问的节点
		BinarySearchTreeNode<T> * pointer =root;
		if(pointer){
			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
		}
		else{
			return true;
		}
		while(!nodeQueue.empty())
		{
			if(pointer->leftChild ==NULL && pointer->rightChild != NULL){   //  当当前节点只有右结点没有左结点时 直接返回false
				return false;
			}
			if(bflag == true && !pointer->isLeaf()){   //  当之前有一个节点只不含有子节点或者只含有一个左子节点（true）， 若当前节点不是叶子节点，直接返回false
				return false;
			}
			pointer = nodeQueue.front();       //读取队首节点
			nodeQueue.pop();                      //将访问过的节点移除队列
			//    将访问过的节点的左右孩纸节点依次加入到队尾
			if(pointer->leftChild){
				nodeQueue.push(pointer->leftChild);
			}
			if(pointer->rightChild){
				nodeQueue.push(pointer->rightChild);
			}
			if(pointer->rightChild == NULL){      //  当一个节点的右指针域为空，设置标记为true
				bflag = true;
			}
		}
		return true;
	 }

	BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root,T key){  //查找
		BinarySearchTreeNode<T>* current = root;
		while((NULL != root)&&(key != current->getValue())){//当当前结点的key等于查询的值时退出循环
			current = (key<current->getValue()?search(current->leftChild,key):search(current->rightChild,key));
					//根据当前结点的值的大小决定移动方向
		}
		return current;
	}

	void insertNode(const T& value){      //插入
		BinarySearchTreeNode<T> *p = root,*prev = NULL;
		while(p!=NULL){                     //查找新结点位置
			prev = p;					 //记录父结点
			if(p->getValue()<value){
				p = p->rightChild;
			}else{
				p = p->leftChild;
			}
		}
		if(root == NULL)
			root = new BinarySearchTreeNode<T>(value);
		else if(prev->getValue()<value){
			prev->rightChild = new BinarySearchTreeNode<T>(value);
		}else{
			prev->leftChild = new BinarySearchTreeNode<T>(value);
		}
	}
	BinarySearchTreeNode<T>* deletemin(BinarySearchTreeNode<T>* rt){
		if (rt->leftChild != NULL)
			return deletemin(rt->leftChild);
		else { // 找到右子树中最小，删除
			BinarySearchTreeNode<T> *temp = rt;
			rt = rt->rightChild;
			return temp;
		}
	}
	void deleteByCopying(BinarySearchTreeNode<T> *& rt, const T val) {
		if (rt == NULL)    //找到
			cout << val << " is not in the tree.\n";
		else if (val < rt->getValue())
			deleteByCopying(rt->leftChild, val);
		else if (val > rt->getValue())
			deleteByCopying(rt->rightChild, val);
		else { // 真正的删除
			BinarySearchTreeNode < T > *temp = rt;
			if (rt->leftChild == NULL)
				rt = rt->rightChild;
			else if (rt->rightChild == NULL)
				rt = rt->leftChild;
			else {
				temp = deletemin(rt->rightChild);
				rt->setValue(temp->getValue());
			}
		}
	}

};
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	n0 = 0;
	n1 = 0;
	n2 = 0;
	high = 0;
	width = 0;
	root = NULL;
}
template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTreeNode<T>* rt){
	n0 = 0;
	n1 = 0;
	n2 = 0;
	high = 0;
	width = 0;
	root = rt;
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree(){
	root = NULL;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::createTree(BinarySearchTreeNode<T>* root){
	char ele;
	cout<<"请按先序输入结点数据（'#'表示该结点为空）：";
	cin>>ele;			//按先序建立二叉树
	if(ele == '#')
	{
		root = NULL;	//置为NULL后结束
		return root;
	}
	root = new(BinarySearchTreeNode<T>);
	root->element = ele;
	root->leftChild = createTree(root->leftChild);
	root->rightChild = createTree(root->rightChild);
	return root;
}
template <class T>
void BinarySearchTree<T>::visit(BinarySearchTreeNode<T>* root){
	cout<<root->element;
}
template <class T>
bool BinarySearchTree<T>::isEmpty() const{
	if (root == NULL){
		return true;
	}else{
		return false;
	}
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getRoot() const{
	return root;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getLeftSubling(BinarySearchTreeNode<T>* current) const{
	return current->leftChild;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getRightSubling(BinarySearchTreeNode<T>* current) const{
	return current->rightChild;
}
template <class T>
void BinarySearchTree<T>::levelOrder(BinarySearchTreeNode<T>* root){
    using std::queue;
    queue<BinarySearchTreeNode<T>*> nodeQueue;
    BinarySearchTreeNode<T>* pointer = root;

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
void BinarySearchTree<T>::preOrder(BinarySearchTreeNode<T>* root){
    if(root != NULL){
        visit(root);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}
template <class T>
void BinarySearchTree<T>::inOrder(BinarySearchTreeNode<T>* root){
	if(root != NULL){
		inOrder(root->leftChild);
		visit(root);
		inOrder(root->rightChild);
	}
}
template <class T>
void BinarySearchTree<T>::postOrder(BinarySearchTreeNode<T>* root){
	if(root != NULL){
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		visit(root);
	}
}

#endif /* BINARYSEARCHTREE_H_ */
