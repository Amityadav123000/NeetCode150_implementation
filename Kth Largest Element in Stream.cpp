#include<bits/stdc++.h>
using namespace std;

class KthLargest{
public:
	priority_queue<int,vector<int>,greater<int>> pq;
	int k;

	KthLargest(int K,vector<int> &nums){
		k=K;
		for(auto x:nums){
			pq.push(x);

			if(pq.size()>k) pq.pop();
		}
	}

	int add(int val){
		pq.push(val);

		if(pq.size()>k) pq.pop();

		return pq.top();

	}

};


int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector<int> nums={7, 7, 7, 7, 8, 3};
	KthLargest* kthLargest = new KthLargest(4, nums);
	cout<<"ANS :"<<kthLargest->add(2)<<endl; // return 7
	cout<<"ANS :"<<kthLargest->add(10)<<endl; // return 7
	cout<<"ANS :"<<kthLargest->add(9)<<endl; // return 7
	cout<<"ANS :"<<kthLargest->add(9)<<endl; // return 8

}