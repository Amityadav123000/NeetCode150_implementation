#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

bool solve(string &s,int i,int j){
	if(i>=j) return true;

	if(t[i][j]!=-1) return t[i][j];

	if(s[i]==s[j]) return t[i][j]=solve(s,i+1,j-1);

	return t[i][j]=false;
}

string longestPalindrome(string s){
	int n=s.length();

	int maxLen=INT_MIN;
	int startingIndex=0;
	memset(t,-1,sizeof(t));

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){

			if(solve(s,i,j)){
				if(j-i+1>maxLen){
					startingIndex=i;
					maxLen=j-i+1;
				}
			}

		}
	}
	return s.substr(startingIndex,maxLen);

}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s="babad";
	cout<<longestPalindrome(s)<<endl;
}