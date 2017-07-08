#include <bits/stdc++.h>
#include <list>
#include "component.h"

using namespace std;

extern int componentnum;

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v+1];
}

void Graph::insertedge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
	return ;
}

void Graph::deleteedge(int x, int y){
	//code
	adj[x].remove(y);
	adj[y].remove(x);
	
}

void Graph::bfs(int start,int visited[]){

	queue<int> q;
	q.push(start);
	visited[start] = componentnum;
	list<int>::iterator itr;
	while(!q.empty()){
		int x = q.front();
		q.pop();

		for(itr = adj[x].begin();itr != adj[x].end();itr++){

			if(!visited[*itr]){
				visited[*itr] = componentnum;
				q.push(*itr);
			}
		}
	}

}

bool Graph::processA(int start, int end, int visited[]){
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
	componentnum++;
	for(int i=0;i<temp.size();i++){
		visited[temp[i]] = componentnum;
	}

	return false;
}

bool Graph::connectivity(int comp1, int comp2){
	
	if(comp1 == comp2) return true;

	return false;

}

