 #include<bits/stdc++.h>
 using namespace std;
 
 int solve(int n){
 	if(n==1 || n==2) return n;

 	vector<int> t(n+1);
 	t[0]=0;
 	t[1]=1;
 	t[2]=2;

 	for(int i=3;i<=n;i++){
 		t[i]=t[i-1] + t[i-2];
 	}

 	return t[n];

 }

 int main(){
 
 #ifndef ONLINE_JUDGE	
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 #endif
 
 	int n=10;
 	cout<<solve(n)<<endl;

 }