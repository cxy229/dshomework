#include<iostream>
#include<string>
#include"HosPartNode.h"
#include"Tree.h"
using namespace std;

int main()
{
	Tree tree;
	tree.insert("yiyuan",new HosPartNode(1,"yiyuan"));

	tree.insert("yiyuan",new HosPartNode(10,"louceng"));

	tree.insert("louceng",new HosPartNode(1,"zhongyangdating"));
	tree.insert("louceng",new HosPartNode(4,"peilou"));

	tree.insert("zhongyangdating",new HosPartNode(1,"TV"));
	tree.insert("zhongyangdating",new HosPartNode(2,"sofa"));

	tree.insert("peilou",new HosPartNode(2,"changzoulang"));
	tree.insert("peilou",new HosPartNode(1,"zoulanglianjie"));

	tree.insert("changzoulang",new HosPartNode(21,"bingfang"));

	tree.insert("zoulanglianjie",new HosPartNode(5,"kufang"));

	tree.insert("bingfang",new HosPartNode(1,"washroom"));
	tree.insert("bingfang",new HosPartNode(4,"chazuo"));
	tree.insert("bingfang",new HosPartNode(2,"bingchuang"));

	tree.insert("washroom",new HosPartNode(1,"ximianpen"));
	tree.insert("washroom",new HosPartNode(1,"zuobianqi"));

	tree.insert("chazuo",new HosPartNode(2,"chakou"));
	tree.insert("chazuo",new HosPartNode(1,"mianban"));

//	tree.getParent(tree.Find("bingfang"))->print();
//	tree.Find("bingfang")->print();
//	cout<<endl;
	tree.WithTraverse(tree.getRoot());
	cout<<endl;
	cout<<"每个楼层中病房的数量为 ： "<<tree.count("louceng","bingfang")<<endl;
	return 0;
}
