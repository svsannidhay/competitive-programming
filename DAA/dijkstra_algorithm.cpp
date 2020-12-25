#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f

using namespace std;

void addEdge(vector< pair<ll,ll> > adj[],ll u,ll v,ll wt){
    adj[u].pb(mp(v,wt));
    adj[v].pb(mp(u,wt));
    return;
}

void dfs(vector<bool> &visited,vector< pair<ll,ll> > adj[],ll curr){
    if(visited[curr]) return;
    visited[curr] = true;
    cout<<curr<<" ";
    for(ll i=0;i<adj[curr].size();i++){
        if(!visited[adj[curr][i].first]){
            dfs(visited,adj,adj[curr][i].first);
        }
    }
    return;
}

struct custom_compare{
    bool operator()(pair<ll,ll> a,pair<ll,ll> b){
        return a.second>b.second;
    }
};

pair< vector<ll>,vector<ll> >spDijkstra(vector< pair<ll,ll> > adj[],ll v,ll start){
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, custom_compare > pq;
    vector<ll> dist(v+1,INF);
    vector<ll> prev(v+1,0);
    dist[start] = 0;
    pq.push(mp(start,dist[start]));
    while(!pq.empty()){
        pair<ll,ll> current = pq.top();
        ll indexcurr = current.first;
        ll distcurr = current.second;
        pq.pop();
        if(distcurr>dist[indexcurr]) continue;
        for(ll i=0;i<adj[indexcurr].size();i++){
            if (distcurr + adj[indexcurr][i].second < dist[adj[indexcurr][i].first]){
                dist[adj[indexcurr][i].first] = distcurr + adj[indexcurr][i].second;
                pq.push(mp( adj[indexcurr][i].first, dist[adj[indexcurr][i].first]) );
                prev[adj[indexcurr][i].first] = indexcurr;
            }
        }
    }
    return mp(dist,prev);
}

int main(){
    cinll(v);cinll(e);
    vector< pair<ll,ll> > adj[v+1];
    for(ll i=0;i<e;i++){
        cinll(u);cinll(v);cinll(wt);
        addEdge(adj,u,v,wt);
    }
    // vector<bool> visited(v+1,false);
    // dfs(visited,adj,1);

    pair< vector<ll>, vector<ll> > djk;
    djk = spDijkstra(adj, v, 1);
    vector<ll> prev = djk.second;
    vector<ll> dist = djk.first;

    for(ll i=0;i<=v;i++)    cout<<dist[i]<<" ";
    cout<<"\n";
    for(ll i=0;i<=v;i++)    cout<<prev[i]<<" ";
    


    return 0;
}