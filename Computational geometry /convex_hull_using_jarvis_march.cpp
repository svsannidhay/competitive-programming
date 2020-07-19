/*
    //Convex hull using jarvis march  :-
    Explaination :-

    utility fucntion :- 
        Orientation checking using 2d Cross product:- 
        https://www.youtube.com/watch?v=KNe9XRCZkVU&t=3991s
          b(x2,y2)
          /       
         /      
        /
       a - -- - --- c(x3,y3)    
     (x1,y1)

     Shifting points to origin first

            b(x2-x1,y2-y1)
          /       
         /      
        /
       a - -- - --- c(x3-x1,y3-y1)     
     0,0
     ac*ab = (x3-x1)*(y2-y1) - (x2-x1)*(y3-y1)

     -> ac*ab > 0 => point c is more left w.r.t (0,0) than b  (clockwise)  --> 1
     -> ac*ab = 0 => point a , b , c are collinear  --> 0
     -> ac*ab < 0 => point c is more right w.r.t (0,0) than b (counter clockwise) -->2


    Convex Hull :- Given a set of points in the plane. 
    the convex hull of the set is the smallest convex polygon that contains all the points of it.


    Jarvis March Algorithm (Gift wrapping Algorithm):- 

    Step1 :-  Initialize p as leftmost point


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
// b w.r.t ac 
ll orientation(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    ll val = (c.first-a.first)*(b.second-a.second) - (b.first-a.first)*(c.second-a.second);  // 2 D Cross product
    if(val == 0) return 0; //a,b,c are on same line
    if(val > 0) return 1;  //b is left to ac (clockwise)
    return 2;  //b is right to ac (counter-cw)
}

vector< pair<ll,ll> > convexHull(vector< pair<ll,ll> > points,ll n){
    if(n<3) return; 

    vector< pair<ll,ll> > hull;
    
    ll leftmost =0;
    for(ll i=1;i<n;i++){
        if(points[i].first<points[leftmost].first){
            leftmost = i;
        }
    }

    ll current = leftmost;
    ll next;
    do{
        hull.pb(points[current]);

        
    }while(current != leftmost);

    for(ll i=0;i<hull.size();i++){
        cout<<hull[i].first<<","<<hull[i].second<<" ";
    }
}


int main(){
    vector< pair<ll,ll> > points()      
    return 0;
}