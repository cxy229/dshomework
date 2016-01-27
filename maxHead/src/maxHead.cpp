#include<iostream>
using namespace std;

template <class T>
class MaxHeap
{
private:
	T *heapArray;         //  存放堆数据的数组
	int CurrentSize;      //  当前堆中元素数目
	int MaxSize;          //  堆所能容纳的最大元素数目
public:
	MaxHeap(T* Array,int num,int max){
		heapArray = Array;
		CurrentSize = num;
		MaxSize = max;
	}
	~MaxHeap(){

	};
	void BuildHeap();
	bool isLeaf(int pos) const;    //  如果是叶子节点，返回TRUE
	int leftchild(int pos) const{  // 返回左孩子位置
		return pos * 2 + 1;
	}
	int rightchild(int pos) const{ // 返回右孩子位置
		return pos * 2 + 2;
	}
	int parent(int pos) const{     // 返回父节点位置
		return (pos - 1) / 2;
	}
	bool Remove(int pos,T& node);  // 删除给定下标的元素
	void SiftDown(int left);       // 筛选法函数，参数left表示开始处理的数组下标
	void SiftUp(int position);     // 从position向上开始调整，使序列成为堆
	bool Insert(const T& newNode); // 向堆中插入新元素newNode
	void MoveMax();                // 从堆顶移动最大值到尾部
	void RemoveMax();                // 从堆顶删除最大值
	void show(){
		if(CurrentSize == 0){
			cout<<"The Heap is Empty!"<<endl;
		}
		else{
			int i;
			for(i = 0;i < CurrentSize;i++){
				cout<<heapArray[i]<<"  ";
			}
			cout<<endl;
		}
	}
};
 template <class T>
 void MaxHeap<T>::BuildHeap()
 {
	 int i;
	 for(i = CurrentSize/2 - 1;i >= 0;i--){
		SiftDown(i);
	 }
 }

 template <class T>
 void MaxHeap<T>::SiftDown(int left)
 {
	int i = left;                    //  标识父节点
	int j = 2 * i + 1;               //  标识左子节点
	T temp = heapArray[i];           //  保存父节点的关健码
	//  过筛
	while(j < CurrentSize){
		if((j < CurrentSize - 1) && (heapArray[j] < heapArray[j + 1])){
			j++;   //  如果该节点有右孩子且右孩子的关健码大于左孩子的关健码时，j指向右子节点
		}

		if(temp < heapArray[j]){     // 该节点的关健码小于左右孩子中比较大的那个时
			heapArray[i] = heapArray[j];  // 交换对应值
			i = j;
			j = 2 * j + 1;              //  向下继续判断是否满足最大堆的性质
		}
		else{
			break;
		}
	}
	heapArray[i] = temp;
 }

  template <class T>
  void MaxHeap<T>::RemoveMax()
  {
	  if(CurrentSize == 0){  //空堆情况
		  cout<<"Can't Delete!"<<endl;
		  return;
	  }
	  else{
		heapArray[0] = heapArray[CurrentSize - 1];   //  将堆低元素上升至堆顶
		CurrentSize--;                               // 堆中元素数量减一
		if(CurrentSize > 1){                         // 堆中元素个数大于1时才需要调整
			SiftDown(0);                             // 从堆顶开始筛选
		}
		//return temp;
	  }
  }

  int main()
  {
  	int Array[] = {20,12,35,15,19,80,30,17,2,1};
  	MaxHeap<int> maxHeap(Array,10,15);
  	maxHeap.BuildHeap();
  	maxHeap.show();
  	maxHeap.RemoveMax();
  	maxHeap.show();
  	return 0;
  }
