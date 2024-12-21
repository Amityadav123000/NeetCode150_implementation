#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board){
	vector<set<int>> rows(9),cols(9),blocks(9);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){

			if(board[i][j]=='.') continue;

			int curr=board[i][j]-'0';
			if(rows[i].count(curr) || cols[i].count(curr) || blocks[(i/3)*3 + j/3].count(curr)){
				return false;
			}
			rows[i].insert(curr);
			cols[i].insert(curr);
			blocks[(i/3)*3 + j/3].insert(curr);
		}
	}

	return true;


}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<char>> board={
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
		};

		cout<<"ANS ="<<isValidSudoku(board)<<endl;

}