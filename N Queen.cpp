#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> result;
int N;

bool isValid(vector<string> &board,int row,int col){

	for(int i=row-1;i>=0;i--){
		if(board[i][col]=='Q') return false;
	}

	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
		if(board[i][j]=='Q') return false;
	}

	for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){
		if(board[i][j]=='Q') return false;
	}

	return true;

}

void solve(vector<string> &board,int row){
	if(row>=N){
		result.push_back(board);
		return;
	}

	for(int col=0;col<N;col++){
		if(isValid(board,row,col)){
			board[row][col]='Q';
			solve(board,row+1);
			board[row][col]='.';
		}
	}
}


vector<vector<string>> solveNqueen(int n){
	//cout<<"Inside";
	N=n;
	vector<string> board(n,string(n,'.'));
	solve(board,0);
	return result;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<string>> ans;
	ans=solveNqueen(5);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" "<<endl; 
		}
		cout<<endl;
	}
}