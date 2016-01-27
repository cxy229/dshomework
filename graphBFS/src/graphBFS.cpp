#include"AdjGraph.h"
#include<iostream>
using namespace std;
int main()
{
	AdjGraph adjg(3);
	//AdjGraph prim(6);
	int s = 0;
	int e = 0;
	int w = 0;
	cout << "请输入起点,终点,权值(起点为-1时结束):" << endl;
	cin >> s >> e >> w;
	while (s != -1)
	{
		adjg.setEdge(s, e, w);
		cin >> s >> e >> w;
	}
	cout << "DFS:" << endl;
	adjg.DFS(0);
	cout << endl;
	cout << "BFS:" << endl;
	adjg.BFS(0);
	cout << endl;
//	cout <<"Prim"<< endl;
//	Edge* eg = adjg.Prim(0);
//	adjg.print(eg);
//	cout << endl;
//	cout << "Kruskal:" << endl;
//	Edge* eg1 = adjg.Kruskal();
//	adjg.print(eg1);
	//adjg.out();
	return 0;
}
