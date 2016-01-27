#include "Graph.h"
#define INF 1000000

Edge::Edge()
{
}

Edge::Edge(int start, int end, int weight)
{
	this->start = start;
	this->end = end;
	this->weight = weight;
}

bool Edge::operator>(Edge e)
{
	if (weight > e.weight)
		return true;
	return false;
}

bool Edge::operator<(Edge e)
{
	if (weight < e.weight)
		return true;
	return false;
}

void Edge::operator=(Edge e)
{
	start = e.start;
	weight = e.weight;
	end = e.end;
}

ostream& operator<<(ostream& out, Edge& e)
{
	out << "(" << e.start << "," << e.end << "," << e.weight << ")";
	return out;
}

Graph::Graph()
{
}

Graph::Graph(int vertexnum)
{
	this->vertexnum = vertexnum;
	edgenum = 0;
	mark = new int[vertexnum];
	for (int i = 0; i < vertexnum; i++)
		mark[i] = 0;//0表示未访问
}

Graph::~Graph()
{
	if (mark)
		delete[]mark;
}

int Graph::Vertexnum()
{
	return vertexnum;
}

int Graph::Edgenum()
{
	return edgenum;
}

int Graph::startVertex(Edge e)
{
	return e.start;
}

int Graph::endVertex(Edge e)
{
	return e.end;
}

int Graph::Edgeweight(Edge e)
{
	return e.weight;
}

bool Graph::isEdge(Edge e)
{
	if (e.end >= 0 && e.weight > 0 && e.weight < INF)
		return true;
	return false;
}
