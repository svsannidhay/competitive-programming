// problem statement :- https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-watching-fight/


#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<math.h>

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long int
#define ll long long int
#define cinll(i) ll i;cin>>i;
#define cout(i) cout<<i;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0)
#define pb(x) push_back(x);

using namespace std;

struct BstNode{
    ll data;
    struct BstNode *left;
    struct BstNode *right;
}; 

struct BstNode *getNewNode(ll data){
    struct BstNode *tempNode = new BstNode;
    tempNode->data = data;
    tempNode->left = tempNode->right = NULL;
    return tempNode;
}

struct BstNode *insert(struct BstNode *root ,ll data){
    if(root == NULL){
        struct BstNode * newNode = getNewNode(data);
        return newNode;
    }
    else{
        if(data <= root->data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
    }
    return root;
}

void preOrderTraversal(struct BstNode *root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}



ll maxDepth(struct BstNode *root){
	if(root==NULL){
		return 1;
	}
	ll left = maxDepth(root->left);
	ll right = maxDepth(root->right);
	ll max;
	if(left>=right){
		max = left;
	}
	else{
		max = right;
	}
    //maxDepth(root) = max(maxDepth(root->left),maxDepth(root->right));
	return max + 1;  
}

int main(){
    fio;
    cinll(n);
    struct BstNode * root = NULL;
    for(ll i=0;i<n;i++){
        cinll(x);
        if(i==0){
            root = insert(root,x);

        }else{
            insert(root,x);
        }
    }
    //preOrderTraversal(root);
    ll height = (log2(n+1) + 1);
    cout<<maxDepth(root)-1;
    return 0;
}

