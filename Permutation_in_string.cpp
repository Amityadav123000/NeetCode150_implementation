#include<bits/stdc++.h>
using namespace std;

bool checkPermut(string s1,string s2){
	if(s1.size() > s2.size()) return false;

	vector<int> s1Count(26,0),s2Count(26,0);

	for(int i=0;i<s1.size();i++){
		s1Count[s1[i]-'a']++;
		s2Count[s2[i]-'a']++;
	}

	for(int i=0;i<s2.size()-s1.size();i++){
		if(s1Count == s2Count) return true;
		s2Count[s2[i]-'a']--;
		s2Count[s2[i+s1.size()] - 'a']++;
	}

	return s1Count==s2Count;

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s1="ab";
	string s2="eidbaooo";

	cout<<"ANS :"<<checkPermut(s1,s2);

}