/*
 * Graph.h
 *
 *  Created on: Dec 17, 2015
 *      Author: cxy229
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include<iomanip>//声明一些流操作符
using namespace std;
//最大权值
#define MAXWEIGHT 100

//用邻接矩阵实现图
class Graph
{
public:
	//numV顶点数，isWeighted是否带权值，isDirected是否有向
	Graph(int numV, bool isWeighted , bool isDirected );
	//建图
	void createGraph();
	~Graph();
	//获取顶点数
	int GetVernums()
	{
		return numV;
	}
	//获取边数
	int GetEdgeS()
	{
		return numE;
	}
	//设定给定边的权值
	void setEdgeWeight(int start, int end, int weight);
	//打印邻接矩阵
	void printAdjacentMatrix();
	//检查输入
	bool check(int i, int j, int w=1 );
private:
	//是否带权
	bool isWeighted;
	//是否有向
	bool isDirected;
	//顶点数
	int numV;
	//边数
	int numE;
	//邻接矩阵
	int **matrix;//指向邻接矩阵的指针
};
//构造方法，numV顶点数，isWeighted是否带权值，isDirected是否有向
Graph::Graph(int numV, bool isWeighted , bool isDirected )
{
		this->numV = numV;
		this->isWeighted = isWeighted;
		this->isDirected = isDirected;
		this->numE = 0;
		matrix = new int *[numV];//指针数组
		int i, j;
		for (i = 0; i < numV; i++)
			matrix[i] = new int[numV];
		//对图进行初始化
		if (!isWeighted)//无权图
		{
			//所有权值初始化为0
			for (i = 0; i < numV; i++)
			{
				for (j = 0; j < numV; j++)
					matrix[i][j] = 0;
			}
		}
		else //有权图
		{
			//所有权值初始化为最大权值
			for (i = 0; i < numV; i++)
			{
				for (j = 0; j < numV; j++)
					matrix[i][j] = MAXWEIGHT;
			}
		}

}
//建图
void Graph::createGraph()
{
	cout << "输入边数:";
	while (cin >> numE && numE < 0)
		cout << "输入有误！，重新输入 ";

	int i, j, w;
	this->numE = numE;
	if (!isWeighted)  //无权图
	{
		if (!isDirected)  //无向图
		{
			cout << "输入每条边的起点和终点：\n";
			for (int k = 0; k < numE; k++)
			{
				cin >> i >> j;
				while (!check(i, j))
				{
					cout << "输入的边不对！重新输入\n";
					cin >> i >> j;
				}
				matrix[i][j] = matrix[j][i] = 1;
			}
		}
		else  //有向图
		{
			cout << "输入每条边的起点和终点：\n";
			for (int k = 0; k < numE; k++)
			{
				cin >> i >> j;
				while (!check(i, j))
				{
					cout << "输入的边不对！重新输入\n";
					cin >> i >> j;
				}
				matrix[i][j] = 1;
			}
		}
	}
	else  //有权图
	{
		if (!isDirected)   //无向图
		{
			cout << "输入每条边的起点、终点和权值：\n";
			for (int k = 0; k < numE; k++)
			{
				cin >> i >> j >> w;
				while (!check(i, j, w))
				{
					cout << "输入的边不对！重新输入\n";
					cin >> i >> j >> w;
				}
				matrix[i][j] = matrix[j][i] = w;
			}
		}
		else  //有向图
		{
			cout << "输入每条边的起点、终点和权值：\n";
			for (int k = 0; k < numE; k++)
			{
				cin >> i >> j >> w;
				while (!check(i, j, w))
				{
					cout << "输入的边不对！重新输入\n";
					cin >> i >> j >> w;
				}
				matrix[i][j] = w;
			}
		}
	}
}

//析构方法
Graph::~Graph()
{
	int i = 0;
	for (i = 0; i < numV; i++)
		delete[] matrix[i];
	delete[] matrix;
}
//设置指定边的权值
void Graph::setEdgeWeight(int start, int end, int weight)
{
	if (isWeighted)//有权图
	{
		while (!check(start, end, weight))
		{
			cout << "输入不正确，重新输入边的起点，终点和权值" << endl;
			cin >> start >> end >> weight;
		}
		if (isDirected)
			matrix[start][end] = weight;
		else
			matrix[start][end] = matrix[start][end] = weight;
	}
	else//无权图
	{
		while (!check(start, end, 1))
		{
			cout << "输入不正确，重新输入边的起点和终点" << endl;
			cin >> start >> end;
		}
		if (isDirected)
			matrix[start][end] = (weight!=0)?1:0;
		else
			matrix[start][end] = matrix[end][start] = (weight!=0)?1:0;
	}
}
//检查输入是否有误
bool Graph::check(int i, int j, int w )
{
	if (i >= 0 && i < numV && j >= 0 && j<numV && w>0 && w <= MAXWEIGHT)
		return true;
	else
		return false;
}
//打印邻接矩阵
void  Graph::printAdjacentMatrix()
{
	int i, j;
	cout.setf(ios::left);
	cout << setw(4) << " ";
	for (i = 0; i < numV; i++)
		cout << setw(4) << i;
	cout << endl;
	for (i = 0; i < numV; i++)
	{
		cout << setw(4) << i;
		for (j = 0; j < numV; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}




#endif /* GRAPH_H_ */
