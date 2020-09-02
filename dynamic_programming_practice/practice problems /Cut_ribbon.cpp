/*
    https://codeforces.com/problemset/problem/189/A
	Solution by:- 
	--------------Sannidhay Vashal
	----------------NIT SRINAGAR
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<climits>
#include<set>
#include<cstring>
#include<unordered_map>
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll            long long int
#define ull           unsigned long long int
#define cinll(x)      ll x;cin>>x;
#define cini(x)       int x;cin>>x;
#define cins(x)       string x;cin>>x;
#define vect(x)       vector<ll> x;
#define vect1(x)      vector<ll> x;x.push_back(0);
#define pb(x)         push_back(x)
#define mp(x,y)       make_pair(x,y)
#define MAX           1e18
#define MIN           -1e18
#define MOD           1000000007
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}

using namespace std;

//top- down memoized solution 
ll memo[100000];
ll opp = 0;
ll solvememo(ll n,ll a,ll b,ll c){
  opp++;
  if(n==0) return 0;
  if(n<0) return MIN;
  if(memo[n]!=-1) return memo[n];
  ll vala = 1 + solvememo(n-a,a,b,c);
  ll valb = 1 + solvememo(n-b,a,b,c);
  ll valc = 1 + solvememo(n-c,a,b,c);
  memo[n] = max(vala,max(valb,valc));
  return memo[n];
}
//bottom- up dp
ll solvedp(ll n,ll a,ll b,ll c){
  ll dp[100005];
  for(ll i=0;i<=100005;i++) dp[i] = MIN;
  dp[a] = 1;dp[b] = 1;dp[c] = 1;
  for(ll i=1;i<=n;i++){
    ll valprev = dp[i];
    ll vala = MIN;ll valb = MIN;ll valc = MIN;
    if(i-a>0) vala = 1 + dp[i-a];
    if(i-b>0) valb = 1 + dp[i-b];
    if(i-c>0) valc = 1 + dp[i-c];
    dp[i] = max(valc,max(valb,max(valprev,vala)));
  }
  return dp[n];
}

int main(){
  fio;
  cinll(n);
  cinll(a);cinll(b);cinll(c);
  memset(memo,-1,sizeof(memo));
  cout<<solvedp(n,a,b,c);
  return 0;
}