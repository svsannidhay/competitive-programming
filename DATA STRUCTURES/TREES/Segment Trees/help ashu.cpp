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
 
void buildSegTree(vector<ll> &arr,vector< pair<ll,ll> > &segTree,ll start,ll end,ll treenode){
	if(start==end){
		if(arr[start]%2==0){
			segTree[treenode] = {1,0};
		}else{
			segTree[treenode] = {0,1};
		}
		return;
	}
	ll mid = (start+end)/2;
	buildSegTree(arr,segTree,start,mid,2*treenode);
	buildSegTree(arr,segTree,mid+1,end,2*treenode+1);
	segTree[treenode].first = segTree[2*treenode].first + segTree[2*treenode+1].first;
	segTree[treenode].second = segTree[2*treenode].second+ segTree[2*treenode+1].second;
}
 
ll query_eve(vector< pair<ll,ll> > &segTree,ll treenode,ll start ,ll end,ll l,ll r){
	if(r<start||l>end){
		return 0;
	}
	if(start>=l&&end<=r){
		return segTree[treenode].first;
	}
	ll mid = (start+end)/2;
	ll left = query_eve(segTree,2*treenode,start,mid,l,r);
	ll right = query_eve(segTree,2*treenode+1,mid+1,end,l,r);
	return (left + right);
}
 
ll query_odd(vector< pair<ll,ll> > &segTree,ll treenode,ll start ,ll end,ll l,ll r){
	if(r<start||l>end){
		return 0;
	}
	if(start>=l&&end<=r){
		return segTree[treenode].second;
	}
	ll mid = (start+end)/2;
	ll left = query_odd(segTree,2*treenode,start,mid,l,r);
	ll right = query_odd(segTree,2*treenode+1,mid+1,end,l,r);
	return (left + right);
}
 
void update(vector< pair<ll,ll> > &segTree,ll treenode,ll start,ll end,ll idx,ll val){
	if(start==end){
		if(val%2==0){
			segTree[treenode] = {1,0};
		}else{
			segTree[treenode] = {0,1};
		}
		return;
	}
	ll mid = (start + end)/2;
	if(idx>=start&&idx<=mid){
		update(segTree,2*treenode,start,mid,idx,val);
	}else{
		update(segTree,2*treenode+1,mid+1,end,idx,val);
	}
	segTree[treenode].first = segTree[2*treenode].first + segTree[2*treenode+1].first;
	segTree[treenode].second = segTree[2*treenode].second+ segTree[2*treenode+1].second;
}
 
int main(){
	fio;
	cinll(n);
	vector<ll> arr;
	for(ll i=0;i<n;i++){
		cinll(x);arr.pb(x);
	}
	vector< pair<ll,ll> > segTree(4*n+1);
	buildSegTree(arr,segTree,0,n-1,1);
	// for(ll i=0;i<segTree.size();i++){
	// 	cout<<segTree[i].first<<","<<segTree[i].second<<"\n";
	// }
	// cout<<"\n";
	cinll(q);
	while(q--){
		cinll(type);
		if(type==1){
			cinll(l);cinll(r);l--;r--;
			cout<<query_eve(segTree,1,0,n-1,l,r)<<"\n";
		}
		if(type==2){
			cinll(l);cinll(r);l--;r--;
			cout<<query_odd(segTree,1,0,n-1,l,r)<<"\n";
		}
		if(type==0){
			cinll(idx);cinll(val);idx--;
			update(segTree,1,0,n-1,idx,val);
		}
	}
	return 0;
}