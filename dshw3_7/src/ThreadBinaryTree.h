/*
 * ThreadBinaryTree.h
 *
 *  Created on: Nov 19, 2015
 *      Author: cxy229
 */

#ifndef THREADBINARYTREE_H_
#define THREADBINARYTREE_H_
#include <stdio.h>
#include<iostream>
#include<queue>
#include<stack>
#include"ThreadBinaryTreeNode.h"
using namespace std;

template <class T>
void visit(ThreadBinaryTreeNode<T> * temp){
		cout<<temp->getValue()<<"   ";
}
template <class T>
class ThreadBinaryTree
{
private:
	ThreadBinaryTreeNode<T> * root;//根节点指针
public:
	ThreadBinaryTree(){  //构造函数
		root = NULL;
	}
	ThreadBinaryTree(ThreadBinaryTreeNode<T> * r){
		root = r;
	}
	~ThreadBinaryTree(){}
	ThreadBinaryTreeNode<T> * getRoot(){   //返回根节点指针
		return root;
	}
	void InThread(ThreadBinaryTreeNode<T>* root){  //中序线索化二叉树;
		queue<ThreadBinaryTreeNode<T>*> nodeQueue;      //用队列来存放将要访问的节点
		ThreadBinaryTreeNode<T> * pointer =root;
		if(pointer){
			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
		}
		else{
			cout<<"树为空。"<<endl;
		}
		while(!nodeQueue.empty())
		{
			pointer = nodeQueue.front();       //读取队首节点
			if(pointer->leftChild == NULL){
				pointer->leftTag = 1;
			}
			else{
				pointer->leftTag = 0;
			}
			if(pointer->rightChild == NULL){
				pointer->rightTag = 1;
			}
			else{
				pointer->rightTag = 0;
			}
			nodeQueue.pop();                      //将访问过的节点移除队列
			//    将访问过的节点的左右孩纸节点依次加入到队尾
			if(pointer->leftChild){
				nodeQueue.push(pointer->leftChild);
			}
			if(pointer->rightChild){
				nodeQueue.push(pointer->rightChild);
			}

		}
	}

	void levelOrder(ThreadBinaryTreeNode<T> *root)       //  按层次遍历以root为根节点的子树(广度优先遍历算法)
	{
		queue<ThreadBinaryTreeNode<T>*> nodeQueue;      //用队列来存放将要访问的节点
		ThreadBinaryTreeNode<T> * pointer =root;
		if(pointer){
			nodeQueue.push(pointer);              //若根节点非空，将根节点移入队列
		}
		else{
			cout<<"树为空。"<<endl;
		}
		while(!nodeQueue.empty())
		{
			pointer = nodeQueue.front();       //读取队首节点
			visit(pointer);              //访问当前节点
			nodeQueue.pop();                      //将访问过的节点移除队列
			//    将访问过的节点的左右孩纸节点依次加入到队尾
			if(pointer->leftChild){
				nodeQueue.push(pointer->leftChild);
			}
			if(pointer->rightChild){
				nodeQueue.push(pointer->rightChild);
			}

		}
	}
	void InOrder(ThreadBinaryTreeNode<T >* root){
		stack<ThreadBinaryTreeNode<T>*> nodeStack;              //用栈来存放带访问的节点
		stack<ThreadBinaryTreeNode<T>*> temp;
		ThreadBinaryTreeNode<T> * pointer = root;                      //保存根节点

		while(!nodeStack.empty() || pointer){                  //栈为空时遍历结束
			if(pointer){
				nodeStack.push(pointer);                     //当前节点入栈
				pointer = pointer->leftChild;                //转向访问其左孩子
			}
			else{        //左子树访问完毕，转向访问其右子树
				pointer = nodeStack.top();         //读取栈顶待访问的节点
				visit(pointer);                    //访问当前节点
				temp.push(pointer);
				pointer = pointer->rightChild;     //转向其右孩子
				nodeStack.pop();                   //删除栈顶节点`
			}
		}
		stack<ThreadBinaryTreeNode<T>*> stack;
		while(!temp.empty()){
			ThreadBinaryTreeNode<T> * pointer = temp.top();
			temp.pop();
			if(pointer->leftTag == 1){
				if(temp.empty())
					pointer->leftChild = NULL;
				else
					pointer->leftChild = temp.top();
			}
			if(pointer->rightTag == 1){
				if(stack.empty())
					pointer->rightChild = NULL;
				else
					pointer->rightChild = stack.top();
			}
			stack.push(pointer);
		}
	}
	ThreadBinaryTreeNode<T>* search_qianqu(ThreadBinaryTreeNode<T>* root){
		return root->leftChild;
	}
	ThreadBinaryTreeNode<T>* search_houji(ThreadBinaryTreeNode<T>* root){
		return root->rightChild;
	}


	 void creat(){        //  创建完全二叉树
		queue<ThreadBinaryTreeNode<T>*> nodeQueue;      //用队列来存放将要访问的节点
		ThreadBinaryTreeNode<T> * pointer = root;
		ThreadBinaryTreeNode<T> * pointer_left = NULL;
		ThreadBinaryTreeNode<T> * pointer_right = NULL;
		T value;

		do{
			cin>>value;
			if(root == NULL){
				root =  new ThreadBinaryTreeNode<T>;
				root->setValue(value);
				nodeQueue.push(root);              //若根节点非空，将根节点移入队列
				continue;
			}

			pointer = nodeQueue.front();       //读取队首节点
			if(pointer->leftChild == NULL){
				pointer_left = new ThreadBinaryTreeNode<T>;
				pointer_left->setValue(value);
				pointer->setLeftChild(pointer_left);
				nodeQueue.push(pointer->leftChild);
			}
			else if(pointer->rightChild == NULL){
				pointer_right = new ThreadBinaryTreeNode<T>;
				pointer_right->setValue(value);
				pointer->setRightChild(pointer_right);
				nodeQueue.push(pointer->rightChild);
			}
			if(pointer->leftChild != NULL && pointer->rightChild != NULL){
				nodeQueue.pop();                      //将访问过的节点移除队列
			}

		}while(getchar() != '\n');
	 }
};
#endif /* THREADBINARYTREE_H_ */
