#include<bits/stdc++.h>
using namespace std;

int kadaneMax(vector<int> &nums,int n){
	int sum=nums[0];
	int maxSum=nums[0];

	for(int i=1;i<n;i++){
		sum=max(sum+nums[i],nums[i]);
		maxSum=max(sum,maxSum);
	}

	return maxSum;
}

int kadaneMin(vector<int> &nums,int n){
	int sum=nums[0];
	int minSum=nums[0];

	for(int i=1;i<n;i++){
		sum=min(sum+nums[i],nums[i]);
		minSum=min(sum,minSum);
	}

	return minSum;
}

int maxSubArraySumCircular(vector<int> &nums){
	int n=nums.size();

	int SUM=accumulate(begin(nums),end(nums),0);

	int miniSum=kadaneMin(nums,n);
	int maxSum=kadaneMax(nums,n);
	int circular_sum=SUM-miniSum;

	if(maxSum>0) return max(maxSum,circular_sum);
	return maxSum;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,-2,3,-2};
	cout<<"ANS ="<<maxSubArraySumCircular(nums)<<endl;
}