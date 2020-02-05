//Problem statement:- https://codeforces.com/contest/1296/problem/A
//Ad hoc
/*
    Firstly, if the array already has an odd sum, the answer is "YES". Otherwise, we need to change the parity of the sum, so we need to change the parity of some number. We can do in only when we have at least one even number and at least one odd number. Otherwise, the answer is "NO".
    -----Sannidhay Vashal
    ----NIT SRINAGAR
*/
// Header files
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
 
// I/O manipulations
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define cinll(i) ll i;cin>>i;
#define outll(i) cout<<i;
 
using namespace std;
 
int main(){
  cinll(t);
  for(ll i=0;i<t;i++){
    cinll(n);
    vector<ll> arr;
    ll countOdd = 0;
    ll countEven = 0;
    for(ll i=0;i<n;i++){
      cinll(x);
      if(x%2!=0){
        countOdd++;
      }
      else{
        countEven++;
      }
      arr.push_back(x);
    }
    ll ans = 0;
    if(countOdd>=1&&countEven>=1){
      ans = 1;
    }
    if(countOdd == n && (n%2!=0)){
      ans = 1;
    }
    if(ans == 1){
      cout<<"YES"<<"\n";
    }
    else{
      cout<<"NO"<<"\n";
    }
  }
  return 0;
}