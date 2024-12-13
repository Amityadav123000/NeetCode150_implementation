#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};


node* buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	//cout<<"--->"<<d;
	//input 1 2 4 -1 -1 5 -1 -1 3 -1 -1
	node* n=new node(d);
	n->left=buildTree();
	n->right=buildTree();
	return n;
}

bool isPossible(node* root,int l,int r){
	if(root==NULL) return true;

	if(l>=root->data || root->data>=r) return false;
	return isPossible(root->left,l,root->data) and isPossible(root->right,root->data,r);
}

bool isValidBST(node* root){
	int l=INT_MIN;
	int r=INT_MAX;

	return isPossible(root,l,r);
}

//input 5 1 -1 -1 4 3 -1 -1 6 -1 -1
int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	
	bool ans=isValidBST(root);
	cout<<"ANS : "<<ans;

	return 0;
}