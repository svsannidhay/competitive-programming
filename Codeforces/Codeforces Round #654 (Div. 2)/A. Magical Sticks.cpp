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
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define MAX INT_MAX
#define MIN INT_MIN
#define MOD 1000000007
 
using namespace std;

struct comp{
  bool operator()(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second){
      return a.first>b.first;
    }
    return a.second<b.second;
  }
};


int main(){
  cinll(t);
  for(ll i=0;i<t;i++){
    cinll(n);
    ll ans;
    if(n%2==0){
      ans = n/2;
    }else{
      ans = n/2 +1;
    }
     cout<<ans<<"\n";
  }
  return 0;
}