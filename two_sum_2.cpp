#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>&nums,int target){
	int left=0;
	int right=nums.size()-1;

	while(left<right){
		int sum=nums[left]+nums[right];

		if(sum==target){
			return {nums[left],nums[right]};
		}else if(sum<target) left++;
		else right--;
	}

	return {-1,-1};
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={2,7,11,15};
	vector<int> ans;
	ans=twoSum(nums,9);

	for(auto &it:ans){
		cout<<it<<" ";
	}

}