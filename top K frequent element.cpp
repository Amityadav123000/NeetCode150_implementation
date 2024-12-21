#include<bits/stdc++.h>
using namespace std;

vector<int> topKfrequentElement(vector<int> &nums,int k){
	int n=nums.size();

	unordered_map<int,int> mpp;

	for(int &num:nums){
		mpp[num]++;
	}

	vector<vector<int>> bucket(n+1);

	for(auto &it:mpp){
		int element=it.first;
		int freq=it.second;
		bucket[freq].push_back(element);
	}

	vector<int> result;

	for(int i=n;i>=0;i--){
		if(bucket[i].size()==0){
			continue;
		}

		while(bucket[i].size()>0 && k>0){
			result.push_back(bucket[i].back());
			bucket[i].pop_back();
			k--;
		}
	}

	return result;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> nums={1,1,1,2,2,3};
	vector<int> ans;
	ans=topKfrequentElement(nums,2);
	//cout<<ans.size()<<endl<<endl;
	for(auto it:ans){
		cout<<it<<" ";
	}
}