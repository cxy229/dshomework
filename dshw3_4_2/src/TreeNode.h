/*
 * treeNode.h
 *
 *  Created on: Dec 4, 2015
 *      Author: cxy229
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#include<iostream>
#include<string>
#include"HosPartNode.h"
using namespace std;
class TreeNode
{
private:
	HosPartNode *m_value;
	TreeNode *rSibling;    //  其右兄弟的指针
	TreeNode *lSibling;    //  最左边的子节点的指针
public:
	TreeNode(HosPartNode *value){
		m_value = value;
		rSibling = NULL;
		lSibling = NULL;
	}
	TreeNode(string str){
		m_value = NULL;
		m_value->setName(str);
		m_value->setNum(1);
		rSibling = NULL;
		lSibling = NULL;
	}
	HosPartNode* getValue(){
		return m_value;
	}
	TreeNode* getChild(){
		return lSibling;
	}
	TreeNode* getSibling(){
		return rSibling;
	}

	void setValue(HosPartNode *value){
		m_value = value;
	}
	void setChild(TreeNode *node){
		lSibling = node;
	}
	void setSibling(TreeNode *node){
		rSibling = node;
	}
	void InsertFirst(TreeNode *node){   // 以第一个左孩子身份插入结点

	}
	void InsertNext(TreeNode *node){   // 以其右孩子身份插入结点

	}
	void print(){      // 打印当前结点及左结点的信息
		cout<<m_value->getName()<<" :   "<<m_value->getNum()<<endl;
		cout<<"子节点 : "<<endl;
		if(lSibling){
			cout<<lSibling->getValue()->getName()<<" :   "<<lSibling->getValue()->getNum()<<endl;
			TreeNode *treeNode = lSibling->getSibling();
			while(treeNode){
				cout<<treeNode->getValue()->getName()<<" :   "<<treeNode->getValue()->getNum()<<endl;
				treeNode = treeNode->getSibling();
			}
		}
		else{
			cout<<"无子节点！"<<endl;
		}
	}
};



#endif /* TREENODE_H_ */
