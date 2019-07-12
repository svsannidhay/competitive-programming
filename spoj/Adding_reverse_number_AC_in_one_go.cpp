//problem statement:-   https://www.spoj.com/problems/ADDREV/
//(medium one AC in one attempt)

#include<iostream>
#include<math.h>
using namespace std;
int reverseadigit(long long int n){
	long long int reversedn=0,multiplier=0;
	long long int temp;
    temp = n;
    while(temp>0){
    	temp = temp/10;
    	multiplier++;
    }
	for(long long int i=pow(10,(multiplier-1));n>0;i=(i/10)){
		int digit = n%10;
		n = n/10;
		reversedn = reversedn + (digit*i);
		//multiplier = multiplier -1;
	}
	return reversedn;
	
	
}
int main(){
	long long int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long int n1,n2,nr1,nr2,n;
		cin>>n1>>n2;
		nr1 = reverseadigit(n1);
		nr2 = reverseadigit(n2);
		n = nr1+nr2;
		cout<<reverseadigit(n);
		cout<<"\n";
	}
	

	return 0;
}
