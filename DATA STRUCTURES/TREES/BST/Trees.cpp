//INTRODUCTION TO TREES
/*
  ->Tree :-  collectio entities called nodes , linked together to simulate a hierarchy.
  
  --> Non linear data struture
  
  ->Root node :- Top most node is called root node
   
  ->Each arror in a tree is a link
      1
    /   \
   2     3
   2 and 3 are children of 1 and 1 is parent of 2 and 3
  -->leaf Node :- Those nodes which do not have childrens
  -->Remember these links are not bidirection 

  If we can go from A to B
  then A is ancestor of B
  And B is descendent of A
  
  -->PROPERTIES:-

   ->Tree can be called a recursive data structure
  ->If tree conatins N nodes then There must be N-1 edges.
  ->Depth of x = length of path from Root to x or simply no of edges in path from root to x.
  ->Hegiht of x = No of edges in longest path from x to leaf.
  ->heigt of tree = height of root node.
  ->height of leaf nodes = 0

  -> Basic way of implementing  a tree is using Node and links created recursively. 



  -->Binary Trees :- Each node can have at most 2 children.
        root
       /    \ 
      /      \
    Left    right 
    child   child
    /   \   /   \
   /     \ /     \
  
  -->Strict/Proper binary Tree :-  Each node can have either 2 or 0 children.
  
  -->Complete Binary tree:- All levels Except possibly the last are completely filled and all the nodes are as far left as possible.

  -->Max No of nodes at level i = 2^i //       
        Considering root node at level zero.

  -->Perfect Binary tree:- All levels will be   
       completely filled.
       
       ->Maximum no Nodes in a Binary tree with height h 
         = (2^(h+1) - 1)
       ->Height of binary tree with n nodes
         h = log2(n+1) - 1 
   
   -->Balanced Binary Tree:-
        Difference Between height of left and right subtree for every node is not more than k (mostly 1).
    -->Implementing a Binary  tree:-
        a. Dynamically created nodes
        b. arrays


 ---------Binary Search Tree ---------
-> A binary tree in which for each node,value of all the nodes in left
subtree is lesser and value of all the nodes in right subtree is greater.
*/

//Implementation of binary search tree

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>

#define cinll(i) ll i;cin>>i;
#define cout(i) cout<<i;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vect(x) vector<ll> x
#define fio ios_base::sync_with_stdio(false);ciin.tie(NULL)
#define ll long long int
#define ull unisgned long long int


using namespace std; 

struct BstNode{
  ll data;
  struct BstNode *left;
  struct BstNode *right;
};



struct BstNode * getNewNode(ll data){               //Return a Node with given data as an data element
  struct BstNode *tempNode = new BstNode;            
  tempNode->data = data;
  tempNode->left = tempNode->right = NULL;
  return tempNode ;
}

struct BstNode * insertNode(struct BstNode *node, ll data){
  if(node == NULL){
    struct BstNode *currNode ;
    currNode = getNewNode(data);              //Complexity O(log n)
    return currNode;
  }
  else{
    if(data <= node->data){
        node->left = insertNode(node->left,data);
    }
    else{
      node->right = insertNode(node->right,data);
    }
  }
  return node;
}

void preOrderTraversal(struct BstNode * root){    //root - left - right
  if(root != NULL){
    cout(root->data);cout("\n");           //print root node
    preOrderTraversal(root->left);   //go to left subtree
    preOrderTraversal(root->right);  // go to right subtree
  }
}

void postOrderTraversal(struct BstNode * root){
  if(root != NULL){
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout(root->data);cout("\n");
  }
}

void inOrdertraversal(struct BstNode * root){
  if(root  != NULL){
    inOrdertraversal(root->left);
    cout(root->data);cout("\n");
    inOrdertraversal(root->right);
  }
}

ll depth(struct BstNode * root){
  if(root==NULL){
    return 0;
  }
  ll dleft = depth(root->left);
  ll dright = depth(root->right);
  return max(dleft,dright)+1;
}


int main(){
  struct BstNode *root = NULL;
  root = insertNode(root,50);
  insertNode(root,30);
  insertNode(root,20);
  insertNode(root,40);
  insertNode(root,70);
  insertNode(root,60);
  insertNode(root,80);
  preOrderTraversal(root);
  cout("\n\n");
  postOrderTraversal(root);
  cout("\n\n");
  inOrdertraversal(root);
  return 0;
}


//sample tutorail problem link :-https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/tutorial/

// #include<iostream>
// #include<vector>
// #include<map>
// #include<stack>
// #include<queue>
// #include<algorithm>
// #include<math.h>

// #define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define ull unsigned long long int 
// #define ll long long int
// #define MOD 1000000007
// #define cinll(i) ll i;cin>>i;
// #define cout(i) cout<<i;
// #define pb(x) push_back(x);
// #define vect(x) vector<ll> x;
// #define vect1(x) vector<ll> x; x.pb(0);

// using namespace std;

// struct BstNode{
// 	ll data;
// 	struct BstNode *left;
// 	struct BstNode *right;
// };
// map< ll,BstNode *> cache;
// struct BstNode *getNewNode(ll data){
// 	struct BstNode * temp = new BstNode;
// 	temp->data = data;
// 	temp->right = temp->left = NULL;
// 	return temp;
// }

// struct BstNode * insertNode(struct BstNode * node,ll data){
// 	if(node == NULL){
// 		struct BstNode * currNode = getNewNode(data);
// 		cache.insert(pair<ll,struct BstNode *>(currNode->data,currNode));	
// 		return currNode;
// 	}
// 	else{
// 		if(data <= node->data){
// 			node->left = insertNode(node->left,data);
// 		}
// 		else{
// 			node->right = insertNode(node->right,data);
// 		}
// 	}
// 	return node;	
// }

// void preOrderTraversal(struct BstNode * root){
// 	if(root != NULL){
// 		cout(root->data);cout("\n");
// 		preOrderTraversal(root->left);
// 		preOrderTraversal(root->right);
// 	}
// }

// int main(){
// 	cinll(n);
// 	vect(sieve);
// 	struct BstNode * root = NULL;
// 	struct BstNode * customRoot = NULL;
// 	for(ll i=0;i<n;i++){
// 		cinll(x);
// 		sieve.pb(x);
// 	}
// 	cinll(q);
// 	root = insertNode(root,sieve[0]);
// 	for(auto it = sieve.begin()+1;it != sieve.end();it++){
// 			insertNode(root,*it);
// 	}
	
	
// 	map<ll,BstNode *>::iterator it;
// 	it = cache.find(q);
// 	customRoot = it->second;
// 	/*
// 	for(it = cache.begin();it!= cache.end();it++){
// 		if(it->first == q){
// 			customRoot = it->second;
// 			//cout<<customRoot->data;
// 		}
// 		//cout<<it->first<<" ";  
// 	}
// 	*/
// 	preOrderTraversal(customRoot);
// 	return 0;
// }