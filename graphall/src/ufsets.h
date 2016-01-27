/*
 * ufsets.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef UFSETS_H_
#define UFSETS_H_


class UFSets
{
	int n;
	int* root;
	int* next;
	int* length;
public:
	UFSets(int size)
	{
		n=size;
		root=new int[size];
		next=new int[size];
		length=new int[size];
		for(int i=0;i<n;i++)
		{
			root[i]=next[i]=i;
			length[i]=1;
		}
	}

	int Find(int v){return root[v];}

	bool Find(int v,int u)	{	return root[v]==root[u];}

	void Union(int v,int u)
	{
		int rt;
		if(Find(v,u))
			return;
		else if(length[root[v]]<length[root[u]])
		{
			int i;
			rt=root[v];
			length[root[u]]+=length[root[v]];
			root[rt]=root[u];
			for(int i=next[rt];i!=rt;i=next[i])
				root[i]=root[u];
			i=next[rt];
			next[rt]=next[root[u]];
			next[root[u]]=i;
		}
		else
		{
			int i;
			rt=root[u];
			length[root[v]]+=length[root[u]];
			root[rt]=root[v];
			for(int i=next[rt];i!=rt;i=next[i])
				root[i]=root[v];
			i=next[rt];
			next[rt]=next[root[u]];
			next[root[u]]=i;
		}
	}
};


#endif /* UFSETS_H_ */
