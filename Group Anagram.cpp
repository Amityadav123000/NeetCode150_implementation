#include<bits/stdc++.h>
using namespace std;

string generate(string &word){
	int arr[26]={0};

	for(auto &ch:word){
		arr[ch-'a']++;
	}

	string new_word="";

	for(int i=0;i<26;i++){
		int freq=arr[i];
		if(freq>0){
			new_word+=string(freq,i+'a');
		}
	}
	return new_word;
}


vector<vector<string>> groupAnagram(vector<string> &strs){
	int n=strs.size();
	unordered_map<string,vector<string>> mpp;

	vector<vector<string>> result;

	for(int i=0;i<n;i++){
		string word=strs[i];
		string new_word=generate(word);
		mpp[new_word].push_back(word);
	}

	for(auto &it:mpp){
		result.push_back(it.second);
	}



	return result;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<string> strs={"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> ans;
	ans=groupAnagram(strs);

	for(auto list:ans){
		for(auto it:list){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}