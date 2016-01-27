#include "AdjGraph.h"
#include<iostream>
#include<stack>
#include<queue>
#define INF 10000
using namespace std;

UFSets::UFSets(int n)
{
	this->n = n;
	root = new int[n];
	next = new int[n];
	length = new int[n];
	for (int i = 0; i < n; i++)
	{
		root[i] = i;//每个元素独立成为等价类，代表元素为其本身
		next[i] = i;//每个元素独立成为等价类，下一个元素编号为其本身
		length[i] = 1;//每个元素独立成为等价类，长度均为1
	}
}

//合并v,u所在等价类
void UFSets::Union(int v, int u)
{
	if (root[v] == root[u])
	{
		cout << v << u << "两元素在同一个等价类中" << endl;
		return;
	}
	else
	{
		if (length[v] < length[u])//当前面元素个数<后面时，合并后的代表元为原u的代表元
		{
			int rt = root[u];//获取u所在等价类的代表元素
			length[rt] += length[v];//更新等价类长度
			//更新代表元素
			for (int j = next[root[v]]; j != root[v]; j = next[j])
				root[j] = rt;
			//更新next
			int rtv = next[root[v]];
			next[root[v]] = next[rt];
			next[rt] = rtv;
		}
		else//当前面元素个数>后面时，合并后的代表元为原v的代表元
		{
			int rt = root[v];//获取v所在等价类的代表元素
			length[rt] += length[u];//更新等价类长度
			//更新代表元素
			for (int j = next[root[u]]; j != root[u]; j = next[j])
				root[j] = rt;
			//更新next
			int rtu = next[root[u]];
			next[root[u]] = next[rt];
			next[rt] = rtu;
		}
	}
}

AdjGraph::AdjGraph()
{
}

AdjGraph::AdjGraph(int vertexnum) :Graph(vertexnum)
{
	matrix = new int*[vertexnum];
	int j = 0;
	int k = 0;
	for (; j < vertexnum; j++)
		matrix[j] = new int[vertexnum];
	for (; k < vertexnum;k++)//初始化二维数组
	for (j = 0; j < vertexnum; j++)
		matrix[k][j] = 0;
}

AdjGraph::~AdjGraph()
{
	for (int i = 0; i < Vertexnum(); i++)
		delete[]matrix[i];
	delete[]matrix;
}

void AdjGraph::setEdge(int start, int end, int weight)
{
	if (matrix[start][end] == 0)
		edgenum++;
	matrix[start][end] = weight;
	matrix[end][start] = weight;
}

void AdjGraph::delEdge(int start, int end)
{
	if (matrix[start][end] != 0)
		edgenum--;
	matrix[start][end] = 0;
	matrix[end][start] = 0;
}

//顶点第一条边
Edge AdjGraph::firstEdge(int vertex)
{
	Edge temp;
	temp.start = vertex;
	for (int i = 0; i < vertexnum;i++)
	if (matrix[temp.start][i] != 0)
	{
		temp.end = i;
		temp.weight = matrix[temp.start][i];
		break;
	}
	return temp;
}

//同一顶点下一条边
Edge AdjGraph::nextEdge(Edge e)
{
	Edge temp;
	temp.start = e.start;
	for (int i = e.end + 1; i < vertexnum;i++)
	if (matrix[temp.start][i] != 0)
	{
		temp.end = i;
		temp.weight = matrix[temp.start][i];
		break;
	}
	return temp;
}

//深度优先遍历
void AdjGraph::DFS(int i)
{
	stack<int> s;
	//初始化mark
	for (int ii = 0; ii < Vertexnum(); ii++)
		mark[ii] = 0;
	//对每一个结点开始访问
	for (; i < Vertexnum(); i++)
	{
		if (mark[i] == 0)
		{
			s.push(i);                                      //遍历顺序不是我想要的啊！！！！！
			cout << i << " ";
			mark[i] = 1;
			while (!s.empty())
			{
				int j = s.top();
				cout << j << " " ;
				mark[j] = 1;
				s.pop();
				for (Edge e = firstEdge(j); isEdge(e); e = nextEdge(e))
				{
					int k = e.end;
					if (mark[k] == 0 && j<k)
					{
						s.push(k);
						cout << k << " " << endl;
						mark[k] = 1;
					}
				}
			}
		}
	}
}

