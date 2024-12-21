#include<bits/stdc++.h>
using namespace std;

int lengthOfLOngestSubstr(string s){
	int n=s.length();
	unordered_map<char,int> mpp;
	int left=0;
	int right=0;
	int maxLen=0;

	while(right<n){
		mpp[s[right]]++;

		while(mpp[s[right]]>1){
			mpp[s[left]]--;
			left++;
		}

		maxLen=max(right-left+1,maxLen);
		right++;
	}


	return maxLen;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="abcdeabcbb";
	cout<<"ANS :"<<lengthOfLOngestSubstr(s);
}