// problem statement :- https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/lets-begin/
// easy one 
// greedy algorithm worked for me by just putting some conditions and using proper memoization 
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll  long long int
using namespace std;
vector<ll> dp(1000000,0);
ll find_ans(ll n){
    if(dp[n]!= 0){
        return dp[n];
    }
    else{
        if(n>=9||n==7){
            dp[n] = 1 + find_ans(n-7);
            return dp[n];
        }
        if(n>=7||n==5){
            dp[n] = 1 + find_ans(n-5);
            return dp[n];
        }
        if(n>=5||n==3){
            dp[n] = 1 + find_ans(n-3);
            return dp[n];
        }
        if(n==4||n==2){
            dp[n] = 1 + find_ans(n-2);
            return dp[n];
        }
        if(n==1){
            return -1;
        }
    }
    
}
int main(){
    ll t;
    fio;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        ll count = find_ans(n);
        cout<<count<<"\n";
    }
    return 0;
}
