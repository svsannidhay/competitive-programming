//Problem statement :-https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-cursed-tree/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef0(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
using namespace std;
struct Node{
	ll data;
	Node *left,*right;
};
vect(path);
Node *get(ll data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right= NULL;
	return temp;
}
Node *insert(Node *node,ll data){
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
Node * lca(Node * root,ll x,ll y ){
    if(root == NULL){
        return NULL;
    }
    if (root->data == x || root->data == y) {
        return root;
    }
    if(root->data > x && root->data > y){
        return lca(root->left,x,y);
    }
    if(root->data < x && root->data < y){
        return lca(root->right,x,y);
    }
    return root;
}

void search(Node *root,ll val,ll & max){
	if(root!=NULL){
		if(root->data>=max){
			max = root->data;
		}
			if(val > root->data){
				search(root->right,val,max);
			}
			if(val <= root->data){
				search(root->left,val,max);
			}

	}	
}

int main(){
	fio;
	cinll(n);
	vect(arr);
	Node *root = NULL;
	for(ll i=0;i<n;i++){
		cinll(x);
		arr.pb(x);
		if(i==0){
			root = insert(root,x);
		}
		else{
			insert(root,x);
		}
	}
	cinll(x);
	cinll(y);
	Node * customroot = NULL;
	customroot = lca(root,x,y);
	ll max = 0;
	search(customroot,x,max);
	search(customroot,y,max);
	if(x>=max){
		max = x;
	}
	if(y>=max){
		max = y;
	}
	cout<<max<<"\n";
	return 0;
}