/*
 * AdjGraph.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef ADJGRAPH_H_
#define ADJGRAPH_H_

#include "Graph.h"
#include"MinHeap.h"
class UFSets//等价类,从最初一个元素构成一个等价类到最终把所有元素合并为一个等价类
{
private:
	int n;//等价类中元素个数
	int* root;//root[i]表示等价类中i元素的代表元素
	int* next;//next[i]表示等价类中i元素的下一个元素编号
	int* length;//length[i]表示i所在等价类的元素个数
public:
	UFSets(int n);
	int Find(int v)//等价类的代表元素
	{
		return root[v];
	}
	void Union(int v, int u);//合并v,u所在等价类
};
class AdjGraph :public Graph
{
private:
	int** matrix;
public:
	AdjGraph();
	AdjGraph(int vertexnum);
	~AdjGraph();
	void setEdge(int start, int end, int weight);
	void delEdge(int start, int end);
	Edge firstEdge(int vertex);//顶点第一条边
	Edge nextEdge(Edge e);//同一顶点下一条边
	void DFS(int i);//深度优先遍历
	void BFS(int i);//广度优先遍历
	void print(Edge* e);//输出最小生成树中边的所有信息
	Edge* Prim(int s);//最小生成树的Prim算法
	Edge* Kruskal();//最小生成树Kruskal算法
	void out();//输出矩阵形式
};



#endif /* ADJGRAPH_H_ */
