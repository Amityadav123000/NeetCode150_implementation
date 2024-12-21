#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;

void twoSum(vector<int> &nums,int target,int i,int j){
	while(i<j){
		if(nums[i]+nums[j] < target) i++;
		else if (nums[i]+nums[j] > target) j--;
		else{
			while(i<j && nums[i]==nums[i+1]) i++;
			while(i<j && nums[j]==nums[j-1]) j--;

			result.push_back({-target,nums[i],nums[j]});
			i++;
			j--;
		}
	}
}

vector<vector<int>> threeSum(vector<int> &nums){
	int n=nums.size();
	if(n<3) return {};
	sort(nums.begin(),nums.end());

	for(int i=0;i<n;i++){
		if(i>0 && nums[i]==nums[i-1]) continue;

		int n1=nums[i];
		int target=-n1;

		twoSum(nums,target,i+1,n-1);
	}
	return result;
}



int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={-1,0,1,2,-1,-4};
	vector<vector<int>> res;
	res=threeSum(nums);

	for(auto it: res){
		for(auto out:it){
			cout<<out<<" ";
		}
		cout<<endl;
	}

}