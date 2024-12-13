#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int target,int i,int sum){
	if(i>=nums.size()) return target==sum;

	int a=solve(nums,target,i+1,sum+nums[i]);
	int b=solve(nums,target,i+1,sum-nums[i]);

	return a+b;
}
	
int findTargetSumWays(vector<int>& nums, int target){
	return solve(nums,target,0,0);
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,1,1,1,1,1,1,1};
	int target=2;

	
	cout<<"ANS ="<<findTargetSumWays(nums,target);

}