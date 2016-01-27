/*
 * eage.h
 *
 *  Created on: Dec 18, 2015
 *      Author: cxy229
 */

#ifndef EDGE_H_
#define EDGE_H_

class Edge
{
public:
	int start;
	int end;
	int weight;
	Edge(){
		start = 0;
		weight=0;
		end = 0;
	}
	Edge(int st,int en,int w)
	{
		start=st;
		end=en;
		weight=w;
	}
	bool operator >(Edge other)
	{
		return weight>other.weight;
	}
	bool operator <(Edge other)
	{
		return weight<other.weight;
	}
	void operator =(Edge other)
	{
		start=other.start;
		end=other.end;
		weight=other.weight;
	}
};



#endif /* EDGE_H_ */
