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
#define INF 0x3f3f3f3f 
using std::string;
//FAST IO
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

//Complexity :- O(V + logE)   //Greedy Approach

void addEdge(vector< pair<ll,ll> > adj[],ll u,ll v,ll wt){
    adj[u].pb(make_pair(v,wt));
    adj[v].pb(make_pair(u,wt));      //Include this for bidirectional graph
}
// DFS complexity : - O(N+E)
void dfs(vector<bool> &visited,vector< pair<ll,ll> > adj[],ll curr){
    if(visited[curr]==true){
        return ;
    }
    visited[curr] = true;
    cout<<curr<<" ";
    for(ll i=0;i<adj[curr].size();i++){
        if(visited[adj[curr][i].first]==false){
            dfs(visited,adj,adj[curr][i].first);
        }
    }
}
//Custom compare to sort priority queue
struct custom_compare{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        return a.second>b.second;
    }
};
//Greedy approach
// Prints shortest paths distance from src to all other vertices 
pair< vector<ll>,vector<ll> > spDijkstra(vector< pair<ll,ll> > adj[],ll v,ll start){
    
    priority_queue < pair<ll,ll>, vector< pair<ll,ll> > , custom_compare > pq;  //min heap priority queue
    // priority_queue< iPair, vector <iPair> , greater<iPair> > pq;  // can be written like this too
    //distance vector initialized to infinity
    //Whenever we get a smaller distance we will update it 
    //Simply we are working greedly
    vector<ll> dist(v+1,INF);
    // This to keep track of which nodes are vistied 
    vector<bool> visited(v+1,false);
    // This previous array keeps the track of which node you took to get to node i
    vector<ll> prev(v+1,0);
    //inseting first element  to min_heap
    dist[start] = 0;
    visited[start] = true;
    pq.push(make_pair(start,dist[start]));
    while(!pq.empty()){
        pair<ll,ll> current = pq.top();
        ll distcurr = current.second;
        ll v = current.first;
        pq.pop();
        visited[v] = true;
        if(distcurr>dist[v]){
            continue;
        }
        for(ll i=0;i<adj[v].size();i++){
            pair<ll,ll> node = adj[v][i];
            ll index = node.first;
            ll distnext = node.second;
            if(dist[index] > distcurr + distnext){
                prev[index] = v;
                dist[index] =  distcurr + distnext;
                pq.push(make_pair(index,dist[index]));
            }
        }
    }
    
    return make_pair(prev,dist); 
}

int main(){

    cinll(v);cinll(e);cinll(k);
    vector< pair<ll,ll> > adj[v+1]; //Indexed from 1 for zero indexing use adj[v]
	for(ll i=0;i<e;i++){
		cinll(u);cinll(v);cinll(wt);
		addEdge(adj,u,v,wt);
	}
    vector<bool> visited(v+1,false);
    //dfs(visited,adj,1);
    pair< vector<ll>,vector<ll> > djk;
    djk = spDijkstra(adj,v,1);
    vector<ll> prev = djk.first;
    vector<ll> dist = djk.second;
    
    // for(ll i=0;i<=v;i++){
    //     cout<<dist[i]<<" ";
    // }
    // for(ll i=0;i<=v;i++){
    //     cout<<prev[i]<<" ";
    // }


    /////////////////////////////////////////////////
    //retreving Path and edge costs for the traversal
    for(ll i=1;i<=v;i++){
        ll start = i;
        vector<ll> path;
        while(prev[start]!=0){
            path.pb(start);
            start = prev[start];
        }
        path.pb(1);
        vector<ll> cost;
        for(ll i=path.size()-1;i>=1;i--){
            ll u = path[i];
            ll v = path[i-1];
            ll edgewt;
            for(ll i=0;i<adj[u].size();i++){
                pair<ll,ll> p = adj[u][i];
                if(p.first==v){
                    edgewt = p.second;
                    break;
                }
            }
            cost.pb(edgewt);
        }
    }

    ////////////////////////////////////////////////
    
    return 0;
}
