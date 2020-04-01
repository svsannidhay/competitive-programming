Problem Statement :-https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/
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
#define MAX INT_MAX;
#define MIN INT_MIN;
#define MOD 1000000007;
 
using namespace std;
 
void btree(ll *tree,ll *arr,ll n,ll s,ll e){
	if(s==e){
		tree[n] = 1;
		return;
 	}else{
		ll mid = (s+e)/2;
		btree(tree,arr,2*n,s,mid);
		btree(tree,arr,2*n+1,mid+1,e);
		tree[n] = tree[2*n] + tree[2*n+1];
	}
}
 
ll query(ll *tree,ll n,ll s,ll e,ll k){
	if(s==e){
		return e;
	}
	else{
		ll mid = (s + e)/2; 
		if(k>tree[2*n]){
			return query(tree,2*n+1,mid+1,e,(k-tree[2*n]));
		}
		else{
			return query(tree,2*n,s,mid,k);
		}
	}
}
void update(ll *tree,ll n,ll s,ll e,ll index){
	if(s==e){
		tree[n] = 0; 
		return;
	}
	else{
		ll mid = (s+e)/2;
		if(index >= s && index <= mid){
			update(tree,2*n,s,mid,index);
		}else{
			update(tree,(2*n)+1,mid+1,e,index);
		}
 
		tree[n] = tree[2*n] + tree[2*n+1];
	}
}
int main(){
	fio;
	cinll(n);cinll(q);
	ll arr[n+1] = {1};
	ll tree[4*n+1];
	btree(tree,arr,1,0,n-1);
	for(ll i=0;i<q;i++){
		ll type;
		cin>>type;
		if(type==1){
			ll k;
			cin>>k;
			if(k<=tree[1]){
			ll ans = query(tree,1,0,n-1,k);
				cout<<ans+1<<"\n";
			}
			else{
				cout<<-1<<"\n";
			}
		}else{
			ll index;
			cin>>index;
			index--;
			update(tree,1,0,n-1,index);
		}
	}
	return 0;
}
