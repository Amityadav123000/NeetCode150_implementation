#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums){
	int n=nums.size();
	vector<int> t(n,1);
	int maxL=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(nums[j]<nums[i]){
				t[i]=max(t[i],t[j]+1);
				maxL=max(maxL,t[i]);
			}
		}
	}

	return maxL;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={10,9,2,5,3,7,101,18};
	cout<<"ANS = "<<lengthOfLIS(nums)<<endl;
}