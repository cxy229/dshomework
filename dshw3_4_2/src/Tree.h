/*
 * Tree.h
 *
 *  Created on: Dec 4, 2015
 *      Author: cxy229
 */

#ifndef TREE_H_
#define TREE_H_

#include<iostream>
#include<string>
#include<queue>
#include"TreeNode.h"
using namespace std;
void visit(TreeNode *temp){
	cout<<temp->getValue()->getName()<<" :   "<<temp->getValue()->getNum()<<endl;
}

class Tree
{
private:
	TreeNode *root;
public:
	Tree(){
		root = NULL;
	}
	TreeNode* getRoot(){
		return root;
	}
	void visit(TreeNode *temp){
		cout<<temp->getValue()->getName()<<" :   "<<temp->getValue()->getNum()<<endl;
	}
	TreeNode* getParent(TreeNode *current){
		queue<TreeNode*> aQueue;      //用队列来存放将要访问的节点
		TreeNode *pointer = root;
		TreeNode *parent = NULL;
		if (current == NULL){
			return NULL;
		}else{
			while(pointer != NULL){
				if(pointer == current){
					return NULL;
				}else{
					aQueue.push(pointer);
					pointer = pointer->getSibling();
				}
			}
			while(!aQueue.empty()){
				parent = aQueue.front();
				aQueue.pop();
				pointer = parent->getChild();
				while(pointer){
					if(pointer == current){
						return parent;
					}else{
						aQueue.push(pointer);
						pointer = pointer->getSibling();
					}
				}
			}
			return NULL;
		}



//		queue<TreeNode*> nodeQueue;      //用队列来存放将要访问的节点
//		TreeNode * pointer =root;
//		if(pointer){
//			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
//		}
//		while(!nodeQueue.empty())
//		{
//			pointer = nodeQueue.front();       //读取队首节点
//			if(pointer->getChild() == current){
//				return pointer;
//			}
//			nodeQueue.pop();                      //将访问过的节点移除队列
//			//    将访问过的节点的左右孩纸节点依次加入到队尾
//			if(pointer->getChild()){
//				nodeQueue.push(pointer->getChild());
//			}
//			if(pointer->getSibling()){
//				nodeQueue.push(pointer->getSibling());
//			}
//		}
		return NULL;
	}
	TreeNode* Find(string current){
		queue<TreeNode*> nodeQueue;      //用队列来存放将要访问的节点
		TreeNode * pointer =root;
		if(pointer){
			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
		}
		while(!nodeQueue.empty())
		{
			pointer = nodeQueue.front();       //读取队首节点
			if(pointer->getValue()->getName() == current){
				return pointer;
			}
			nodeQueue.pop();                      //将访问过的节点移除队列
			//    将访问过的节点的左右孩纸节点依次加入到队尾
			if(pointer->getChild()){
				nodeQueue.push(pointer->getChild());
			}
			if(pointer->getSibling()){
				nodeQueue.push(pointer->getSibling());
			}
		}
		return NULL;
	}
	void insert(string parent,HosPartNode *node){
		if(root == NULL){
			root = new TreeNode(node);
		}else if(Find(parent)==NULL){  //没找到要插入的父结点
			cout<<" 无法找到父节点,请检查."<<endl;
			return;
		}
		else if(Find(parent)->getChild() == NULL){//插入到父节点的孩子结点
			TreeNode *treeNode = Find(parent);
			treeNode->setChild(new TreeNode(node));
		}
		else if(Find(parent)->getChild() != NULL){//插入到父节点孩子结点的兄弟结点                                    //
			TreeNode *treeNode = Find(parent)->getChild();
			while(treeNode->getSibling() != NULL){
				treeNode = treeNode->getSibling();
			}
			treeNode->setSibling(new TreeNode(node));
		}
	}
	void RootFirstTraverse(TreeNode *root){
		visit(root);
		RootFirstTraverse(root->getChild());
		RootFirstTraverse(root->getSibling());
	}
	void RootLastTraverse(TreeNode *root){
		RootFirstTraverse(root->getChild());
		RootFirstTraverse(root->getSibling());
		visit(root);
	}
	void WithTraverse(TreeNode *root){ //广度优先遍历
		queue<TreeNode*> nodeQueue;      //用队列来存放将要访问的节点
		TreeNode * pointer =root;
		TreeNode * temp_pointer=NULL;
		if(pointer){
			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
		}
		while(!nodeQueue.empty()){

			pointer = nodeQueue.front();       //读取队首节点
			pointer->print();

			if(pointer->getChild()){
				nodeQueue.push(pointer->getChild());
				pointer=pointer->getChild();
				temp_pointer=pointer;

				while(temp_pointer->getSibling()!=NULL){
				nodeQueue.push(temp_pointer->getSibling());
				temp_pointer=temp_pointer->getSibling();
				}
			}
			nodeQueue.pop();                      //将访问过的节点移除队列

	}

	}
	int count(string gparent,string gchild){
		TreeNode *parent = Find(gparent);
		TreeNode *child = Find(gchild);
		if(parent == NULL || child == NULL){
			return 0;
		}
		else{
			int Num = 1;
			Num *= child->getValue()->getNum();
			while(getParent(child) != root && getParent(child)->getValue()->getName() != gparent){
				child = getParent(child);
				Num *= child->getValue()->getNum();

//				TreeNode *direParent = getParent(child);
//				if(direParent){
//					if(gparent == direParent->getValue()->getName()){
//						return Num;
//					}
//					else{
//						child = direParent;
//					}
//				}
//				else{
//					return 0;
//				}
			}
			return Num;
		}
		return 0;
	}
};



#endif /* TREE_H_ */
