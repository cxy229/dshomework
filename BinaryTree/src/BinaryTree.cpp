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
template <class T>
class BinaryTree{
private:
    BinaryTreeNode<T>* root;
public:
    BinaryTree();
    BinaryTree(BinaryTreeNode<T>* rt);
    ~BinaryTree();

    BinaryTreeNode<T>* createTree(BinaryTreeNode<T>* root);
    void visit(BinaryTreeNode<T>* root);

    bool isEmpty() const;
    BinaryTreeNode<T>* getRoot() const;
    BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* current) const;
    BinaryTreeNode<T>* getLeftSubling(BinaryTreeNode<T>* current) const;
    BinaryTreeNode<T>* getRightSubling(BinaryTreeNode<T>* current) const;

    void breadthFirstOrder(BinaryTreeNode<T>* root);
    void preOrder(BinaryTreeNode<T>* root);
    void inOrder(BinaryTreeNode<T>* root);
    void postOrder(BinaryTreeNode<T>* root);
    void levelOrder(BinaryTreeNode<T>* root);
    void deleteBinaryTree(BinaryTreeNode<T>* root);
};
template <class T>
BinaryTree<T>::BinaryTree(){
	BinaryTreeNode<T>* rt = NULL;
	root = createTree(rt);
}
template <class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* rt){
	root = rt;
}
template <class T>
BinaryTree<T>::~BinaryTree(){
	root = NULL;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::createTree(BinaryTreeNode<T>* root){
	char ele;
	cout<<"请按先序输入结点数据（直接回车表示该结点为空）：";
	cin>>ele;			//按先序建立二叉树
	if(ele == '#')
	{
		root = NULL;	//置为NULL后结束
		return root;
	}
	root = new(BinaryTreeNode<T>);
	root->element = ele;
	root->leftChild = createTree(root->leftChild);
	root->rightChild = createTree(root->rightChild);
	return root;
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* root){
	cout<<root->element;
}
template <class T>
bool BinaryTree<T>::isEmpty() const{
	if (root == NULL){
		return true;
	}else{
		return false;
	}
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const{
	return root;
}
//template <class T>
//BinaryTreeNode<T>* BinaryTree<T>::getParent(BinaryTreeNode<T>* current) const{
//	return root;
//}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getLeftSubling(BinaryTreeNode<T>* current) const{
	return current->leftChild;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRightSubling(BinaryTreeNode<T>* current) const{
	return current->rightChild;
}
template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root){
    using std::queue;
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;

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
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root){
    if(root != NULL){
        visit(root);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}
template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root){
	if(root != NULL){
		inOrder(root->leftChild);
		visit(root);
		inOrder(root->rightChild);
	}
}
template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root){
	if(root != NULL){
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		visit(root);
	}
}

int main() {
	BinaryTree<char> bintree;
	bintree.preOrder(bintree.getRoot());
	cout<<endl;
	bintree.inOrder(bintree.getRoot());
	cout<<endl;
	bintree.postOrder(bintree.getRoot());
	cout<<endl;
    return 0;
}
