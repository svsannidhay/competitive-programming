Problem Statement :- https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/little-monk-and-swaps/
/*
	Basic Algorithm Used :- 
	 	We know that inOrder traversal on a binary search tree gives out a sorted array
		using this fact what we can do here is find the inOrder traversal for a given binary
		tree and compare it with its sorted version the number of swaps required will be the 
		required output.
		Complexity :-
		  ---> To find inOrder traversal array :- O(n)
		  ----> To find the number swaps required to make it sorted :- O(n^2) //Brute force
	      complexity _ bruteForce :-  O(n^3)
		  --->Efficent approach to find no of swaps rquired to sort an array is counting the no
		  of cycles you need to swap a value can be solved by usign basic graph thoery 
		     
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
#include<string.h>
 
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
#define MAX INT_MAX;
#define MIN INT_MIN;
#define MOD 1000000007;
using namespace std;
void inOrder(ll *bTree,ll n,vector<ll> & sortit){
	if(bTree[n]==0){return ;}
	inOrder(bTree,n*2,sortit);
	sortit.pb(bTree[n]);
	inOrder(bTree,n*2+1,sortit);
}
ll minSwaps(std::vector<ll> &v){ 
    std::vector<pair<ll,ll> > t(v.size()); 
    ll ans = 0; 
    for(ll i = 0; i < v.size(); i++) 
        t[i].first = v[i], t[i].second = i; 
    sort(t.begin(), t.end()); 
    for(ll i = 0; i < t.size(); i++) 
    { 
        if(i == t[i].second) 
            continue; 
        else
        { 
            swap(t[i].first, t[t[i].second].first); 
            swap(t[i].second, t[t[i].second].second); 
        } 
        if(i != t[i].second) 
            --i; 
        ans++; 
    } 
    return ans; 
} 
int main(){
	fio;
	cinll(n);
	ll bTree[4*n+1] = {0};
	for(ll i=1;i<=n;i++){
		cin>>bTree[i];
	}
	vector<ll> sortit;
	inOrder(bTree,1,sortit);
	ll noSwaps = 0;
	noSwaps = minSwaps(sortit);
	cout<<noSwaps;
	return 0;
}
