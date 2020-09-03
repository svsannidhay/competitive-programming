//https://www.codechef.com/LRNDSA07/problems/FROGV
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
using namespace std;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return a<b;
}

ll dp[100005];
void solvedp(vector<pair<ll,ll>> &frogs,ll n,ll k){
    ll start = frogs[0].first;
    dp[frogs[0].second] = start;
    for(ll i=1;i<n;i++){
        if(frogs[i].first-frogs[i-1].first<=k) dp[frogs[i].second] = start;
        else{ 
            start = frogs[i].first;
            dp[frogs[i].second] = start;
        }    
    }
}

int main(){
    cinll(n);cinll(k);cinll(p);
    vector<pair<ll,ll>> frogs;
    vector<ll> arr;
    for(ll i=1;i<=n;i++){
        cinll(x);
        frogs.pb(mp(x,i));
        arr.pb(x);
    }
    sort(frogs.begin(),frogs.end(),compare);
    solvedp(frogs,n,k);
    for(ll i=0;i<p;i++){
        cinll(a);cinll(b);
        ll vala = arr[a-1];
        ll valb = arr[b-1];
        if(vala>=valb){
            if(dp[a]<=valb) cout<<"Yes\n";
            else cout<<"No\n";
        }else{
            if(dp[b]<=vala) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}