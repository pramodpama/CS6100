#include <bits/stdc++.h>
#include "transclo.h"

using namespace std;
#define N 1000
#define MAX 9999

int graph[1000][1000];
int pairs[1000][1000];

int compnum = 0;

int main(int argc, char const *argv[])
{
	int n,m; // n = number of vertices, m = number of edges

	cin >> n >> m ;

	Graph g1(n);
	Graph g2(n);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			pairs[i][j] = MAX;

	int uu,vv;

	for (int i = 0; i < m; ++i)
	{
		cin >> uu >> vv;
		pairs[uu][vv] = 1;
		g1.insertedge(uu,vv);
		g2.insertedge(vv,uu);
	}

	int compname[n+1];	// use for reachability set
	for(int i=0;i<=n;i++)
		compname[i] = 0;

	for(int i=1;i<=n;i++){

		if(compname[i] == 0){
			compnum++;
			g1.reachability(compname,i);
		}
	}
	
//	for(int i=1;i<=n;i++){
//		cout << compname[i] << " ";
//	}

	cout << "Choose one of the options" << endl;

	int option =0;
	int xx,yy;

	while(1){
		cout << "1) Delete edge   2) Is there a path from u to v ?  3) shortest path(distace) from u to v  4) Exit" << endl;	
		cin >> option;

		if(option == 1){
			cout << "Enter two vertices: " << endl;
 			cin >> xx >> yy;
			g1.deleteedge(xx,yy);
			bool cc = g1.updatetree(xx,yy,compname);
			pairs[xx][yy] = MAX;
			shortestpaths(n);

		}
		else if(option == 2){
			cout << "Enter two vertices: " << endl;
			cin >> xx >> yy ;
			if( g1.connectivity(compname[xx],compname[yy]) )
				cout << "Yes";
			else cout << "No";

			cout << endl;	
		}
		else if(option == 3){
			cout << "Enter two vertices: " << endl;
			cin >> xx >> yy ;

			if(pairs[xx][yy] == MAX)
				cout << " path does not exist" << endl;
			else cout << "shortest distace = " << pairs[xx][yy] << endl;
		}

		else break;
	}



	return 0;
}