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

string serialize(node* root){
	if(root==NULL) return "";

	string s="";

	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* node=q.front();
		q.pop();
		if(node==NULL) s.append("#,");
		else s.append(to_string(node->data)+',');
		if(node!=NULL){
			q.push(node->left);
			q.push(node->right);
		}
	}

	cout<<s<<endl;

	return s;
}

node* deSerialize(string data){

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	node* root=buildTree();

	string serialize_ans=serialize(root);
	//node* deSerialize=deSerialize(serialize);

	
	cout<<"ANS ="<<serialize_ans<<endl;
	//postOrder(deSerialize);


	return 0;
}