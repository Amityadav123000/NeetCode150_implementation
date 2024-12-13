#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums){
	int n=nums.size();
	int maxi=0;

	for(int i=0;i<n;i++){
		if(maxi<i) return false;
		maxi=max(maxi,i+nums[i]);
	}
	return true;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={2,3,1,1,4};
	cout<<"ANS ="<<canJump(nums);
}