//广度优先遍历
void AdjGraph::BFS(int i)
{
	queue<int> q;
	//初始化mark
	for (int ii = 0; ii < Vertexnum(); ii++)
		mark[ii] = 0;
	//对每一个结点开始访问
	for (; i < Vertexnum(); i++)
	{
		if (mark[i] == 0)
		{
			q.push(i);
			cout << i << " ";
			mark[i] = 1;
			while (!q.empty())
			{
				int j = q.front();
				cout << j << " " ;
				mark[j] = 1;
				q.pop();
				for (Edge e = firstEdge(j); isEdge(e); e = nextEdge(e))
				{
					int k = e.end;
					if (mark[k] == 0)
					{
						q.push(k);
						cout << k << " ";
						mark[k] = 1;
					}
				}
			}
		}
	}
}

//输出最小生成树中边的所有信息
void AdjGraph::print(Edge* e)
{
	int n = Vertexnum();
	for (int i = 0; i < n-1; i++)
	{
		cout << e[i]<<" ";
	}
}

//最小生成树的Prim算法
Edge* AdjGraph::Prim(int s)
{
	int i = 0, j = 0;
	Edge e;
	int n = Vertexnum();//图中结点个数
	Edge* MST = new Edge[n - 1];//存储最小生成树的边,即各个顶点到生成树中的各个顶点的最短边
	int* mark = new int[n];//标记i号顶点是否已加入生成树中,1表示未加入，-1表示已加入
	int* node = new int[n];//记录已加入生成树中的结点
	//初始化nearest和mark
	for (i = 0; i < n; i++)
	{
		mark[i] = 1;
		node[i] = s;
	}
	mark[s] = -1;//将已加入到生成树的点的最近邻设置为0
	for (i = 1; i < n; i++)
	{//i标记已经加入到最小生成树中的点个数
		int min = INF;
		int v = s;//用于计算的最小边起点
		int vv = s;//真实的最小边起点
		int u = s;//用于计算的最小边终点
		int uu = s;//真实的最小边终点
		//遍历生成树中每一个节点，找到权值最小的边
		for (j = 0; j < i; j++)
		{
			v = node[j];//最小边起点
			u = node[j];//最小边终点
			for (e = firstEdge(v); isEdge(e); e = nextEdge(e))
			{
				u = e.end;
				if (mark[u] == 1 && e.weight < min)
				{
					vv = v;
					uu = e.end;
					min = e.weight;
				}
			}
		}
		mark[uu] = -1;
		node[i] = uu;//将终点加入生成树中
		Edge ee(vv, uu, min);
		MST[i - 1] = ee;//将此边加入生成树中
	}
	return MST;
}

//最小生成树Kruskal算法
Edge* AdjGraph::Kruskal()
{
	int i = 0;
	Edge e;
	//把所有边建成最小堆
	int en = Edgenum();//边数
	int vn = Vertexnum();//顶点数
	UFSets set(vn);//vn个结点的等价类
	MinHeap heap(en-1);//en个节点的最小堆
	Edge* MST = new Edge[vn - 1];//存放生成树的边
	for (; i < vn;i++)
	for (e = firstEdge(i); isEdge(e); e = nextEdge(e))
	if (e.start < e.end)//防止无向图重复包含边
		heap.insert(e);
//	heap.print();
	//对于每一条最小边,检查其始点终点是否在同一连通分量中，若不在，则结合成一个,并把该边加入到生成树中
	i = 0;
	while (i < vn-1)
	{//i代表生成树中边数
		if (!heap.isEmpty())
		{
			cout << "heap.print():" << endl;
			heap.print();
			e = heap.delroot();
		//	cout << "heap.print()():" << endl;
			//heap.print();
			cout << "i1=" << i << endl;
		//	cout << "e" << e << endl;
			/*cout << "set.Find(e.start):" << set.Find(e.start) << endl;
			cout << "set.Find(e.end):" << set.Find(e.end) << endl;*/
			if (set.Find(e.start) != set.Find(e.end))
			{
				set.Union(e.start, e.end);
				MST[i] = e;
				i++;
			}
			//cout << "i=" << i << endl;
		}
		else
		{
			cout << "无法构成最小生成树" << endl;
			return NULL;
		}
	}
	cout << "MST:" << endl;
	print(MST);
	return MST;
}

void AdjGraph::out()
{
	for (int i = 0; i < Vertexnum(); i++)
	{
		for (int j = 0; j < Vertexnum(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
