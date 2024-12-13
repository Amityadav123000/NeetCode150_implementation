#include<bits/stdc++.h>
using namespace std;
int n;

bool isPalindrome(string &s,int l,int r){
	while(l<r){
		if(s[l]!=s[r]) return false;
		l++;
		r--;
	}
	return true;
}

void backtrack(string &s,int idx,vector<string> &curr,vector<vector<string>> &result){
	if(idx==n){
		result.push_back(curr);
		return;
	}

	for(int i=idx;i<n;i++){
		if(isPalindrome(s,idx,i)){
			curr.push_back(s.substr(idx,i-idx+1));
			backtrack(s,i+1,curr,result);
			curr.pop_back();
		}
	}
}


vector<vector<string>> partition(string s){
	vector<vector<string>> result;
	vector<string> curr;
	n=s.length();
	backtrack(s,0,curr,result);

	return result;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="aabbaa";
	vector<vector<string>> ans;
	ans=partition(s);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}



}