#include <bits/stdc++.h>
#include "component.h"

using namespace std;
int componentnum = 0;
int main(int argc, char const *argv[])
{
	/* code */
	int n,m; // n = number of vertices, m = number of edges

	cin >> n >> m ;

	Graph g(n);

	int uu,vv;

	for (int i = 0; i < m; ++i)
	{
		cin >> uu >> vv;
		g.insertedge(uu,vv);
	}

	int visited[n+1];	
	memset(visited,0,sizeof(visited));
	//int componentnum = 0;

	for(int i=1;i<=n;i++){

			if(!visited[i]){
				componentnum++;
				g.bfs(i,visited);
			}

	}

//	for(int i=1;i<=n;i++){
//		cout << visited[i] << " ";
//	}

	cout << endl;

	cout << "Enter following options: " << endl ;		

	int option = 0;
	int xx,yy;
	while(1){
		cout << "1) Delete edge   2) are u and v in same component ?  3) exit " << endl;	
		cin >> option;

		if(option == 1){
			cout << "Enter two vertices: " << endl;
 			cin >> xx >> yy;
			g.deleteedge(xx,yy);
			bool cc = g.processA(xx,yy,visited);
		}
		else if(option == 2){
			cout << "Enter two vertices: " << endl;
			cin >> xx >> yy ;
			if( g.connectivity(visited[xx],visited[yy]) )
				cout << "present is same component";
			else cout << "not present in same component";

			cout << endl;	
		}
		else break;
	}

	//cout << "Hello world" << endl;
	return 0;
}
