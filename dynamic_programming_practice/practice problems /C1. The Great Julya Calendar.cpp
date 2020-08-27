/*
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

ll dp[10000000];

ll findansdp(ll n){
  if(n==0) return 0;
  if(n<10) return 1;
  ll ans = MAX;ll tmp = n;
  if(dp[n]!=-1) return dp[n];
  while(tmp>0){
    ll digit = tmp%10;
    tmp = tmp/10;
    ll ansdigit = MAX;
    if(digit!=0) ansdigit = 1 + findansdp(n-digit);
    if(ansdigit<ans) ans = ansdigit;
  }
  dp[n] = ans;
  return ans;
}

int main(){
  memset(dp,-1,sizeof(dp));
  cinll(n);
  cout<<findansdp(n);
  return 0;
}