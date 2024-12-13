#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>&points,int k){
	priority_queue<pair<int,vector<int>>> maxHeap;

	for(auto point:points){
		int x=point[0];
		int y=point[1];
		int distance=x*x+y*y;

		maxHeap.push({distance,point});

		if(maxHeap.size()>k) maxHeap.pop(); 
	}

	vector<vector<int>> res;

	while(!maxHeap.empty()){
		res.push_back(maxHeap.top().second);
		maxHeap.pop();
	}

	return res;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector<vector<int>> ans;
	vector<vector<int>> points={{3,3},{5,-1},{-2,4}};
	ans=kClosest(points,2);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}