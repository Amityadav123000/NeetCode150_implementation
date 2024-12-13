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

void leftView(node *root,int level,vector<int> &ans){
	if(root==NULL) return;

	if(ans.size()==level) ans.push_back(root->data);
	leftView(root->right,level+1,ans);
	leftView(root->left,level+1,ans);

}

vector<int> leftView(node* root){
	vector<int> ans;
	leftView(root,0,ans);
	return ans;
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	vector<int> res=leftView(root);
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<"--> ";
	}

	return 0;
}