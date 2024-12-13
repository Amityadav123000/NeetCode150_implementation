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

	node* n=new node(d);
	n->left=buildTree();
	n->right=buildTree();
	return n;
}

int maxPath(node* root,int &ans){
	if(root==NULL) return 0;

	int left=max(0,maxPath(root->left,ans));
	int right=max(0,maxPath(root->right,ans));
	ans=max(ans,(left+right+root->data));

	return root->data + max(left,right);
}

int maxPathSun(node* root){
	int ans=INT_MIN;
	maxPath(root,ans);
	return ans;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	
	int ans=maxPathSun(root);
	cout<<"ANS : "<<ans;
	


	return 0;
}