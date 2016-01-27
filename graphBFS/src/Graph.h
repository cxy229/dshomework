/*
 * Graph.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
using namespace std;
class Edge
{
	friend ostream& operator<<(ostream& out, Edge& h);
public:
	int start, end;
	int weight;//起点，终点，权重
	Edge();
	Edge(int start, int end, int weight);
	bool operator>(Edge e);
	bool operator<(Edge e);
	void operator=(Edge e);
	//friend ostream& operator<<(ostream& out, Edge& e);为什么不能放在这
};
class Graph
{
public:
	int vertexnum;//顶点数
	int edgenum;//边数
	int* mark;//标志顶点是否被访问过
	Graph();
	Graph(int vertexnum);
	~Graph();
	int Vertexnum();
	int Edgenum();
	int startVertex(Edge e);
	int endVertex(Edge e);
	int Edgeweight(Edge e);
	bool isEdge(Edge e);
	virtual void setEdge(int start, int end, int weight) = 0;
	virtual void delEdge(int start, int end) = 0;
	virtual Edge firstEdge(int vertex) = 0;//顶点第一条边
	virtual Edge nextEdge(Edge e) = 0;//同一顶点下一条边
};


#endif /* GRAPH_H_ */
