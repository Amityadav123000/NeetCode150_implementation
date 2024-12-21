#include<bits/stdc++.h>
using namespace std;

int orangeRotting(vector<vector<int>> &grid){
	if(grid.size()==0) return 0;
	int freshOrange=0;
	int row=grid.size();
	int col=grid[0].size();
	int time=0;

	vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
	queue<pair<int,int>> que;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(grid[i][j]==1) freshOrange++;
			else if(grid[i][j]==2) que.push({i,j});
		}
	}

	while(!que.empty() && freshOrange!=0){
		int size=que.size();
		for(int i=0;i<size;i++){
			auto front=que.front();
			que.pop();
			int x=front.first;
			int y=front.second;

			for(auto dir:direction){
				int new_x=x+dir[0];
				int new_y=y+dir[1];

				if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y] == 1){
					grid[new_x][new_y]=2;
					freshOrange--;
					que.push({new_x,new_y});
				}
			}
		}
		time++;
	}

	return freshOrange==0?time:-1;



}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> grid={{2,1,1},{0,1,1},{0,1,1}};
	cout<<"ANS :"<<orangeRotting(grid);
}