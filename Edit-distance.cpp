#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
	if(i<0) return j+1;
	if(j<0) return i+1;

	if(dp[i][j]!=-1) return dp[i][j];

	if(s1[i]==s2[j]) return dp[i][j] = solve(i-1,j-1,s1,s2,dp);

	int del=1+solve(i,j-1,s1,s2,dp);
	int upd=1+solve(i-1,j,s1,s2,dp);
	int rep=1+solve(i-1,j-1,s1,s2,dp);

	return dp[i][j]=min(del,min(upd,rep));
}


int minDistance(string word1, string word2) {
	int n=word1.size();
	int m=word2.size();
	vector<vector<int>> dp(n+1,(vector<int>(m+1,-1)));
	return solve(n,m,word1,word2,dp);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string word1="horse";
	string word2="ros";

	cout<<"ANS ="<<minDistance(word1,word2);


}