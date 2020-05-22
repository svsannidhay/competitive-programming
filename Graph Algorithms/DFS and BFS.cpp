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
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define MAX INT_MAX
#define MIN INT_MIN
#define MOD 1000000007
 
using namespace std;
// DFS complexity : - O(N+E)
void dfs(vector<bool> &visited,vector<ll> adj[],ll curr){
    if(visited[curr]==true){
        return ;
    }
    visited[curr] = true;
    cout<<curr<<" ";
    for(ll i=0;i<adj[curr].size();i++){
        if(visited[adj[curr][i]]==false){
            dfs(visited,adj,adj[curr][i]);
        }
    }
}
// BFS complexity :- O(N+E)
void bfs(vector<ll> adj[],ll s, ll e){

}

int main(){
    cinll(n); cinll(e); 
    vector<ll> adj[n];
    for(ll i=0;i<e;i++){
        cinll(x);cinll(y);
        adj[x].pb(y);adj[y].pb(x);
    }
    vector<bool> visited;
    for(ll i=0;i<=n;i++){
        visited.pb(false);
    }

    return 0;
}