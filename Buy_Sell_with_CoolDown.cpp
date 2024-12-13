#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices,int day,int n,int buy,vector<vector<int>> &dp){
	if(day>=n) return 0;

	int profit=0;
	if(dp[day][buy]!=-1) return dp[day][buy];

	if(buy){
		int take=solve(prices,day+1,n,false,dp)-prices[day];
		int not_take=solve(prices,day+1,n,true,dp);
		profit=max({profit,take,not_take});
	}else{
		int sell=solve(prices,day+2,n,true,dp) + prices[day];
		int not_sell=solve(prices,day+1,n,false,dp);
		profit=max({profit,sell,not_sell});
	}

	return dp[day][buy]=profit;		
}

int maxProfit(vector<int> &prices){
	int n=prices.size();
	vector<vector<int>> dp(5001,vector<int>(2,-1));
	return solve(prices,0,n,true,dp);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> prices={1,2,3,0,2};
	cout<<"ANS = "<<maxProfit(prices)<<endl;
}