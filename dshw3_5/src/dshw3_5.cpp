#include <iostream>
using namespace std;
#include<queue>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"


int main() {
	BinaryTree<char> bintree;
	cout<<"前序遍历结果：";bintree.preOrder(bintree.getRoot());
	cout<<endl;
	bintree.count();//统计度为0,1,2的结点个数
	cout<<"高度为"<<bintree.getHigh(bintree.getRoot())<<endl;//统计高度
	cout<<"宽度为"<<bintree.getWidth(bintree.getRoot())<<endl;//统计宽度
	cout<<"最大的元素值为"<<bintree.getMax(bintree.getRoot())<<endl;//计算最大值
	bintree.swop(bintree.getRoot());//交换
	cout<<"交换之后前序遍历结果：";bintree.preOrder(bintree.getRoot());
	cout<<endl;
	bintree.clearLeaf(bintree.getRoot());//删去叶子
	cout<<"删去叶子后前序遍历结果：";bintree.preOrder(bintree.getRoot());
	return 0;
}
