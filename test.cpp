#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)
using namespace std;
 
void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void solve(vector<ll> adj[],vector<ll> &visited,ll current,ll depth,ll &maxdepth,ll &ok){
    if(!visited[current]){
        if(adj[current].size()==1){
            if(depth>max)
            maxdepth = max(maxdepth,depth);
        }
        vector<ll> depths;
        for(ll i=0;i<adj[current].size();i++){
            if(!visited[adj[current][i]]){
                visited[adj[current][i]] = true;
                solve(adj,visited,adj[current][i],depth+1,maxdepth);
                if(ok){
                    depths.pb(maxdepth);
                }    
            }
        }
    }
}

int main(){
    cinll(n);
    vector<ll> adj[n];
    for(ll i=0;i<n-1;i++){  
        cinll(u);cinll(v);
        addEdge(adj,u,v);
    }
    vector<bool> visited(n,false);
    return 0;
}
