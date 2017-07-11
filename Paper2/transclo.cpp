#include <bits/stdc++.h>
#include <list>
#include "transclo.h"

using namespace std;
#define N 1000
extern int compnum;
extern int mat[1000][1000];
extern int pairs[1000][1000];

void Graph::reachability(int compname[], int start){

	queue<int> q;
	q.push(start);
	compname[start] = compnum;
	list<int>::iterator itr;
	while(!q.empty()){
		int x = q.front();
		q.pop();

		for(itr = adj[x].begin();itr != adj[x].end();itr++){

			if(!compname[*itr]){
				compname[*itr] = compnum;
				q.push(*itr);
			}
		}
	}

}

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v+1];
}

void Graph::insertedge(int u,int v){
	adj[u].push_back(v);
	return ;
}

void shortestpaths(int v){

	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++){

				if(pairs[i][k]+pairs[k][j] < pairs[i][j])
					pairs[i][j] = pairs[i][k] + pairs[k][j];
			}

	return ;		
}



bool Graph::updatetree(int start, int end, int visited[]){
	queue<int> q;
	q.push(start);
	int visit[v+1];
	memset(visit,0,sizeof(visit));
	visit[start] = 1;
	vector<int> temp;
	bool path = false;
	list<int>::iterator itr;
	while(q.size()!=0){
		int x = q.front();
		temp.push_back(x);
		q.pop();

		for(itr = adj[x].begin();itr!=adj[x].end();itr++){

			if(*itr == end) return true; // path exists (edge deletion does not break into a component)

			if(visit[*itr] == 0){
				visit[*itr] = 1;
				q.push(*itr);
			}
		}
	}
	compnum++;
	for(int i=0;i<temp.size();i++){
		visited[temp[i]] = compnum;
	}

	return false;
}

bool Graph::connectivity(int comp1, int comp2){
	
	if(comp1 == comp2) return true;

	return false;

}

void Graph::deleteedge(int x, int y){
	//code
	adj[x].remove(y);
	
}