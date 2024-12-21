#include<bits/stdc++.h>
using namespace std;

void remove_redundant(int x,int y,vector<int>&rank,vector<int>&parent){
	if(rank[x]>rank[y]) parent[x]=y;
	else if(rank[x]<rank[y]) parent[y]=x;
	else{
		parent[y]=x;
		rank[x]++;
	}
}

int findUper(int node,vector<int> &parent){
	if(node==parent[node]) return node;
	return parent[node]=findUper(parent[node],parent);
}


vector<int> findRedundantConnection(vector<vector<int>> &edges){
	int n=edges.size();
	vector<int> rank(n+1,0);
	vector<int> parent(n+1);
	int x,y;

	for(int i=1;i<=n;i++) parent[i]=i;
	
	for(auto it:edges){
		x=findUper(it[0],parent);
		y=findUper(it[1],parent);

		if(x==y) return it;
		else remove_redundant(x,y,rank,parent);
	}		

	return {};
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
	vector<int> ans;
	ans=findRedundantConnection(edges);

	for(auto it:ans){
		cout<<it<<" ";
	}

}