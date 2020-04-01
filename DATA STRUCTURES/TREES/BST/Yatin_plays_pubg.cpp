// Problem Statement :-https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/dummy3-4/
/*
		Either i will pass AC or i will learn | I never loose
		Solution by
			--------Sannidhay Vashal
			----NIT SRINAGAR
	Algorithm :- 
	   You can see by observation that at each level of BST we can kill one enemy
	   So the number of maximum enemies that can be killed are equal to the height of BST
	   Height of BST can be determined recursively in O(n) time.
*/

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<math.h>
#include<stdio.h>
#include<vector>

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(i) ll i;cin>>i;
#define cin(i) int i;cin>>i;
#define cout(x) cout<<x;
#define MOD 1000000007
#define MAX 1000000000
#define MIN -1000000000
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.pb(val);}
#define vectdef0(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){s.pb(val);}

using namespace std;

struct Node{
	ll data;
	Node *left,*right;
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
	}else{
		if(data<=node->data){
			node->left = insert(node->left,data);
		}else{
			node->right = insert(node->right,data);
		}
	}
	return node;
}
void inOrder(Node *root){
	if(root != NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right); 
	}
}

ll height(Node *root){
	if(root==NULL){
		return 1;
	}
	else{
		ll heightleft = height(root->left);
		ll heightright = height(root->right);
		return max(heightleft,heightright) + 1;
	}
}

int main(){
	cinll(t);
	for(ll i=0;i<t;i++){
		cinll(n);
		Node *root = NULL;
		for(ll i=0;i<n;i++){
			cinll(x);
			if(i==0){
				root = insert(root,x);
			}else{
				insert(root,x);
			}		
		}
		//inOrder(root);
		cout<<height(root)-1<<"\n";
	}
	return 0;
}
