/*
    //LEVEL ORDER CREATION OF A BINARY TREE
    
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
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define MAX INT_MAX;
#define MIN INT_MIN;
#define MOD 1000000007;

using namespace std;

struct node{
    ll data;
    node *left,*right;
};

node *getnewnode(ll data){
    node *tmp = new node;
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void preOrder_recursive(node * root){
    stack<node *> s;
    while(root!=NULL||!s.empty()){
        if(root!=NULL){
            cout<<root->data<<" ";
            s.push(root);
            root = root->left;
        }else{
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

void inOrder(node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    cout<<"Enter the value of root: ";
    cinll(rvalue);
    cout<<"\n";
    node * root = getnewnode(rvalue);  //rooted at 1;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *tmpnode = q.front();
        q.pop();
        cout<<"Enter left child : ";
        cinll(lchild);
        cout<<"\n";
        cout<<"Enter right child : ";
        cinll(rchild);
        cout<<"\n";
        if(lchild!=-1){
            node *leftnode = getnewnode(lchild);
            tmpnode->left = leftnode;
            q.push(leftnode);
        }
        if(rchild!=-1){
            node *rightnode = getnewnode(rchild);
            tmpnode->right = rightnode;
            q.push(rightnode);
        }
    }
    preOrder_recursive(root);
    return 0;
} 