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

vector<vector<int>> levelOrderTraversal(node* root){
	vector<vector<int>> ans;
	if(root==NULL) return ans;

	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		vector<int> level;
		for(int i=0;i<size;i++){
			node* node=q.front();
			q.pop();
			if(node->left!=NULL) q.push(node->left);
			if(node->right!=NULL) q.push(node->right);
			level.push_back(node->data);
		}
		ans.push_back(level);
	}

	return ans;
}

//input 3 9 -1 -1 20 15 -1 -1 7 -1 -1

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	vector<vector<int>> res=levelOrderTraversal(root);
	
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}