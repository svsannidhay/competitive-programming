//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
/*
	So as the given connection forms a n-ary tree so we can simply find the recursion depth
	for each cities consisting girls

	Solution by :- 
				Sannidhay VAshal
				   NIT SRINAGAR

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
#include<bitset>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define coutx(x) cout<<x;
#define cins(s) string s;cin>>s;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define BIT 16
#define MAX 1e18
#define MIN INT_MIN
#define MOD 1000000007
 
using std::string;
static struct IO {
    char tmp[1 << 10];
    char cur;
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

void dfs(vector<bool> &visited,vector<ll> adj[],ll curr,ll &tmp,ll &ans){
	if(visited[curr]==true){
		return;
	}
	visited[curr] = true;
	tmp++;
	if(curr == 1){
		ans = tmp;
		return;
	}
	for(ll i=0;i<adj[curr].size();i++){
		if(visited[adj[curr][i]]==false){
			dfs(visited,adj,adj[curr][i],tmp,ans);
			tmp--;
		}
	}
}

int main(){
	cinll(n);
	vector<ll> adj[n+1];
	for(ll i=0;i<n-1;i++){ //Adj list Created
		cinll(x);cinll(y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cinll(q);
	ll min = 1e18;
	ll id = 1e18; 
	for(ll i=0;i<q;i++){
		vector<bool> visited;
		for(ll i=1;i<=n;i++){visited.pb(false);}
		cinll(x);
		ll tmp = 0;
		ll ans = 0;
		dfs(visited,adj,x,tmp,ans);
		if(ans<=min){
			min = ans;
			if(x<id){
				id = x;
			}
		}
	}
	cout<<id;
	return 0;
}