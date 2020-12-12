//https://codeforces.com/problemset/problem/550/A
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
#include <cstdlib> 
 
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
#define MIN           -1000000007
#define MOD           1000000007

using namespace std;

ll memo[100005];
ll opp;
void solve(string &s,bool ab,bool ba,ll ind,bool &ans){
  opp++;
  if(ab&&ba){
    ans = true;
    return;
  }
  if(ans) return;
  if(memo[ind]!=-1) return;
  if(ind>=s.length()-1) return;
  for(ll i=ind;i<s.length()-1;i++){
    if(s[i]=='A'&&s[i+1]=='B'){
      if(i+2<s.length()&&s[i+2]=='A'){
        solve(s,true,ba,i+2,ans);
      }else{
        ab = true;
      }  
    }
    if(ans) break;
    if(s[i]=='B'&&s[i+1]=='A'){
      if(i+2<s.length()&&s[i+2]=='B'){
        solve(s,ab,true,i+2,ans);
      }else{
        ba = true;
      }  
    }
    if(ans) break;
  }
  if(ab&&ba) ans = true;
  memo[ind] = 1;
  return;
}

int main(){
  memset(memo,-1,sizeof(memo));
  cins(s);
  bool ab = false;
  bool ba = false;
  bool ans = false;
  solve(s,ab,ba,0,ans);
  if(ans) cout<<"YES\n";
  else cout<<"NO\n";
  // cout<<opp;
  return 0;
}