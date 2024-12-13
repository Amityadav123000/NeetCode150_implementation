#include<bits/stdc++.h>
using namespace std;

class MedianFinder{
public:
	priority_queue<int> left_max_heap;
	priority_queue<int,vector<int>,greater<int>> right_min_heap;


	void addNum(int num){
		if(left_max_heap.empty() || num<left_max_heap.top()){
			left_max_heap.push(num);
		}else{
			right_min_heap.push(num);
		}

		if(abs((int)left_max_heap.size()-(int)right_min_heap.size())>1){
			right_min_heap.push(left_max_heap.top());
			left_max_heap.pop();
		}else if(left_max_heap.size()<right_min_heap.size()){
			left_max_heap.push(right_min_heap.top());
			right_min_heap.pop();
		}
	}

	double findMedian(){
		if(left_max_heap.size()==right_min_heap.size()){
			double mean=double(left_max_heap.top()+right_min_heap.top())/2;
			return mean;
		}
		//cout<<"left ="<<left_max_heap.top()<<" ";
		return left_max_heap.top();	
	}

};



int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

MedianFinder* medianFinder = new MedianFinder();
medianFinder->addNum(1);    // arr = [1]
medianFinder->addNum(2);    // arr = [1, 2]
cout<<medianFinder->findMedian()<<endl;; // return 1.5 (i.e., (1 + 2) / 2)
medianFinder->addNum(3);    // arr[1, 2, 3]
cout<<medianFinder->findMedian()<<endl; // return 2.0
 
}