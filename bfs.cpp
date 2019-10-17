#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cout<<"Enter number of vertices:  ";
	cin>>N;
	
	// Adjacency Matrix
	
	int W[N][N];
	
	cout<<"Enter Adjacency Matrix: \n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin>>W[i][j];
	}
	
	queue <int> q;
	int visited[N]={0};
	
	int source;
	cout<<"Enter Starting vertex: ";
	cin>>source;
	
	visited[source]=1;
	
	q.push(source);
	
	cout<<"BFS: ";
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout<<v<<" " ;
		for(int i=0;i<N;i++){
			if(visited[i]==0 && W[v][i]==1){
				q.push(i);
				visited[i]=1;
			}
			
		}
		
	}
	cout<<endl;
	
	return 0;
	
	
}
/*

0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0


0 1 1 1 0
1 0 1 0 0
1 1 0 0 1
1 0 0 0 0
0 0 1 0 0

*/