#include<bits/stdc++.h>
using namespace std;
int t[101];

int solve(int idx,int n,vector<int> &nums){
	if(idx>=n) return 0;
	
	if(t[idx]!=-1) return t[idx];

	int steal=nums[idx] + solve(idx+2,n,nums);
	int nonSteal=0+solve(idx+1,n,nums);

	return t[idx]=max(steal,nonSteal);

}

int rob(vector<int>& nums){
	memset(t,-1,sizeof(t));
	int n=nums.size();
	return solve(0,n,nums);
}	


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={2,7,9,3,1};
	cout<<rob(nums)<<endl;

}