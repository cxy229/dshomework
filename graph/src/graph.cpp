#include<iostream>
#include"Graph.h"
#include<iomanip>//声明一些流操作符
using namespace std;

int main()
{
	cout << "******使用邻接矩阵实现图结构******" << endl;
	bool isDirected, isWeighted;
	int numV;
	cout << "建图" << endl;
	cout << "输入顶点数:";
	cin >> numV;
	cout << "边是否带权值，输入0(不带) or 输入 1(带):";
	cin >> isWeighted;
	cout << "是否是有向图，输入0(无向) or 输入 1(有向):";
	cin >> isDirected;
	Graph graph(numV, isWeighted, isDirected);
	cout << "这是一个";
	isDirected ? cout << "有向、" : cout << "无向、";
	isWeighted ? cout << "有权图" << endl : cout << "无权图" << endl;
	graph.createGraph();
	cout << "输出邻接矩阵" << endl;
	graph.printAdjacentMatrix();
	cout << endl;

//	int tail, head, weight;
//	cout << "修改指定边的权值" << endl;
//	cout << "输入边的起点、终点和权值 ";
//	cin >> tail >> head >> weight;
//	graph.setEdgeWeight(tail, head, weight);
//	cout << "修改成功！" << endl;
//
//	cout << "输出邻接矩阵" << endl;
//	graph.printAdjacentMatrix();
	return 0;
}