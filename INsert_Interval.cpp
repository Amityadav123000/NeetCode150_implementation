#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,vector<int> &newIntervals){
	int i=0;
	vector<vector<int>> result;
	int n=intervals.size();

	while(i<n){
		if(intervals[i][1]<newIntervals[0]){
			result.push_back(intervals[i]);
		}else if(intervals[i][0]>newIntervals[1]){
			break;
		}else{
			newIntervals[0]=min(newIntervals[0],intervals[i][0]);
			newIntervals[1]=max(newIntervals[1],intervals[i][1]);
		}
		i++;
	}

	result.push_back(newIntervals);
	while(i<intervals.size()){
		result.push_back(intervals[i]);
		i++;
	}

	return result;

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> intervals= {{1,3},{6,9}};
	vector<int> newIntervals= {2,5};

	vector<vector<int>> ans;
	ans=insert(intervals,newIntervals);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}