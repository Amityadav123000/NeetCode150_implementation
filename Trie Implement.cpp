#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
	struct trieNode{
		trieNode* children[26];
		bool isEndOfWord;
	};

	trieNode* getNode(){
		trieNode* newNode=new trieNode();
		newNode->isEndOfWord=false;
		for(int i=0;i<26;i++){
			newNode->children[i]=NULL;
		}
		return newNode;
	}

	trieNode* root;

	Trie(){
		root=getNode();
	}

	void insert(string word){
		trieNode* crawler=root;

		for(int i=0;i<word.length();i++){
			int index=word[i]-'a';
			if(!crawler->children[index]){
				crawler->children[index]=getNode();
			}
			crawler=crawler->children[index];
		}
		crawler->isEndOfWord=true;
	}

	bool search(string word){
		trieNode* crawler=root;
		for(int i=0;i<word.length();i++){
			int index=word[i]-'a';
			if(!crawler->children[index]) return false;
			crawler=crawler->children[index];
		}

		return (crawler!=NULL && crawler->isEndOfWord);
	}

	bool startsWith(string prefix){
		trieNode* crawler=root;
		int i=0;
		for(i=0;i<prefix.length();i++){
			int index=prefix[i]-'a';

			if(!crawler->children[index]) return false;
			crawler=crawler->children[index];
		}

		if(i==prefix.length()) return true;
		return false;
	}
};

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	Trie* trie = new Trie();
	trie->insert("apple");
	cout<<endl<<"Search :"<<trie->search("apple");   // return True
	cout<<endl<<"Search :"<<trie->search("app");     // return False
	cout<<endl<<"Search :"<<trie->startsWith("app"); // return True
	trie->insert("app");
	cout<<endl<<"Search :"<<trie->search("app");     // return True
 
}