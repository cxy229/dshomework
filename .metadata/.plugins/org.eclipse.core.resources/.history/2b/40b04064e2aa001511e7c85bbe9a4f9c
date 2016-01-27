/*
 * Graph.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include"MinHeap.h"
#include"edge.h"
#include"intqueue.h"
#include"ufsets.h"
#include <stdlib.h>
using namespace std;

class AdjGraph
{
	int ** matrix;                    //带权有向图
	int *arr;                         //顶点信息
	int num;
	int *Mark;
public:
	AdjGraph(int* a,int num)
	{
		int i,j;
		arr=new int[num];
		matrix=(int**)new int*[num];
		for(i=0;i<num;i++)
			matrix[i]=new int[num];
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
				matrix[i][j]=0;
		for(i=0;i<num;i++)
			arr[i]=a[i];
		Mark=new int [num];
		this->num=num;
	}

	~AdjGraph()
	{
		for(int i=0;i<num;i++)
			delete []matrix[i];
		delete []matrix;
	}

	bool setEdge(int from,int to,int weight)       //有向图
	{
		if(from<num&&to<num)
		{
			matrix[from][to]=weight;
		}
		else
			return false;
		return true;
	}

	int getNum()
	{return num;}

	int getEdge(int from,int to)
	{
		if(from<num&&to<num)
			return matrix[from][to];
		else
			exit(0);
	}

	void DFS(int v)                                   //DFS
	{
		cout<<arr[v]<<ends;
		Mark[v]=1;
		for(int i=0;i<num;i++)
			if(matrix[v][i]!=0&&Mark[i]==0)
				DFS(i);
	}

	void DFSShow()//DFS算法遍历图
	{
		int i;
		for(i=0;i<num;i++)
			Mark[i]=0;
		for(i=0;i<num;i++)
			if(Mark[i]==0)
				DFS(i);
	}

	void BFS(int v)                             //BFS
	{
		IntQueue Q(num);
		cout<<arr[v]<<ends;
		Mark[v]=1;
		Q.EnQueue(v);
		while(!Q.IsEmpty())
		{
			Q.DeQueue(v);
			for(int i=0;i<num;i++)
				if(matrix[v][i]!=0&&Mark==0)
				{
					cout<<arr[i]<<ends;
					Mark[i]=1;
					Q.EnQueue(i);
				}
		}
	}

	void BFSShow()//BFS算法遍历图
	{
		int v;
		for(v=0;v<num;v++)
			Mark[v]=0;
		for(v=0;v<num;v++)
			if(Mark[v]==0)
				BFS(v);
	}

	Edge* prim(int v)                                  //Prim
	{
		int i;
		Edge e;
		Edge* mini=new Edge[num-1];//储存最小生成树的边
		Minheap<Edge> mp(num*num);

		for(i=0;i<num;i++)
			Mark[i]=0;
		Mark[v]=1;

		for(int j=0;j<num-1;j++)
		{
			for(i=0;i<num;i++)
				if(matrix[v][i]!=0&&Mark[i]==0)
				{
					e.start=v;
					e.end=i;
					e.weight=matrix[v][i];
					mp.insert(e);
				}
			mp.deleteMin(e);

			while(Mark[e.end]!=0&&Mark[e.start]!=0)
			{
				mp.deleteMin(e);
			}

			mini[j]=e;
			v=e.end;
			Mark[v]=1;
			}
		return mini;
	}

	Edge* Kruskal()                                    //Kruskal
	{
		UFSets set(num);
		Edge* mini=new Edge[num-1];
		Minheap<Edge> mp(num*num);
		Edge e;
		int i,j;
		int edgeNum=0;

		for(i=0;i<num;i++)
			Mark[i]=0;

		for(i=0;i<num;i++)
		{
			Mark[i]=1;
			for(j=0;j<num;j++)
				if(matrix[i][j]!=0&&Mark[j]==0)
				{
					e.start=i;
					e.end=j;
					e.weight=matrix[i][j];
					mp.insert(e);
				}
		}

		while(edgeNum<num-1)
		{
			if(!mp.isEmpty())
			{
				mp.deleteMin(e);
				if(!set.Find(e.start,e.end))
				{
					mini[edgeNum++]=e;
					set.Union(e.start,e.end);
				}
			}
			else
				exit(0);
		}
		return mini;
	}

	void Dijkstra(int v,int path[],int dis[])
	{
		int i,j;
		int min=-1;
		for(i=0;i<num;i++)
		{
			Mark[i]=0;
			path[i]=-1;
			dis[i]=0;
		}

		path[v]=0;
		Mark[v]=1;
		for(i=0;i<num;i++)
		{

			for(j=0;j<num;j++)
				if(Mark[j]==0)
				{
					if(min==-1)
					{
						dis[j]=matrix[v][j];
						if(dis[j]!=0)
							path[j]=v;
					}
					else if(dis[min]!=0&&matrix[v][j]!=0&&(dis[j]==0||dis[j]>dis[min]+matrix[v][j]))
					{
						dis[j]=dis[min]+matrix[v][j];
						path[j]=min;
					}
				}

			min=-2;
			for(j=0;j<num;j++)
			{
				if(Mark[j]==0)
				{
					if(min<0)
						min=j;
					else if(dis[j]!=0&&dis[j]<dis[min])
						min=j;
				}
			}

			Mark[min]=1;
			v=min;
		}
	}

	void Floyd(int** adj,int** path)
	{
		int i,j,v;

		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
			{
				adj[i][j]=matrix[i][j];
				path[i][j]=i;
			}
		for(v=0;v<num;v++)
			for(i=0;i<num;i++)
				for(j=0;j<num;j++)
				{
					if(adj[i][v]!=0&&adj[v][i]!=0)
						if(adj[i][j]>adj[i][v]+adj[v][j])
						{
							adj[i][j]=adj[i][v]+adj[v][j];
							path[i][j]=v;
						}
				}
	}
};




#endif /* GRAPH_H_ */
