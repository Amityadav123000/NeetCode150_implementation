#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> &candidates,int target,vector<int>& curr,int idx,vector<vector<int>>& result){
	if(target<0) return;

	if(target==0){
		result.push_back(curr);
		return;
	}

	for(int i=idx;i<candidates.size();i++){
		if(i>idx && candidates[i]==candidates[i-1]){
			continue;
		}

		curr.push_back(candidates[i]);
		solve(candidates,target-candidates[i],curr,i+1,result);
		curr.pop_back();
	}


}


vector<vector<int>> combinationSum2(vector<int> &candidates,int target){
	vector<vector<int>> result;
	vector<int> curr;

	sort(begin(candidates),end(candidates));

	solve(candidates,target,curr,0,result);

	return result;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> candidates={10,1,2,7,6,1,5};
	vector<vector<int>> ans;
	ans=combinationSum2(candidates,8);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}