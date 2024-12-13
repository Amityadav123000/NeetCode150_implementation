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

	
int ans = 1;
void dfs(node *root ,int max){
    if(!root) return;
    if(root->data >= max){
        ans++;
        max = root->data;
    }
    dfs(root->left , max);
    dfs(root->right , max);
}
int goodNodes(node* root) {
    dfs(root->left , root->data);
    dfs(root->right , root->data);
    return ans;
}


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node *root=buildTree();
	int res=goodNodes(root);
	
	//for(int i=0;i<res.size();i++){
		cout<<"Ans = "<<res;
	//}

	return 0;
}