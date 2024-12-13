#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void solve(vector<int> &nums,int idx,vector<int> &temp){
	if(idx>=nums.size()){
		result.push_back(temp);
		return;
	}

	temp.push_back(nums[idx]);
	solve(nums,idx+1,temp);
	temp.pop_back();
	solve(nums,idx+1,temp);
}

vector<vector<int>> subsets(vector<int>&nums){
	vector<int> temp;
	solve(nums,0,temp);
	return result;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,2,3};
	vector<vector<int>> ans;

	ans=subsets(nums);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}