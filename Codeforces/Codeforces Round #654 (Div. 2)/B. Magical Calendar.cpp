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




int main(){
  cinll(t);
  for(ll i=0;i<t;i++){
    cinll(n);cinll(r);
    ll ans;
    if(r<n){
      ans = r*(r+1)/2;
    }else{
      ans = (n-1)*(n)/2;
      ans++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}