#include<bits/stdc++.h>
using namespace std;




int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<int>> board = 
	{{"X","X","X","X"},
	 {"X","O","O","X"},
	 {"X","X","O","X"},
	 {"X","O","X","X"}};

	 for(int i=0;i<board.size();i++){
	 	for(int j=0;j<board[0].size();j++){
	 		cout<<board[i][j]<<" "; 
	 	}
	 	cout<endl;
	 }


}