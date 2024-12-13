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

int findPosition(vector<int>&in,int element,int n){
	for(int i=0;i<n;i++){
		if(in[i]==element) return i;
	}
	return -1;
}

node* solve(vector<int>&in,vector<int>&pre,int &index,int inOrderStart,int inOrderEnd,int n){
	if(index>=n || inOrderStart>inOrderEnd){
		return NULL;
	}

	int element=pre[index++];
	node* root=new node(element);
	int position=findPosition(in,element,n);
	root->left=solve(in,pre,index,inOrderStart,position-1,n);
	root->right=solve(in,pre,index,position+1,inOrderEnd,n);

	return root;
}

node* buildTree(vector<int>&in,vector<int>&pre,int n){
	int preOrderIndex=0;
	node* ans=solve(in,pre,preOrderIndex,0,n-1,n);
	return ans;
}

void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	//node* root=buildTree();
	vector<int> inOrder={3,1,4,0,5,2};
	vector<int> preOrder={0,1,3,4,2,5};
	node* ans=buildTree(inOrder,preOrder,6);


	postOrder(ans);
	

	return 0;
}