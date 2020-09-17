//https://codeforces.com/contest/1407/problem/D
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


using namespace std;

ll memo[300005];
ll solvememo(ll i,ll n,vector<ll> adj[]){
  if(i==n-1) return 0;
  if(memo[i]!=-1) return memo[i];
  ll ans = n-1-i;
  for(ll j=0;j<adj[i].size();j++){
    ans = min(ans,1 + solvememo(adj[i][j],n,adj));
  }
  memo[i] = ans;
  return ans;
}
/*______________NEARESET GREATER ELEMENT ON LEFT AND RIGHT IN O(N)________________*/
vector<ll> nearestGreaterelementonright(vector<ll> &arr){
  vector<ll> nge(arr.size(),-1);
  stack<pair<ll,ll>> st;
  for(ll i=0;i<arr.size();i++){
    if(st.empty()||st.top().first>arr[i]){
      st.push(mp(arr[i],i));
    }
    else{
      while(!st.empty()&&st.top().first<=arr[i]){
        nge[st.top().second] = i;
        st.pop();
      }
      st.push(mp(arr[i],i));
    }
  }
  return nge;
}

vector<ll> nearestGreaterelementonleft(vector<ll> &arr){
  vector<ll> nge(arr.size(),-1);
  stack<pair<ll,ll>> st;
  for(ll i=arr.size()-1;i>0;i--){
    if(st.empty()||st.top().first>arr[i]){
      st.push(mp(arr[i],i));
    }
    else{
      while(!st.empty()&&st.top().first<=arr[i]){
        nge[st.top().second] = i;
        st.pop();
      }
      st.push(mp(arr[i],i));
    }
  }
  return nge;
}
/*______________NEARESET SMALLER ELEMENT ON LEFT AND RIGHT IN O(N)________________*/
vector<ll> nearestSmallerelementonright(vector<ll> arr){
  vector<ll> nse(arr.size(),-1);
  stack<pair<ll,ll>> st;
  for(ll i=0;i<arr.size();i++){
    if(st.empty()||st.top().first<arr[i]){
      st.push(mp(arr[i],i));
    }
    else{
      while(!st.empty()&&st.top().first>=arr[i]){
        nse[st.top().second] = i;
        st.pop();
      }
      st.push(mp(arr[i],i));
    }
  }
  return nse;
}

vector<ll> nearestSmallerelementonleft(vector<ll> arr){
  vector<ll> nse(arr.size(),-1);
  stack<pair<ll,ll>> st;
  for(ll i=arr.size()-1;i>=0;i--){
    if(st.empty()||st.top().first<arr[i]){
      st.push(mp(arr[i],i));
    }
    else{
      while(!st.empty()&&st.top().first>=arr[i]){
        nse[st.top().second] = i;
        st.pop();
      }
      st.push(mp(arr[i],i));
    }
  }
  return nse;
}

int main(){
    cinll(n);
    vector<ll> arr;
    memset(memo,-1,sizeof(memo));
    for(ll i=0;i<n;i++){
      cinll(x);arr.pb(x); 
    }
    vector<ll> ngeonr = nearestGreaterelementonright(arr);
    vector<ll> nseonr = nearestSmallerelementonright(arr);
    vector<ll> ngeonl = nearestGreaterelementonleft(arr);
    vector<ll> nseonl = nearestSmallerelementonleft(arr);
    vector<ll> adj[n+1];
    for(ll i=0;i<n;i++){
      if(ngeonl[i]!=-1) adj[ngeonl[i]].pb(i);
      if(nseonl[i]!=-1) adj[nseonl[i]].pb(i);
      if(ngeonr[i]!=-1) adj[i].pb(ngeonr[i]);
      if(nseonr[i]!=-1) adj[i].pb(nseonr[i]);
    }
    cout<<solvememo(0,n,adj);
    return 0;
}