/*
    Segment Tree :- is a complete binary tree in which each node store some information
                    about a particular range of elements
        Particularly Used for problems involving queries and Updations
        Both quaries and upadtations can be completed in O(logN) time.

    based upon Divide and conquer

    In  an array representation of a segment tree for each treeNode i the 
    left child will be at 2*i and (2*i + 1)

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<map>

#define ll long long int
#define ull usigned long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<x;
#define MOD 1000000007
#define MAX 10000000000
#define MIN -10000000000
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);

using  namespace std;

void buildTree(ll* arr,ll* segTree,ll start,ll end,ll treeNode){
    if(start == end){
        segTree[treeNode] = arr[start];
        return;
    }
    
    ll mid = (start + end)/2;
    
    buildTree(arr,segTree,start,mid,2*treeNode);
    buildTree(arr,segTree,(mid+1),end,((2*treeNode)+1));
    segTree[treeNode] = segTree[2*treeNode] + segTree[2*treeNode +1];
}

void build(int node, int start, int end){
    if(start == end){
        tree[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else{
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start or end < l){
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r){
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main(){
    ll arr[] = {1,2,3,4,5,6,7,8,9};
    //ll * segTree = new ll[18];
    ll segTree[100];
    buildTree(arr,segTree,0,8,1);

    for(ll i=1;i<18;i++){
        cout<<segTree[i]<<" ";
    }

    return  0;
}
