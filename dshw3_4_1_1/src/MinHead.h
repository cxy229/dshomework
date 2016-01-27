#ifndef MINHEAD_H_
#define MINHEAD_H_

#include <iostream>
using namespace std;

template <typename T>
class MinHead
{
    T* heap_array;
    int size;   //当前元素个数
    int max;    //最大容量
public:
    MinHead();
    MinHead(T* arr, int num, int max);
    int parent(int kid);
    bool empty();
    bool leaf(int pos);
    int search(T a);            //查找
    void insert(T a);           //插入
    void del(T a);              //删除
    void build();               //构建最大堆
    void sift_up(int pos);
    void sift_down(int pos);
    T top();                    //返回堆顶元素
    void pop();                 //删除堆顶元素
    void sort();                //最大堆排序
    void show();
    ~MinHead();
};

template <typename T>
MinHead<T>::MinHead()
{
    heap_array = NULL;
    size = 0;
    max = 0;
}
template <typename T>
MinHead<T>::MinHead(T* arr, int num, int m)
{
    size = num;
    max = m;
    heap_array = new T[max];
    for(int i = 0; i<size; i++)
        heap_array[i] = arr[i];
}
template <typename T>
bool MinHead<T>::empty()
{
    if(size == 0)
        return true;
    return false;
}
template <typename T>
bool MinHead<T>::leaf(int pos)
{
    if( pos>(size-2)/2 && pos<size )
        return true;
    return false;
}
template <typename T>
void MinHead<T>::build()         //筛选法构建最小堆
{
    for(int i=size/2-1; i>=0; i--)
        sift_down(i);
}
template <typename T>
void MinHead<T>::sift_up(int pos)
{
    int i = pos;
    int j = parent(pos);
    T temp = heap_array[pos];
    while(temp < heap_array[j]  &&  j >= 0)
    {
        heap_array[i] = heap_array[j];
        i = j;
        j = parent(i);
    }
    heap_array[i] = temp;
}
template <typename T>
void MinHead<T>::sift_down(int pos)
{
    int i = pos;
    int j = i * 2 + 1;
//    j = (heap_array[j] < heap_array[j+1]) ? j : j+1;  //   找出左右结点中最小的那个
    T temp = heap_array[i];
    while(heap_array[j] < temp  &&  i <= size/2-1)
    {
        j = i*2+1;
        j = (heap_array[j] < heap_array[j+1]) ? j : j+1;
        heap_array[i] = heap_array[j];
        i = j;
    }
    heap_array[i] = temp;
}
template <typename T>
int MinHead<T>::parent(int kid)
{
    if(kid == 0)
        return -1;
    return (kid - 1) / 2;
}
template <typename T>
void MinHead<T>::insert(T a)       //插入
{
    if(size == max)
    {
        cout<<"full!"<<endl;
        return ;
    }
    size++;
    heap_array[size-1] = a;
    sift_up(size-1);
}
template <typename T>
int MinHead<T>::search(T a)          //查找
{
    for(int i=0; i<size; i++)
    {
        if(heap_array[i]==a)
            return i;
    }
    return -1;
}
template <typename T>
void MinHead<T>::del(T a)          //删除
{
    if(size == 0)
    {
        cout<<"empty!"<<endl;
        return ;
    }
    int tag = search(a);
    if(tag < 0)   //找不到
        return ;
    heap_array[tag] = heap_array[size-1];   //覆盖
    size--;
    //当新覆盖结点小于它的父结点，向上调整
    if(parent(tag) >= 0 && heap_array[tag] > heap_array[parent(tag)])
        sift_up(tag);
    else
        sift_down(tag);
}
template <typename T>
T MinHead<T>::top()
{
    return heap_array[0];
}
template <typename T>
void MinHead<T>::pop()              //删除堆顶元素
{
    del(heap_array[0]);
}
template <typename T>
void MinHead<T>::sort()                //堆排序
{
    cout<<heap_array[0]<<" ";
    while(!empty())
    {
        del(heap_array[0]);
        cout<<heap_array[0]<<" ";
    }
    cout<<endl;
}
template <typename T>
void MinHead<T>::show()
{
    for(int i=0; i<size; i++)
        cout<<heap_array[i]<<' ';
    cout<<endl;
}
template <typename T>
MinHead<T>::~MinHead()
{
    if(heap_array!=NULL)
        delete []heap_array;
}

#endif /* MINHEAD_H_ */
