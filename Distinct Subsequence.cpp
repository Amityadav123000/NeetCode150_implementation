#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
	
	if(j<0) return 1;
	if(i<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	if(s[i]==t[j]){
		return dp[i][j]=solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);		
	}else{
		return dp[i][j]=solve(i-1,j,s,t,dp);
	}

}


int numDistinct(string s, string t) {
	int n=s.size();
	int m=t.size();

	vector<vector<int>> dp(n,vector<int>(m,-1));
	return solve(n-1,m-1,s,t,dp);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="babgbag";
	string t="bag";

	cout<<"ANS ="<<numDistinct(s,t);

}