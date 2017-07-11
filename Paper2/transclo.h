#ifndef TRANSCLO_H
#define TRANSCLO_H

#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph{
	int v; // number of vertices
	list<int> *adj;
public:
	Graph(int);
	void reachability(int compname[], int start);
	void insertedge(int x,int y);
	bool updatetree(int start, int end, int visited[]);
	bool connectivity(int comp1, int comp2);
	void deleteedge(int, int);
};

void shortestpaths(int v);

#endif