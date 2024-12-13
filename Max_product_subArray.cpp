#include<bits/stdc++.h>
using namespace std;

int subArraySum(vector<int>&a){
	int prefix=1;
	int suffix=1;
	int ans=INT_MIN;

	for(int i=0;i<a.size();i++){
		if(prefix==0) prefix=1;\
		if(suffix==0) suffix=1;

		prefix=prefix*a[i];
		suffix=suffix*a[a.size()-i-1];

		ans=max(ans,max(prefix,suffix));
	}

	return ans;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> arr={1,-2,3,-4};
	cout<<"Ans = "<<subArraySum(arr)<<endl;
}