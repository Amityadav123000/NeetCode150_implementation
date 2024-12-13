#include<bits/stdc++.h>
using namespace std;

vector<string> result;
int r,c;
vector<pair<int,int>> directions{{-1,0},{1,0},{0,1},{0,-1}};

struct trieNode{
	bool endOfWord;
	trieNode* children[26];
	string word;
};

trieNode* getNode(){
	trieNode* temp=new trieNode();
	temp->endOfWord=false;
	for(int i=0;i<26;i++){
		temp->children[i]=NULL;
	}
	temp->word="";
	return temp;
}


void insert(trieNode* root,string str){
	//cout<<"inseting words"<<endl;
	trieNode* pCrawl=root;
	for(char ch:str){
		if(pCrawl->children[ch-'a']==NULL){
			pCrawl->children[ch-'a']=getNode();
		}
		pCrawl=pCrawl->children[ch-'a'];
	}
	pCrawl->endOfWord=true;
	//cout<<str<<endl;
	pCrawl->word=str;
}

void DFS(vector<vector<char>>& board,int i,int j,trieNode* root){
	//cout<<"calling dfs"<<endl;
	if(i<0 || i>=r || j<0 || j>=c || board[i][j] == '$' || root->children[board[i][j]-'a'] == NULL) return;

	root=root->children[board[i][j]-'a'];

	if(root->endOfWord==true){
		//cout<<root->word<<endl;
		result.push_back(root->word);
		root->endOfWord=false;
	}

	char temp=board[i][j];
	board[i][j]='$';
	for(pair<int,int> p:directions){
		int new_i=i+p.first;
		int new_j=j+p.second;
		DFS(board,new_i,new_j,root);
	}
	board[i][j]=temp;
}

vector<string> findWords(vector<vector<char>> &board,vector<string>&words){
	//cout<<"calling find word function"<<endl;
	r=board.size();
	c=board[0].size();

	trieNode* root=getNode();

	for(string str:words){
		insert(root,str);
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char ch=board[i][j];
			//cout<<i<<"----"<<j<<endl;
			if(root->children[ch-'a']!=NULL){
				DFS(board,i,j,root);
			}
		}
	}

	return result;

};





int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<vector<char>> board={
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
		};

	vector<string> words={"oath","pea","eat","rain"};

	vector<string> ans;
	ans=findWords(board,words);

	for(auto it:ans){
		cout<<"ANS ="<<it<<endl;
	}
}