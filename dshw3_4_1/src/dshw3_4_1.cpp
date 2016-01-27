#include <iostream>
using namespace std;
#include "minHead.h"



int main() {
	int Array[] = {20,12,35,15,19,80,30,17,2,1};
	MinHeap<int> minHeap(Array,10,15);
	minHeap.BuildHeap();
	minHeap.show();
	minHeap.RemoveMin();
	minHeap.show();
	minHeap.Insert(0);
	minHeap.show();
	return 0;
}
