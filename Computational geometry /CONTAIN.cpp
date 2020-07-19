/*
	Algorithm:-
	  -->We will create concentric hulls as many as possible 
	  --Algorithm used :- Finding convex hull using graham scan in O(nlogn)
	  --Then we will memoize all these convex hulls and use
	  --Point detection algorithm
	
	
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
 
#define fio ios_base::sync_with_stdio(false);
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

using std::string;

static struct IO {
    char tmp[1 << 10];
    // fast input routines
    char cur;
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }
    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
    inline IO& operator >> (char & c) { c = nextChar(); return *this; }
    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }
    inline IO& operator >> (string & s) {
        if (skipBlanks()) { s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }
    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this; }
#define defineInFor(intType) \
    inline IO& operator >>(intType & n) { \
        if (skipBlanks()) { \
            int sign = +1; \
            if (peekChar() == '-') { \
                sign = -1; \
                n = nextChar() - '0'; \
            } else \
                n = peekChar() - '0'; \
            while (!isBlank(nextChar())) { \
                n += n + (n << 3) + peekChar() - 48; \
            } \
            n *= sign; \
        } \
        return *this; \
    }
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
    // fast output routines
//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }
#define defineOutFor(intType) \
    inline char * toString(intType n) { \
        char * p = (tmp + 30); \
        if (n) { \
            bool isNeg = 0; \
            if (n < 0) isNeg = 1, n = -n; \
            while (n) \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg) *--p = '-'; \
        } else *--p = '0'; \
        return p; \
    } \
    inline IO& operator << (intType n) { return (*this) << toString(n); }
defineOutFor(int)
defineOutFor(long long)
#define endl ('\n')
#define cout _io_
#define cin _io_
} _io_;

///////////////////////////////////////////////////////////////////////////////////////////////////
//Utility functions for convex Hull
///////////////////////////////////////////////////////////////////////////////////////////////////

// https://www.codeproject.com/Tips/84226/Is-a-Point-inside-a-Polygon
bool pointIsInPoly(pair<ll,ll> p, vector<pair<ll,ll>> poly){
    bool isInside = false;    
    ll i = 0, j = (int)poly.size() - 1;
    for (i, j; i < poly.size(); j = i++) {
        if ( (poly[i].second>p.second)!=(poly[j].second>p.second) && p.first<float((poly[j].first-poly[i].first)*(float)(p.second-poly[i].second)/(float)(poly[j].second-poly[i].second)+(float)poly[i].first)) {
             isInside = !isInside;
        }
    }
    return isInside;
}
ll cworccw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    ll ans = ((b.second - a.second) * (c.first - b.first)) - ((b.first - a.first)*(c.second-b.second));
    if(ans==0){
        return 0; //collinear
    }else{
        if(ans>0){
            return 1; //cw
        }else{
            return 2; //ccw
        }
    }
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
bool cw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) < 0;
}
bool ccw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){ 
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) > 0;
}
bool collinear(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c) {
    if(a.first * (b.second - c.second) +  b.first * (c.second - a.second) +  c.first * (a.second - b.second) == 0){
        return true;
    } else return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

//=====================================================================================================

//Convex hull using Graham's Algorithm //I am implementing this algorithm first time so i am taking refernce from geeks for geeks 
pair< vector<pair<ll,ll>>, vector<pair<ll,ll>> > convex_Hull(vector<pair<ll,ll>> &points,ll n){ //Source link  https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
    vector<pair<ll,ll>> leftout;
    vector<pair<ll,ll>> hull; 
    vector<ll> visited(n+1,0);
    if(n <= 2){ 
        return mp(leftout,hull); //There must be more than two points to construct a convex hull 
    }
    // Find the leftmost point 
    ll left = 0; 
    for(ll i = 1;i<n;i++){ 
        if(points[i].first < points[left].first){ 
            left = i; 
        }
    }    
    ll p = left, q; 
    
    do{ 
        hull.push_back(points[p]); 
        visited[p] = 1;
        q = (p+1)%n; 
        for(ll i=0;i<n;i++) { 
            if (cworccw(points[p], points[i], points[q]) == 2){ 
               q = i; 
            }   
        } 
        p = q; 
        
    } while(p != left);  
    
    for(ll i=0;i<n;i++){
        if(visited[i]==0){
            leftout.pb(points[i]);
        }
    }

    vector < pair<ll,ll> > tmp = leftout;

    for(int i=0;i<tmp.size();i++){
        for(ll j = 0;j<hull.size();j++) {
            ll x = cworccw(hull[j],hull[(j + 1) % hull.size()],tmp[i]);
            if(!x){
                leftout.erase(remove(leftout.begin(),leftout.end(), tmp[i]), leftout.end());
                //cout<<tmp[i].first<<","<<tmp[i].second<<" "<<"Remove kr diya \n";
            }     
        }
    }

    return mp(leftout,hull);
} 

//===========================================================================================================

//Taking reference from
//https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
pair< vector< pair<ll,ll> >,vector< pair<ll,ll> > > convexHull(vector< pair<ll,ll> >  a) {
    vector<pair<ll,ll>> lo;
    vector<pair<ll,ll>> hull;
    for(ll i=0;i<a.size();i++){
        lo.pb(a[i]);
    } 
    if (a.size() == 1){
        return mp(lo,hull);
    }
    sort(a.begin(), a.end(), &cmp);
    pair<ll,ll> p1 = a[0], p2 = a.back();
    vector<pair<ll,ll>> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    ll x = 0;
    for(ll i=0;i<10;i++){
        pair<ll,ll> a,b,c;
        a.first = i;a.second = i+1;
        b.first = i;b.second = i+1;
        c.first = i;c.second = i+1;
        collinear(a,b,c);
    }
    for (int i = 0; i < (int)up.size(); i++){
        hull.push_back(up[i]);
        lo.erase(remove(lo.begin(), lo.end(), up[i]), lo.end());
    }    
    for (int i = down.size() - 2; i > 0; i--){
        hull.push_back(down[i]);
        lo.erase(remove(lo.begin(), lo.end(), down[i]), lo.end());
    }
    vector < pair<ll,ll> > tmp = lo;
    for(int i=0;i<tmp.size();i++){
        for(ll j = 0;j<hull.size();j++) {
            ll x = cworccw(hull[j],hull[(j + 1) % hull.size()],tmp[i]);
            if(!x){
                lo.erase(remove(lo.begin(),lo.end(), tmp[i]),lo.end());
                //cout<<tmp[i].first<<","<<tmp[i].second<<" "<<"Remove kr diya \n";
            }     
        }
    }
    return mp(lo,hull);
}

//============================================================================================================//


int main(){
    fio;
    cinll(t);
    for(ll i=0;i<t;i++){
        vector<pair<ll,ll>> pts;
        vector<pair<ll,ll>> leftout;
        cinll(n);cinll(q);
        for(ll i=0;i<n;i++){
            cinll(x);cinll(y);
            pts.pb(mp(x,y));
            leftout.pb(mp(x,y));
        }
        vector< vector<pair<ll,ll>> > concentrichulls;
        ll noofhulls = 0;
        while(leftout.size()>2){
            pair< vector<pair<ll,ll>>,vector<pair<ll,ll>> > temphulllo = convexHull(leftout);
            if(temphulllo.second.size()>0){
                concentrichulls.pb(temphulllo.second);
                noofhulls++;
            }
            leftout = temphulllo.first;
        }
        // for(ll i=0;i<noofhulls;i++){
        //     cout<<"{ ";
        //     for(ll j=0;j<concentrichulls[i].size();j++){
        //         cout<<"("<<concentrichulls[i][j].first<<","<<concentrichulls[i][j].second<<")"<<",";
        //     }
        //     cout<<"}\n";
        // }
        while(q--){
            cinll(x);cinll(y);
            ll countlayer = 0;
            pair<ll,ll> xy = mp(x,y);
            //cout<<"run ";
            for(ll i = 0;i<noofhulls;i++){
                if(pointIsInPoly(xy,concentrichulls[i])){ 
                    //////////////////////////////////
                     bool ckvertex = false;
                    // for(ll j=0;j<concentrichulls[i].size();j++){
                    //     if(concentrichulls[i][j].first == x and concentrichulls[i][j].second == y){
                    //         //cout<<"vertex hai \n";
                    //         ckvertex = true;
                    //     }
                    // }
                    bool ckcollinear = false;
                    for(ll j=0;j<concentrichulls[i].size()-1;j++){
                        if(collinear(concentrichulls[i][j],concentrichulls[i][j+1],xy)){
                           //cout<<"collinear hai yr \n";
                            ckcollinear = true;
                        }
                    }  
                    if(collinear(concentrichulls[i][0],concentrichulls[i][concentrichulls[i].size()-1],xy)){
                            //cout<<"collinear hai yr \n";
                            ckcollinear = true;
                    }
                    bool hua = false;
                    if(!ckcollinear&&!ckvertex){   
                        countlayer++;
                        hua = true;
                    }
                    if(hua==false){
                        goto bk;
                    }
                    ///////////////////////////////
                }else{
                    break;
                }
            }
            bk:;
            cout<<countlayer<<"\n";
            
        }
    }    
    return 0;
}
/*
1
12 5
-1 -1
2 -3
5 -1
6 2
5 5
0 4
0 0
2 -1
4 1
3 3
1 2
3 0
*/

/*
1
11 6
-1 -1
2 -3
5 -1
6 2
5 5
0 4
0 0
1 2
3 3
4 1
2 -1
2 1         
4 2        
-1 -1      
3 3       
3 -3       
4 4  
*/