#include<bits/stdc++.h>
using namespace std;

void islandsAndTreasure(vector<vector<int>> &grid){
	int m=grid.size();
	int n=grid[0].size();

	queue<pair<int,int>> q;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==0) q.push({i,j});
		}
	}


	vector<vector<int>> direction={{-1,0},{1,0},{0,-1},{0,1}};

	while(!q.empty()){
		int row=q.front().first;
		int col=q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int r=row + direction[i][0];
			int c=col + direction[i][1];

			if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!=INT_MAX) continue;

			grid[r][c]=grid[row][col]+1;
			q.push({r,c});
		}

	}




}
	


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector<vector<int>> grid={
		{INT_MAX,-1,0,INT_MAX},
		{INT_MAX,INT_MAX,INT_MAX,-1},
		{INT_MAX,-1,INT_MAX,-1},
		{0,-1,INT_MAX,INT_MAX}
	};

	islandsAndTreasure(grid);

	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			cout<<" "<<grid[i][j];
		}
		cout<<endl;
	}

}