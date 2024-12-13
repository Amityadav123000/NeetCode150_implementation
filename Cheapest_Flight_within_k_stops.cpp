#include<bits/stdc++.h>
using namespace std;

int cheapestFlight(int n,vector<vector<int>>& flights,int src,int dst,int K){
	vector<int> distance(n,INT_MAX);

	unordered_map<int,vector<pair<int,int>> > adj;

	for(vector<int> &vec:flights){
		int u=vec[0];
		int v=vec[1];
		int cost=vec[2];

		adj[u].push_back({v,cost});
    }
		queue<pair<int,int>> que;
		que.push({src,0});
		distance[src]=0;
		int steps=0;

		while(!que.empty() && steps<=K){
			int N=que.size();
			while(N--){
				int u=que.front().first;
				int d=que.front().second;

				que.pop();

				for(auto &P:adj[u]){
					int v=P.first;
					int cost=P.second;

					if(distance[v]>d+cost){
						distance[v]=d+cost;
						que.push({v,d+cost});
						//cout<<"Push-->"<<steps<<endl;
					}
				}
			}
			steps++;
		}

	//	for(int i=0;i<distance.size();i++){
	//		cout<<i<<"--->"<<distance[i]<<endl;	
	//	}
		
		return distance[dst]==INT_MAX?-1:distance[dst];
};


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n=4;
	vector<vector<int>> flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
	int src=0;
	int dst=3;
	int K=1;

	int res=cheapestFlight(n,flights,src,dst,K);
	cout<<res<<endl;


}