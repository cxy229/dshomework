#include <iostream>
using namespace std;

template <class T>
void InsertionSort(T data[],int n){//直接插入排序
	int p;
	T temp;
	for(p=1;p<n;p++){
		temp = data[p];
		int i;
		for(i=p-1;i>=0&&data[i]>temp;i--){
				data[i+1]=data[i];
		}
		data[i+1]=temp;
	}
}

template <class T>
void BinaryInsertionSort(T data[],int n){//折半插入排序
	int p;
	T temp;
	int left=0,mid=0,right=0;
	for(p=1;p<n;p++){
		temp = data[p];
		for(left=0,right=p-1;left<=right;){
			mid = (left+right)/2;
			if(temp<data[mid]){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}
		int i;
		for(i=p-1;i>=left;i--){
			data[i+1]=data[i];
		}
		data[left]=temp;
	}
}

template <class T>            //shell排序
void ShellSort(T data[],int n){//d初始化n/2  对以d为间距的所有子序列直接插入排序 d=d/2
	int d;
	for(d=n/2;d>=1;d=d/2){
		int k;
		for(k=0;k<d;k++){
			int p;
			for(p=k+d;p<n;p+=d){//直接插入排序
				int temp = data[p];
				int i;
				for(i=p-d;i>=0&&data[i]>temp;i-=d){
					data[i+d]=data[i];
				}
				data[i+d]=temp;
			}
		}
	}
}

template <class T>
void BubbleSort(T data[],int n){//冒泡排序
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(data[j]<data[j-1]){
				T temp;
				temp=data[j-1];
				data[j-1]=data[j];
				data[j]=temp;
			}
		}
	}
}

int Partition(int a[],int left,int right)
{
	int pivot = a[left];
	while (left < right&&a[right] > pivot)
	{
		right--;
	}
	a[left] = a[right];
	while (left < right&&a[left] <= pivot)
	{
		left++;
	}
	a[right] = a[left];
	a[left] = pivot;
	return left;
}
void QuickSort(int a[], int left,int right)//快速排序
{
	if (left < right)
	{
		int p = Partition(a, left, right);
		QuickSort(a, left, p - 1);
		QuickSort(a, p + 1, right);
	}

}
void SelectionSort(int a[], int n)//简单选择排序
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[k])
				k = j;
		}
		if (k != i - 1)
		{
			int t = a[k];
			a[k] = a[i - 1];
			a[i - 1] = t;
		}
	}
}

void Merge(int a[], int start,int mid,int end)
{
	int len1 = mid - start + 1, len2 = end - mid;
	int i, j, k;
	int* left = new int[len1];//临时数组存放数据
	int* right = new int[len2];//临时数组存放数据
	for (i = 0; i < len1; i++)
		left[i] = a[i + start];//数据复制操作
	for (i = 0; i < len2; i++)
		right[i] = a[i + mid+1];//数据复制操作
	i = 0; j = 0;
	for (k = start; k < end; k++)
	{
		if (i == len1 || j == len2)
			break;
		if (left[i] <= right[j])
			a[k] = left[i++];
		else
			a[k] = right[j++];
	}
	while (i < len1)
		a[k++] = left[i++];
	while (j < len2)
		a[k++] = right[j++];
	delete[]left;
	delete[]right;
}

void MergeSort(int a[], int start, int end)//归并排序
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, start, mid, end);
	}
}
int main() {
	int data[10]={10,8,7,4,5,4,3,2,1,0};

//	InsertionSort<int>(data,10);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;

//	BinaryInsertionSort<int>(data,10);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;
//
//	ShellSort<int>(data,10);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;

//	BubbleSort<int>(data,10);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;

//	QuickSort(data,0,9);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;

//	SelectionSort(data,10);
//	for(int i=0;i<10;i++){
//		cout<<data[i]<<",";
//	}
//	cout<<endl;

	MergeSort(data,0,9);
	for(int i=0;i<10;i++){
		cout<<data[i]<<",";
	}
	cout<<endl;
	return 0;
}
