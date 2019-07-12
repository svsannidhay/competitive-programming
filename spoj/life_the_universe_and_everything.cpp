// problem statement :- https://www.spoj.com/problems/TEST/
// (easiest problem ever encountered on sppoj)
#include <iostream>
using namespace std;

int main() {
	int flag= 1;
	while(flag==1){
		int n;
		cin>>n;
		if(n==42){
			flag = 0;
		}
		if(n!=42){
			cout<<n;
			cout<<"\n";
		}
	}
	return 0;
}
