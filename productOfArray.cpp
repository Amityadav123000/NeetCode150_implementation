#include<bits/stdc++.h>
using namespace std;

vector<int> productOfArrayExceptSelf(vector<int> &nums){
	int n=nums.size();
	vector<int> result(n,1);

	for(int i=1;i<n;i++){
		result[i]=result[i-1]*nums[i-1];
	}

	int suffix=1;
	for(int i=n-1;i>=0;i--){
		result[i]*=suffix;
		suffix*=nums[i];
	}

	return result;

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,2,3,4};

	vector<int> ans;
	ans=productOfArrayExceptSelf(nums);

	for(auto it:ans){
		cout<<it<<" ";
	}

}