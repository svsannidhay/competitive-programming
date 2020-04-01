#include<iostream>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<map>

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.pb(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.pb(val);}

using namespace std;

struct Node{
    ll data;
    Node *left,*right;
};

Node *get(ll data){
    Node *tmp = new Node;
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node * insert(Node * node,ll data){
    if(node == NULL){
        return get(data);
    }else{
        if(data <= node->data){
            node->left = insert(node->left,data);
        }else{
            node->right = insert(node->right,data);
        }
    }
    return node;
}

void inOrderReccursive(Node *root){
    if( root!= NULL ){
        inOrderReccursive(root->left);
        cout<<root->data<<" ";
        inOrderReccursive(root->right);
    }
}

void inOrderNonRecursice(Node * root){
    stack<Node *> s;
    Node * curr = root;
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }    

}

int main(){
    Node *root = NULL;
    root = insert(root,10);
    insert(root,17);
    insert(root,4);
    insert(root,5);
    insert(root,1);
    insert(root,21);
    insert(root,16);
    inOrderReccursive(root);
    cout("\n");
    inOrderNonRecursice(root);
    return 0;
}

