#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &h,vector<vector<bool>> &vis,int i,int j){
	int m=h.size();
	int n=h[0].size();

	vis[i][j]=true;

	if(i-1>=0 && vis[i-1][j] != true && h[i-1][j]>=h[i][j]){
		dfs(h,vis,i-1,j);
	}

	if(i+1<m && vis[i+1][j] != true && h[i+1][j]>=h[i][j]){
		dfs(h,vis,i+1,j);
	}

	if(j-1>=0 && vis[i][j-1] != true && h[i][j-1]>=h[i][j]){
		dfs(h,vis,i,j-1);
	}

	if(j+1<n && vis[i][j+1] != true && h[i][j+1]>=h[i][j]){
		dfs(h,vis,i,j+1);
	}



}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
	vector<vector<int>> ans;
	int m=heights.size();
	int n=heights[0].size();

	vector<vector<bool>> pacific(m,vector<bool>(n));
	vector<vector<bool>> atlntic(m,vector<bool>(n));

	for(int i=0;i<m;i++){
		dfs(heights,pacific,i,0);
		dfs(heights,atlntic,i,n-1);
	}

	for(int j=0;j<n;j++){
		dfs(heights,pacific,0,j);
		dfs(heights,atlntic,m-1,j);
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){

			if(pacific[i][j] && atlntic[i][j]){
				ans.push_back({i,j});
			}
		}
	}
	return ans;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> heights = {
		{1,2,2,3,5},
		{3,2,3,4,4},
		{2,4,5,3,1},
		{6,7,1,4,5},
		{5,1,1,2,4}};


	vector<vector<int>> ans;
	ans=pacificAtlantic(heights);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}	
}