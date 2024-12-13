#include<bits/stdc++.h>
using namespace std;

string findOrder(string dict[],int N,int K){
	vector<int> adj[K];
	vector<int> indegree(K);

	for(int i=0;i<N-1;i++){
		string s1=dict[i];
		string s2=dict[i+1];
		int len=min(s1.size(),s2.size());
		for(int ptr=0;ptr<len;ptr++){
			if(s1[ptr]!=s2[ptr]){
				adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
				indegree[s2[ptr]-'a']++;
				break;
			}	
		}
	}

	queue<int> q;
	for(int i=0;i<indegree.size();i++){
		if(indegree[i]==0) q.push(i);
	}

	string ans="";
	while(!q.empty()){
		int node=q.front();
		q.pop();
		ans.push_back(char(node+'a'));

		for(auto it:adj[node]){
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}


	return ans;



}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int N=5;
	int K=4;
	string dict[]={"baa","abcd","abcaa","cab","cad"};
	string res=findOrder(dict,N,K);
	cout<<res<<endl;

}