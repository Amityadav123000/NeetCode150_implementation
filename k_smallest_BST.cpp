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

void Inorder(node* root,vector<int> &ans,int k){
	if(root==NULL) return;
	Inorder(root->left,ans,k);
	ans.push_back(root->data);
	Inorder(root->right,ans,k);
}
	
int kth_smallest_element(node *root,int k){
	vector<int> ans;
	Inorder(root,ans,k);
	return ans[k-1];
}	


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	int ans=kth_smallest_element(root,3);	

	cout<<"ANS = "<<ans<<endl;
	return 0;
}