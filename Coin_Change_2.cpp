#include<bits/stdc++.h>
using namespace std;

int solve(int i,vector<int> coins,int amount){
	
	if(amount==0) return dp[i][amount]=1;
	if(i==n || amount<0) return dp[i][amount]=0;

	
}


int change(int amount,vector<int> &coins){
	n=coins.size();
	memset(dp,-1,sizeof(dp));
	return solve(0,coins,amount);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int amount=5;
	vector<int> coins={1,2,5};

	cout<<"ANS : "<<change(amount,coins)<<endl;
}