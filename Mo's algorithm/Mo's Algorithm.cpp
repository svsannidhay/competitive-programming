/*		I never loose
		I either win or learn it

    Algorithm used :-

	Mo's Algorithm.  https://www.hackerearth.com/practice/notes/mos-algorithm/
        complexity O((Q+N)*sqrt(N))*O(R-L)) //92 Points 
    Tags :- Squareroot decomposition|Mo's Algorithm|FAST IO|Segment free with bitsets

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
#define MAX INT_MAX
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
ll BLOCK_SIZE;
bool mo_order(pair< pair<ll,ll>,ll> &x,pair< pair<ll,ll>,ll> &y){
    ll block_x = x.first.first / (BLOCK_SIZE);
    ll block_y = y.first.first / (BLOCK_SIZE);
    if(block_x != block_y){
        return block_x < block_y;
    }else{    
        return x.first.second < y.first.second;
    }
}
bool cmp(pair< pair<ll,ll>,ll> &a,pair< pair<ll,ll>,ll> &b){    //Good comparator
    if(a.first.first / BLOCK_SIZE != b.first.first / BLOCK_SIZE)
        return a.first.first < b.first.first;
    return a.first.first / BLOCK_SIZE % 2 ? a.first.second < b.first.second : a.first.second > b.first.second;
}
void fastscan(int &number){ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c=='-'){ 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 
int main(){
    //fio;
    cinll(n);cinll(m);
    BLOCK_SIZE = sqrt(n);
    //if(BLOCK_SIZE*BLOCK_SIZE!=n){
       // BLOCK_SIZE++;
    //}
    vector<ll> arr;
    for(ll i=0;i<n;i++){cinll(x);arr.pb(x);} 
    vector<ll>happ;
    happ.pb(0);
    for(ll i=0;i<m;i++){cinll(x);happ.pb(x);} 
    cinll(q);
    pair<pair<ll,ll>,ll> queries[q+1];                 
    for(ll i=0;i<q;i++){
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].second = i;
    } 
    sort(queries,queries+q,cmp);
    vector<ll> freqsieve;     
    freqsieve.pb(0);           
    for(ll i=1;i<=m;i++){
        freqsieve.pb(0);
    }
    ll mo_left = 0;
    ll mo_right = -1;
    vector<ll> answers;
    for(ll i=0;i<q;i++){
        answers.pb(1);
    }
    for(ll i=0;i<q;i++){
        while(mo_right<queries[i].first.second-1){
            mo_right++;
            freqsieve[arr[mo_right]]++;
        }
        while(mo_right>queries[i].first.second-1){
            freqsieve[arr[mo_right]]--;
            mo_right--;
        }
        while(mo_left<queries[i].first.first-1){
            freqsieve[arr[mo_left]]--;
            mo_left++;
        }
        while(mo_left>queries[i].first.first-1){
            mo_left--;
            freqsieve[arr[mo_left]]++;
        }
        for(ll j=(queries[i].first.second-1);j>=queries[i].first.first-1;j--){
            if(freqsieve[arr[j]]!=happ[arr[j]]){
                if(freqsieve[arr[j]]!=0){
                    answers[queries[i].second] = 0;
                    break;
                }
            }
        }
    }
    for(ll i=0;i<q;i++){cout<<answers[i]<<"\n";}
	return 0;
}