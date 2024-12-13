#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> &nums,int index,int range,vector<int> &dp){
	
	if(index>range) return 0;
	if(dp[index]!=-1) return dp[index];

	int include=nums[index]+rec(nums,index+2,range,dp);
	int exclude=0+rec(nums,index+1,range,dp);

	dp[index]=max(include,exclude);

	return dp[index];



}

int rob(vector<int> &nums){
	vector<int> dp1(nums.size()+1,-1);
	vector<int> dp2(nums.size()+1,-1);

	if(nums.size()==1) return nums[0];

	int include=rec(nums,0,nums.size()-2,dp1);
	int exclude=rec(nums,1,nums.size()-1,dp2);

	return max(include,exclude);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,2,3,1};
	cout<<rob(nums)<<endl;
}