//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-minimum-query/
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
#define ll            long long int
#define ull           unsigned long long int
#define cinll(x)      ll x;cin>>x;
#define cini(x)       int x;cin>>x;
#define cins(x)       string x;cin>>x;
#define cinch(x)      char x;cin>>x;
#define vect(x)       vector<ll> x;
#define vect1(x)      vector<ll> x;x.push_back(0);
#define pb(x)         push_back(x)
#define mp(x,y)       make_pair(x,y)
#define MAX           1e18
#define MIN           -1e18
#define MOD           1000000007
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}

using namespace std;

void buildsegtree(vector<ll> &arr,ll *segtree,ll start,ll end,ll treenode){
    if(start==end){
        segtree[treenode] = arr[start];
        return;
    }
    ll mid = (start+end)/2;
    buildsegtree(arr,segtree,start,mid,2*treenode);
    buildsegtree(arr,segtree,mid+1,end,2*treenode+1);
    segtree[treenode] = min(segtree[2*treenode],segtree[2*treenode+1]);
}

ll query(ll *segtree,ll treenode,ll start,ll end,ll l,ll r){
    //Case I No overlap
    if(r<start||l>end){
        return MAX;
    }
    //Case II Complete overlap
    if(l<=start&&r>=end){
        return segtree[treenode];
    }
    ll mid = (start + end)/2;
    ll left = query(segtree,2*treenode,start,mid,l,r);
    ll right = query(segtree,2*treenode+1,mid+1,end,l,r);
    return min(left,right);
}

void update(ll *segtree,ll treenode,ll start,ll end,ll idx,ll val){
    if(start==end){
        segtree[treenode] = val;
        return; 
    }
    ll mid = (start+end)/2;
    if(idx>=start&&idx<=mid){
        update(segtree,2*treenode,start,mid,idx,val);
    }else{
        update(segtree,2*treenode+1,mid+1,end,idx,val);
    }
    segtree[treenode] = min(segtree[2*treenode],segtree[2*treenode+1]);
}

int main(){
    fio;
    cinll(n);cinll(q);
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        cinll(x);arr.pb(x);
    }
    ll segtree[4*n+1];
    buildsegtree(arr,segtree,0,n-1,1);
    // for(ll i=0;i<4*n+1;i++){
    //     cout<<segtree[i]<<" ";
    // }
    // cout<<"\n";
    while(q--){
        cinch(ch);
        if(ch=='u'){
            cinll(idx);cinll(val);idx--;
            update(segtree,1,0,n-1,idx,val);
            // for(ll i=0;i<4*n+1;i++){
            //     cout<<segtree[i]<<" ";
            // }
            // cout<<"\n";
        }else{
            cinll(l);cinll(r);l--;r--;
            cout<<query(segtree,1,0,n-1,l,r)<<"\n";
        }
    }
    return 0;
}