#include<bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> intervals={{1,2},{2,3},{3,4},{1,3}};
	cout<<"ANS :"<<eraseOverLappingIntervals(vector<vector<int>> &intervals);

}