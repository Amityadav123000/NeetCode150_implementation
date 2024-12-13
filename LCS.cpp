#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int f(string s1,string s2,int i,int j){
	if(i>=s1.size()) return 0;
	if(j>=s2.size()) return 0;
	
	if(dp[i][j]!=-1) return dp[i][j];

	int ans=0;
	if(s1[i]==s2[j]) return ans=1+f(s1,s2,i+1,j+1);
	else ans=max({f(s1,s2,i+1,j),f(s1,s2,i,j+1)});

	return dp[i][j]=ans;
}

int LCS(string s1,string s2){
dp.clear();
dp.resize(1005,vector<int>(1005,-1));
return f(s1,s2,0,0);
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s1="abcde";
	string s2="ace";

	cout<<LCS(s1,s2)<<endl;

}