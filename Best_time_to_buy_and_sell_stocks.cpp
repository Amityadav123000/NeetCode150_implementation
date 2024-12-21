#include<bits/stdc++.h>
using namespace std;

int maxProffit(vector<int> &prices){
	int mini=INT_MAX;
	int profit=INT_MIN;
	int ans=0;

	for(int i=0;i<prices.size();i++){
		mini=min(prices[i],mini);
		profit=prices[i]-mini;
		ans=max(profit,ans);
	}

	return ans;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> proces={7,1,5,3,6,4};
	cout<<"ANS: "<<maxProffit(proces);
}