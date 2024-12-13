#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>> &grid,int &count,vector<vector<int>> &vis){

	if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] ==0 || vis[i][j] == 1 ){
		return;
	}

	count++;
	vis[i][j]=1;

	dfs(i-1,j,grid,count,vis);
	dfs(i,j+1,grid,count,vis);
	dfs(i,j-1,grid,count,vis);
	dfs(i+1,j,grid,count,vis);

}

int maxAreaIsland(vector<vector<int>> &grid){
	int count=0;
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1 && !vis[i][j]){
				int c=0;
				dfs(i,j,grid,c,vis);
				count=max(count,c);
			}
		}
	}
	return count;

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> grid={
{0,0,1,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0},
{0,1,1,0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,1,1,0,0,1,0,1,0,0},
{0,1,0,0,1,1,0,0,1,1,1,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0}};

cout<<"ANS :"<<maxAreaIsland(grid);


}