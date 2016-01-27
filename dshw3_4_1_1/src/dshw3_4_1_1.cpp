#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "HuffmanTree.h"
using namespace std;

class imgCompressor
{
    HuffmanTree<string> h_tree;
    string* color;  //符号数组
    int* wei;       //权重数组
    int sum;        //符号种类总数
public:
    imgCompressor();
    void calculate();   //计算各符号出现的次数
    void buildTree();   //建树
    void compresse();   //压缩
    void decompresse(); //解压还原
    void run();
    ~imgCompressor();
};
imgCompressor::imgCompressor()
{
    color = NULL;
    wei = NULL;
    sum = 0;
}
string swich(char* c, int n)//从c中读8个字符
{
    string str(c,n);
    return str;
}
void imgCompressor::calculate()
{
    ifstream image("/home/cxy229/image/data.dat",ios::in);
    if(!image.good())    //文件未成功打开
    {
        cerr<<" error:: unable to open image! "<<endl;
        exit(1);
    }

    char temp[65];
    string str="";
    map<string,int> p;
    map<string,int>::iterator i;
    int j = 0, k = 0;
    while(!image.eof())
    {
        image.getline(temp,65);
        for(k = 0; k < 64; k += 8)
        {
            str = swich(temp+k,8);
            p[str]++;
//            cout<<str<<" "<<p[str]<<" ";
        }
//        cout<<endl;
    }
    for(j = 0,i = p.begin() ; i != p.end() ; i++,j++);  //计数
    sum = j;                  //键值对的总数
    color = new string[sum];
    wei = new int[sum];
    for(j = 0, i = p.begin() ; i!=p.end() ; i++,j++)
    {
        color[j] = (*i).first;
        wei[j] = (*i).second;
        cout<<color[j]<<" "<<wei[j]<<" "<<endl;
    }
    image.close();
}
void imgCompressor::buildTree()
{
    h_tree.setTree(wei,color,sum,"");
    h_tree.encode(h_tree.getroot(),"");
}
void imgCompressor::compresse()//图片压缩
{
    ofstream img_com("/home/cxy229/image/img_compressed",ios::app);
    if(!img_com)
    {
        cout<<" fail to open img_compressed"<<endl;
        exit(1);
    }

    ifstream image;
    image.open("/home/cxy229/image/data.dat",ios::in);
    if(!image.good())    //文件未成功打开
    {
        cerr<<" error:: unable to open image! "<<endl;
        exit(1);
    }

    char temp[65];
    string str = "";
    int k = 0;
    while(!image.eof())
    {
        image.getline(temp,65);
        for(k = 0; k < 64; k += 8)
        {
            str = swich(temp + k, 8);
            img_com<<h_tree.coding(str);//将压缩后的编码写入文件
        }
        img_com<<endl;
    }

    image.close();
    img_com.close();
}
void imgCompressor::decompresse()
{
    ifstream img_com;
    img_com.open("/home/cxy229/image/img_compressed");
    if(!img_com.good())    //文件未成功打开
    {
        cerr<<" error:: unable to open img_compressed! "<<endl;
        exit(1);
    }
    ofstream img_decom("/home/cxy229/image/img_decompressed",ios::out|ios::app);
    if(!img_decom)
    {
        cout<<" fail to open img_decom"<<endl;
        exit(1);
    }

    char temp[100];
    string str;
    while(!img_com.eof())
    {
        img_com.getline(temp,99);
        str = swich(temp,strlen(temp));
        //cout<<str;
        img_decom<<h_tree.uncoding(str)<<endl;
    }
    img_com.close();
    img_decom.close();
}
void imgCompressor::run()
{
    calculate();
    buildTree();
    compresse();     //  压缩
    decompresse();   //  解压缩
}
imgCompressor::~imgCompressor()
{
    if(color)
        delete []color;
    if(wei)
        delete []wei;
}

int main()
{
	ifstream image;
	image.open("/home/cxy229/image/data.dat");
    if(!image.good())     //文件未成功打开
    {
        cerr<<" error:: unable to open image! "<<endl;
        exit(1);
    }
    char aaaa[4]={'a','b','c','d'};
    int w[4]={5,6,7,8};
    HuffmanTree<char> test;
    test.setTree(w,aaaa,4,0);
    test.encode(test.getroot(),"");
    cout<<"d:"<<test.coding('d')<<endl;
	cout<<"c:"<<test.coding('c')<<endl;
    cout<<"b:"<<test.coding('b')<<endl;
    cout<<"a:"<<test.coding('a')<<endl;
    cout<<test.uncoding("010110");
    cout<<endl;

    imgCompressor img;
    img.run();
    return 0;
}
