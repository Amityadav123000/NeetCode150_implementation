#include<bits/stdc++.h>
using namespace std;
int m,n,N;

bool solve(int i,int j,int k,string &s1,string &s2,string &s3){
	if(i==m && j==n && k==N) return true;

	if(k>=N) return false;

	bool result=false;

	if(s1[i]==s3[k]){
		result=solve(i+1,j,k+1,s1,s2,s3);
	}

	if(s2[j]==s3[k]){
		result=solve(i,j+1,k+1,s1,s2,s3);
	}

	return result;
}

bool isInterleave(string s1,string s2,string s3){
		m=s1.size();
		n=s2.size();
		N=s3.size();

		return solve(0,0,0,s1,s2,s3);
	}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string s1="aabcc";
	string s2="dbbca";
	string s3="aadbbcbcac";

	cout<<"ANS ="<<isInterleave(s1,s2,s3);

}