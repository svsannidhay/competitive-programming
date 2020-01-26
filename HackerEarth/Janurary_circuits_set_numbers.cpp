//Problem statement :- https://www.hackerearth.com/challenges/competitive/january-circuits-20/algorithm/set-numbers-bea74f5a/
#include<iostream>
#include<vector>
#include<math.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        ll numberOfDigit = log2(n) + 1;
        ll number = 0;
        for(ll i=0;i<=numberOfDigit-2;i++){
            ll power = pow(2,i); 
            number = number + power;
            if(i == numberOfDigit-2){
                ll powerLast = pow(2,i+1);
                if(number+powerLast<=n){
                    number = number + powerLast;
                }
            }
        }
        if(n==1){
            number = number+1;
        }
        cout<<number<<"\n";
    }
    return 0;
}
