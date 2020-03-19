// problem Statement :-https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
/*
	Solution by Sannidhay Vashal
	-----NIT SRINAGAR
	Data structure used :- Binary Search tree
  
*/
 
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
 
#define ull unsigned long long int
#define ll long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define pb(x) push_back(x);
#define vect1(x) vector<ll> x; x.pb(0);
#define vectdef0(x,size) vector<ll> x ;for(ll i=1;i<=size;i++){x.pb(0)};
 
using namespace std;
 
struct Node{
	ll data;
	Node *left, *right;
};
 
Node *get(ll data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
 
Node *insert(Node * node,ll data){
	if(node == NULL){
		return get(data);
	}
	else{
		if(data <= node->data){
			node->left = insert(node->left,data);
		}
		else{
			node->right = insert(node->right,data);
		}
	}
	return node;
}
 
void postOrderTraversal(Node * root,bool & check,ll val){
	if(root != NULL){
		if(root->data == val){
			check = true;
		}
		if(val <= root->data){
			postOrderTraversal(root->left,check,val);
		}
		else{
			postOrderTraversal(root->right,check,val);
		}
		
	}
 
}
 
int main(){
	fio;
	cinll(t);
	for(ll i=0;i<t;i++){
		cinll(n);
		cinll(m);
		Node * root = NULL;
		for(ll i=0;i<n;i++){
			cinll(x);
			if(i==0){
				root = insert(root,x);
			}else{
				insert(root,x);
			}
		}
		for(ll i=0;i<m;i++){
			cinll(x);
			bool ck = false;
			postOrderTraversal(root,ck,x);
			if(ck == true){
				cout<<"YES"<<"\n";
			}
			else{
				cout<<"NO"<<"\n";
			}
			insert(root,x);
		}
	}
	return 0;
}