#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones){
	priority_queue<int> pq;

	for(auto stone:stones){
		pq.push(stone);
	}

	while(pq.size()>1){
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		//cout<<"--->"<<abs(a-b)<<endl;
		pq.push(abs(a-b));
	}
	return pq.top();

}

int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int> stones={2,7,4,1,8,1};
	cout<<"ANS ="<<lastStoneWeight(stones)<<endl;
}