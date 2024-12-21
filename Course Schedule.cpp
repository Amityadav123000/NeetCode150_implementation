#include<bits/stdc++.h>
using namespace std;

bool topo(unordered_map<int,vector<int>> &adj,int n,vector<int> &Indegree){
	queue<int> q;
	int count=0;

	for(int i=0;i<n;i++){
		if(Indegree[i]==0){
			count++;
			q.push(i);
		}
	}

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto &neigh:adj[front]){
			Indegree[neigh]--;
			if(Indegree[neigh]==0){
				count++;
				q.push(neigh);
			}
		}
	}

	if(count==n) return true;
	return false;


}


bool canFinish(int numCourses,vector<vector<int>> &prerequisite){
	unordered_map<int,vector<int>> adj;
	vector<int> Indegree(numCourses,0);

	for(auto &vec:prerequisite){
		int u=vec[0];
		int v=vec[1];
		adj[v].push_back(u);
		Indegree[u]++;
	}

	return topo(adj,numCourses,Indegree);
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> prerequisite={{1,0},{0,1}};
	cout<<"ANS :"<<canFinish(2,prerequisite);
}