//problem statement:-  https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/help-patwari/
// easy
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int 
#define MOD 1000000007
using namespace std;
vector<ll> dp(1000000,-1);
ll find_ans(ll n){
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
        if(n==0){
            dp[n] = 0;
            return 0;
        }
        if(n==1){
            
            dp[n] = 1;
            return 1;
            
        }
        
        if(n==2){
            dp[n] = 1;
            return 1;
        }
        ll value = find_ans(n-1)+find_ans(n-2);
        value  = value%MOD;
        dp[n] = value;
        return value;
    }
}

int main(){
    ll n;
    fio;
    cin>>n;
    ll value = find_ans(n);
    cout<<value%MOD;
    return 0;
}
