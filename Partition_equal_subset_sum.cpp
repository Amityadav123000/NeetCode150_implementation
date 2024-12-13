#include<bits/stdc++.h>
using namespace std;

bool solve(int idx,vector<int>&nums,int n,int total){
	vector<vector<int>> dp(n+1,vector<int>(total+1,0));

	for(int i=0;i<=n;i++) dp[i][0]=1;

	for(int i=n-1;i>=0;i--){
		for(int t=0;t<=total/2;t++){
			int inc=0;
			if(t-nums[i]>=0) inc=dp[i+1][t-nums[i]];

			int exc=dp[i+1][t-0];

			dp[i][t]=inc|| exc;
		}
	}	

	return dp[0][total/2];
}

bool canPartition(vector<int> &nums){
	int n=nums.size();
	int total=0;
	for(int i=0;i<n;i++){
		total+=nums[i];
	}

	if(total%2!=0) return false;
	int tagret=total/2;

	return solve(0,nums,n,total);

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,5,11,5};
	bool ans=canPartition(nums);

	cout<<"ANS = "<<ans<<endl;

}