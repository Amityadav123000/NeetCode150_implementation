#include<bits/stdc++.h>
using namespace std;

int merge(int *parent,int x){
	if(parent[x]==x) return x;
	return merge(parent,parent[x]);

}

int connectedcomponents(int n,vector<vector<int>> &edges){
	int parent[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	


}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n=5;
	vector<int> e1={0,1};
	vector<int> e2={2,1};
	vector<int> e3={3,4};

	vector<vector<int>> e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);

	cout<<"Following are connected components:\n";
	int a=connectedcomponents(n,e);
	return 0;

}