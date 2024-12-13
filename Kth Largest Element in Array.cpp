#include<bits/stdc++.h>
using namespace std;

int partition_algo(vector<int>&nums,int L,int R){
	int P=nums[L];
	int i=L;
	int j=R;

	while(i<=j){
		if(nums[i]<P && nums[j]>P){
			swap(nums[i],nums[j]);
			i++;
			j--;
		}

		if(nums[i]>=P) i++;

		if(nums[j]<=P) j--;
	}

	swap(nums[L],nums[j]);
	return j;
}

int findKthLargest(vector<int> &nums,int k){

	int n=nums.size();
	int L=0;
	int R=n-1;
	int pivot_idx=0;

	while(true){
		pivot_idx=partition_algo(nums,L,R);

		if(pivot_idx==k-1){
			break;
		}else if(pivot_idx>k-1){
			R=pivot_idx-1;
		}else{
			L=pivot_idx+1;
		}
	}

	return nums[pivot_idx];

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={3,2,3,1,2,4,5,5,6};
	cout<<"ANS ="<<findKthLargest(nums,4);

}