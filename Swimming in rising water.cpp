#include<bits/stdc++.h>
using namespace std;
int n;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

bool possible(int i,int j,vector<vector<int>> &grid,int time,vector<vector<bool>> &vis){

	if(i<0 || j<0 || i>=n || j>=n || grid[i][j] > time || vis[i][j]){
		return false;
	}
	vis[i][j]=true;

	if(i==n-1 && j==n-1) return true;

	int x=grid[i][j];
	bool res=false;
	for(int k=0;k<4;k++){
		res=res || possible(i+dx[k],j+dy[k],grid,time,vis);
	}

	return res;

}


int swimInWater(vector<vector<int>> &grid){
	n=grid.size();
	int l=grid[0][0];
	int h=1e9;
	int res=h;

	while(l<=h){
		int mid=l+(h-l)/2;
		vector<vector<bool>> vis(n,vector<bool>(n));
		if(possible(0,0,grid,mid,vis)){
			res=mid;
			h=mid-1;
		}else{
			l=mid+1;
		}
	}

	return res;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> grid={{0,2},{1,3}};
	int result=swimInWater(grid);
	cout<<result<<endl;
}
