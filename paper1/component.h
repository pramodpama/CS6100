#ifndef COMPONENT_H
#define COMPONENT_H

#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph{
	int v; // number of vertices
	list<int> *adj;
public:
	Graph(int);
	void insertedge(int x,int y);
	void bfs(int start,int []);
	bool processA(int start, int end, int []); // this is bfs algorithm to check if edge deletion breaks a component
	bool connectivity(int comp1, int comp2);
	void deleteedge(int x, int y);
};

#endif 