#include<bits/stdc++.h>
using namespace std;

vector<string> result;

void solve(int idx,string &digit,string &temp,unordered_map<char,string> &mpp){

	if(idx>=digit.length()){
		result.push_back(temp);
		return;
	}

	char ch=digit[idx];
	string str=mpp[ch];

	for(int i=0;i<str.length();i++){
		temp.push_back(str[i]);
		solve(idx+1,digit,temp,mpp);
		temp.pop_back();
	}

}


vector<string> letterCombinations(string digit){

	if(digit.length()==0) return {};

	unordered_map<char,string> mp;

	mp['2']="abc";
	mp['3']="def";
	mp['4']="ghi";
	mp['5']="jkl";
	mp['6']="mno";
	mp['7']="pqrs";
	mp['8']="tuv";
	mp['9']="wxyz";

	string temp="";

	solve(0,digit,temp,mp);

	return result;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string digit="234";
	vector<string> ans;
	ans=letterCombinations(digit);

	cout<<"ANS ="<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

}