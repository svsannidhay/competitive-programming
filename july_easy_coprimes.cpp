//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/coprimed-32042ef1/
// very very easy one 
#include<iostream>
#include <algorithm> 
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n-2;i>=1;i--){
        if(__gcd(i,n)==1){
            cout<<i;
            break;
        }
    }
    return 0;
}
