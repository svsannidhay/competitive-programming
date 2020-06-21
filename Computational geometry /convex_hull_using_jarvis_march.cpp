/*
    //Convex hull using jarvis march  :-
    Explaination :- 

    Step1 :- Select the Left most point left using linear search
    Step2 :-



    utility fucntion :-
        checking orientation :- 
        
                . r
                 \
                  \ a
                   \
     p . __ __ __ _ .q
            b

        2D cross product: a ^ b = XaYb - YaXb = |a||b|sin α.

        Xa = r.x - q.x  ; Yb = q.y - p.y
        Ya = r.y - q.y  ; Xb = q.x - p.x

        => a ^ b = (r.x - q.x) * (q.y - p.y) - (r.y - q.y) * (q.x - p.x)

    - if a ^ b < 0, then b points to the left side of pq p to q direction ( i.e counter clockwise)
    - if a ^ b = 0, then r lies on b, so it's collinear with p and q;
    - if a ^ b > 0, then b points to the right side of d (as in the picture).


    Time Complexity :- O(n * no of points on hull) 
                       O(n^2) Worst case
    Space complexity :- O(n)
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
#define ll            long long int
#define ull           unsigned long long int
#define lld           long double
#define cinlld(x)     lld x;cin>>x;
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
#define INF 10000 

using namespace std;

ll orientation(pair<ll,ll> p,pair<ll,ll> q,pair<ll,ll> r){
    ll val = (q.second - p.second) * ( )
}

int main(){

    return 0;
}