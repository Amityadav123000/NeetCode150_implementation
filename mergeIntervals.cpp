#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>&intervals){
	vector<vector<int>> mergeIntervals;
	if(intervals.size()==0){
		return mergeIntervals;
	}

	sort(intervals.begin(),intervals.end());
	vector<int> tempInterval=intervals[0];

	for(auto it:intervals){
		if(it[0]<=tempInterval[1]){
			tempInterval[1]=max(it[1],tempInterval[1]);
		}else{
			mergeIntervals.push_back(tempInterval);
			tempInterval=it; 
		}
	}
	
	mergeIntervals.push_back(tempInterval);
	return mergeIntervals;

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> ans;

	ans=merge(intervals);
	//cout<<ans.size()<<"  "<<ans[0].size()<<endl<<endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}