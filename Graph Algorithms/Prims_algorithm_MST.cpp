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
using namespace std;

void addEdge(vector< pair<ll,ll> > adj[],ll u,ll v,ll wt){
    adj[u].pb(make_pair(v,wt));
    adj[v].pb(make_pair(u,wt));      //Include this for bidirectional graph
}

struct custom_compare{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        return a.second>b.second;
    }
};

ll lazyprim(vector<pair<ll,ll>> adj[],ll n,ll x){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, custom_compare > pq;
    ll y;
	vector<bool> marked(n+1,false);
	ll edgecount = 0;
    ll minimumCost = 0;
    pair<ll,ll> p;
    pq.push(make_pair(x,0));
    while(!pq.empty()&&edgecount!=n){
        // Select the edge with minimum weight
        p = pq.top();
        pq.pop();
        x = p.first;
        // Checking for cycle
        if(marked[x] == true)	continue;
        minimumCost += p.second;
        marked[x] = true;
        edgecount++;
        for(ll i = 0;i < adj[x].size();i++){
            y = adj[x][i].first;
            if(marked[y] == false)	pq.push(adj[x][i]);
        }
    }
    return minimumCost;
}


int main(){
	cinll(v);cinll(e);
    vector< pair<ll,ll> > adj[v+1]; //Indexed from 1 for zero indexing use adj[v]
	for(ll i=0;i<e;i++){
		cinll(u);cinll(v);cinll(wt);
		addEdge(adj,u,v,wt);
	}
	cout<<lazyprim(adj,v,1);
	return 0;
}