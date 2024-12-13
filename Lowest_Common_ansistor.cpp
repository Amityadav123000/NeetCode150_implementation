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

node* LCA(node* root,int p,int q){
	if(root==NULL) return NULL;

	if(root->data==p || root->data==q) return root;

	node* left=LCA(root->left,p,q);
	node* right=LCA(root->right,p,q);

	if(left!=NULL && right!=NULL) return root;
	if(left!=NULL) return left;
	return right;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	node* res=LCA(root,5,1);
	
	cout<<"ANS = "<<res->data<<" ";

	return 0;
}