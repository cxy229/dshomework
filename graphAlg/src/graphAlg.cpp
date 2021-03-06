#include<iostream>
#include"Graph.h"
#include<iomanip>//声明一些流操作符
using namespace std;
#include "edge.h"
#include "ufsets.h"
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

	cout<<"DFS遍历结果：";
	graph.DFSTraverse();
	cout<<endl;

	cout<<"BFS遍历结果：";
	graph.BFSTraverse();
	cout<<endl;

	Edge *e;
	e=graph.prim(0);
	cout<<endl<<"Prim最小生成树："<<endl;
	for(int i=0;i<graph.GetVernums()-1;i++)
		cout<<"("<<e[i].start<<","<<e[i].end<<")"<<" weight:"<<e[i].weight<<endl;

	e=graph.Kruskal();
		cout<<endl<<"Kruskal最小生成树："<<endl;
		for(int i=0;i<graph.GetVernums()-1;i++)
			cout<<"("<<e[i].start<<","<<e[i].end<<")"<<" weight:"<<e[i].weight<<endl;

	int path[100],dis[100];
	cout<<endl<<"Dijkstra单源最短路径："<<endl;
	graph.Dijkstra(0,path,dis);
	for(int i=0;i<graph.GetVernums();i++)
		cout<<i<<"  ";
	cout<<endl;
	for(int i=0;i<graph.GetVernums();i++)
		cout<<dis[i]<<"  ";
	cout<<endl;

	cout<<endl<<"Floyd :"<<endl;
	int **ad,**p;
	ad=(int**)new int*[graph.GetVernums()];
	p=(int**)new int*[graph.GetVernums()];
	for(int i=0;i<graph.GetVernums();i++)
	{
		ad[i]=new int[graph.GetVernums()];
		p[i]=new int[graph.GetVernums()];
	}
	graph.Floyd(ad,p);
	cout<<"Adj :"<<endl;
	for(int i=0;i<graph.GetVernums();i++)
	{
		for(int j=0;j<graph.GetVernums();j++)
			cout<<ad[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Path :"<<endl;
	for(int i=0;i<graph.GetVernums();i++)
	{
		for(int j=0;j<graph.GetVernums();j++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
//	int res[10];
//	graph.circle(res);
//	cout<<"其中一条回路：";
//	for(int i=0;i<graph.GetVernums();i++)
//	{
//		cout<<res[i]<<" ";
//	}
//	cout<<endl;

	int res[10][10];
	cout<<"其中一条回路：";
	graph.ToploySort();


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
