#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height){
	int left=0;
	int right=height.size()-1;
	int maxArea=0;

	while(left<right){
		int currArea=min(height[left],height[right]) * (right-left);
		maxArea=max(maxArea,currArea);

		if(height[left]<height[right]) left++;
		else right--;
	}

	return maxArea;

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,8,6,2,5,4,8,3,7};
	cout<<"ANS :"<<maxArea(nums);
}