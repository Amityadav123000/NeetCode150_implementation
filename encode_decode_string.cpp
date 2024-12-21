#include<bits/stdc++.h>
using namespace std;

string encode(string &str){
	int n=str.length();
	string ans;

	for(int i=0;i<n;i++){
		int count =1;
		string temp="";
		while(i<n-1 && str[i]==str[i+1]){
			count++;
			i++;
		}

		temp= str[i]+to_string(count);
		ans+=temp;
		//cout<<str[i]<<count;
	}

	return ans;
}



int main(){

#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string str="wwwwaaadexxxxxxywww";
	string ans=encode(str);
	cout<<"ENCODE :"<<ans<<endl;

}