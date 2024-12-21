#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int n,int m){
	return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int i,int j,vector<vector<char>> &board,vector<vector<int>> &directions,int n,int m){
	if(!isSafe(i,j,n,m) || board[i][j]!='O') return;

	board[i][j]='F';

	for(auto dir:directions){
		int new_i=i+dir[0];
		int new_j=j+dir[1];
		dfs(new_i,new_j,board,directions,n,m);
	}
}



void solve(vector<vector<char>> &board){
	int n=board.size();
	int m=board[0].size();
	vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
				dfs(i,j,board,directions,n,m);
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]=='O') board[i][j]='X';
			else if(board[i][j]=='F') board[i][j]='O';
		}
	}


}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<char>> board = 
	{{'X','X','X','X'},
	 {'X','O','O','X'},
	 {'X','X','O','X'},
	 {'X','O','X','X'}};

	 solve(board);

	 for(int i=0;i<board.size();i++){
	 	for(int j=0;j<board[0].size();j++){
	 		cout<<char(board[i][j])<<' '; 
	 	}
	 	cout<<endl;
	 }


}