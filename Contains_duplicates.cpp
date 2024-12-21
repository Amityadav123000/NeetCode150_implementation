#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums){
	int n=nums.size();
	unordered_map<int,int> mpp;

	for(int i=0;i<n;i++){
		mpp[nums[i]]++;
		if(mpp[nums[i]]>=2) return true;
	}

	return false;

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,1,1,3,3,4,3,2,4,2};
	cout<<"ANS :"<<containsDuplicate(nums)<<endl;
}