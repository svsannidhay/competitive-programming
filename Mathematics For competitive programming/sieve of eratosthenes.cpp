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

void create_sieve(vector<ll> &sieve,ll s,ll e){
    vector<ll> tmp;
    for(ll i=s;i<=e;i++){
        tmp.pb(i);
    }
    for(ll i=2;i<=sqrt(e);i++){
        if(tmp[i-s]!=-1){  //This will give segmentation fault if s>1 so 
            cout<<i<<" ";  //this is only to find primes btw 1 -> n
            for(ll j=0;j<tmp.size();j++){
                if(tmp[j]>=i*i&&tmp[j]%i==0){
                    tmp[j] = -1;
                }
            }
        }
    }
    for(ll i=0;i<tmp.size();i++){
        if(tmp[i]!=-1){
            sieve.pb(tmp[i]);
        }
    }
}

//Time complexity : O(n*log(log(n)))
//------------------------------------------------OPTIMISED SIEVE OF ERATOSTHENES 
void create_sieve_optimised(vector<ll> &spfi,vector<ll> &sieve,ll e){
    vector<ll> tmp;
    for(ll i=0;i<=e;i++){
        tmp.pb(i);
        spfi.pb(i);
    }
    for(ll i=2;i<=sqrt(e);i++){
        if(tmp[i]!=-1){
            ll currprime = i;
            ll mul = 2;
            while(currprime*mul<=e){
                ll index = currprime*mul;
                if(tmp[index]%currprime==0){
                    tmp[index] = -1;
                    spfi[index] = currprime;
                }
                mul++;
            }
        }
    }
    for(ll i=2;i<tmp.size();i++){
        if(tmp[i]!=-1){
            sieve.pb(tmp[i]);
        }
    }
}

int main(){
    vector<ll> sieve;
    create_sieve(sieve,8,200);
    vector<ll>::iterator it;
    for(it=sieve.begin();it!=sieve.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}