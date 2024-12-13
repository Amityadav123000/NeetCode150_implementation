#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>&nums){
	int l=0;
	int r=0;
	int ans=0;
	int maxJump=0;

	int n=nums.size();

	while(r<n-1){
		for(int i=l;i<=r;i++){
			maxJump=max(maxJump,i+nums[i]); 
		}
		ans++;
		l=r+1;
		r=maxJump;
	}
	return ans;

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

vector<int> nums={2,3,1,1,4};
cout<<"ANS ="<<jump(nums);

}