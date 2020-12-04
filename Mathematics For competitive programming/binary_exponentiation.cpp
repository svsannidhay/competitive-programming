#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<climits>
#include<set>
#include<bitset>
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

ll binaryexponential(ll base, ll exp, ll mod){
    ll value = 1;
    while(exp>0){
        if(exp%2==1)
            value = (value % mod * base % mod) % mod;
        exp/=2;
        base = (base%mod * base%mod)%mod;
    }
    return value;
}    

int main()
{
    cout<<binaryexponential(2,5,MOD);
    return 0;
}