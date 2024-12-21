#include<bits/stdc++.h>
using namespace std;

bool valid_anagram(string s,string t){
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());

	return s==t;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="anagram";
	string t="nagaram";

	cout<<"ANS:"<<valid_anagram(s,t)<<endl;

}