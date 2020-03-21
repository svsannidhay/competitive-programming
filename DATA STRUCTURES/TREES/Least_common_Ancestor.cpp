#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x);
#define vectdef0(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.pb(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.pb(val);}

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

void preOrderTraversal(Node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
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

int main(){
    Node * root =NULL;
    root = insert(root,5);
    insert(root,8);
    insert(root,2);
    insert(root,7);
    insert(root,1);
    insert(root,9);
    preOrderTraversal(root);
    cout<<"\n";
    Node *a = lca(root,1,9);
    cout<<a->data<<" ";
    return 0;
}