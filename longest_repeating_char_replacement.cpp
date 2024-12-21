#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s,int k){
	int n=s.size();
	int maxL=0;
	int ans=0;
	int l=0;
	int r=0;

	unordered_map<char,int> count;

	while(r<n){
		count[s[r]]++;
		maxL=max(maxL,count[s[r]]);

		if( ((r-l+1) -maxL)  > k){
			count[s[l]]--;
			l++;
		}

		ans=max(ans,r-l+1);
		r++;
	}

	return ans;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="AABABBA";
	cout<<"ANS :"<<characterReplacement(s,1);
}