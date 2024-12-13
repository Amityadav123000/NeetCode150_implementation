#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix,int row,int col,int prev,vector<vector<int>> &dp){
	
	if(row<0 || col <0 || row>=matrix.size() || col >=matrix[0].size()) return 0;
	if(matrix[row][col]<=prev) return 0;

	if(dp[row][col]!=-1) return dp[row][col];

	int up=solve(matrix,row-1,col,matrix[row][col],dp);
	int down=solve(matrix,row+1,col,matrix[row][col],dp);
	int left=solve(matrix,row,col-1,matrix[row][col],dp);
	int right=solve(matrix,row,col+1,matrix[row][col],dp);

	return dp[row][col] = 1 + max({up,down,left,right});


}


int longestIncreasingPath(vector<vector<int>> &matrix){
	vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));

	int ans=-1;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			ans=max(solve(matrix,i,j,-1,dp),ans);
		}
	}

	return ans;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> matrix={{3,4,5},{3,2,6},{2,2,1}};

	cout<<"ANS ="<<longestIncreasingPath(matrix);



}