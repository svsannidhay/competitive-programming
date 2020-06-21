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
pair< vector<ll>,vector<ll> > spDijkstra(vector< pair<ll,ll> > adj[],ll v,ll start,){  //add ll end is you want shotest path from s to e only
    
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
        /*
        if(v==e){
            //break here if you want to stop at e as the minimum possible distance from source to end will be calculated
        }
        */
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
/*
//Pseudo code

# Runs Dijkstra's Algorihtm and returns an array that contains
# the shortest Distance to every node from the start node s.
# g - adjacency list of weighted graoh 
# n - the number  of nodes in a  graph
# s - the index of the starting node (0 <= s < n)
function dijkstra(g, n, s):
    vis = [false,false, ... , false] #size n 
    dist = [∞,∞, ... ,∞,∞] #size n
    dist[s] = 0
    vis[s] = true
    pq = empty priority queue
    pq.insert(s,0)
    while pq.size() != 0:
        index,minValue = pq.poll()
        vis[index] = true
        for(edge : g[index]):
            if vis[edge.to]: continue
            newDist = dist[index] + edge.cost
            if newDist < dist[edge.to]:
                dist[edge.to] = newDist
                pq.insert(edge.to, newDist)
    return dist            

*/