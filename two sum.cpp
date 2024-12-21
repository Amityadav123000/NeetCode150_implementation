#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums,int target){
	unordered_map<int,int> mpp;

	for(int i=0;i<nums.size();i++){
		int sum=target-nums[i];
		if(mpp.find(sum)!=mpp.end()){
			return {nums[i],nums[mpp[sum]]};
		}
		mpp[nums[i]]=i;
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

	for(auto it:ans){
		cout<<it<<" ";
	}

}