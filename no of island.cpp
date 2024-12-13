#include<bits/stdc++.h>
using namespace std;
int n,m;

void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
	vis[row][col]=1;
	queue<pair<int,int>> q;
	q.push({row,col});

	while(!q.empty()){
		int row=q.front().first;
		int col=q.front().second;
		q.pop();

		for(int deltarow=-1;deltarow<=1;deltarow++){
			for(int deltacol=-1;deltacol<=1;deltacol++){
				int nrow=row+deltarow;
				int ncol=col+deltacol;
				if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
				   grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
					vis[nrow][ncol]=1;
					q.push({nrow,ncol});
				}
			}
		}
	}
}


int numIslands(vector<vector<char>> &grid){
	n=grid.size();
	m=grid[0].size();
	int cnt=0;
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			//cout<<grid[row][col];
			if(!vis[row][col] && grid[row][col]=='1'){
				cnt++;
				bfs(row,col,vis,grid);
			}			
		}
	}
	return cnt;


}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<char>> grid={
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'},
		{'0','0','0','1','1'},
	};


	cout<<"Ans :"<<numIslands(grid);

}