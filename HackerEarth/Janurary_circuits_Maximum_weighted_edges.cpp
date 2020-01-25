//Problem Statement:- https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/approximate/maximum-weighted-edges-ea5b15b8/
//Approximation Score:- 96.771/100
//Graph Theory
/*
    Basic Hashing Used
    
    Time complexity :- O(7*n)  // Linear TIme
    Space complexity : - O(4*n) //Linear Space
    
    ---------Sannidhay Vashal
    ------NIT SRINAGAR

*/

#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
using namespace std;

vector<ll> mapPower;

bool compare(ll val1,ll val2){
    return (mapPower[val1-1] > mapPower[val2-1]);
}

int main(){
    fio;
    ll n,m;
    cin>>n>>m;
    
    //Initiazling mapPower vector Which we are going to use to store no of occurances of  a node
    for(ll i=0;i<n;i++){
        mapPower.push_back(0);
    }
    //Creating Graph  //Each element in a matrix Aij shows a bidirectional path from i to j
    
   // ll graph[m+1][m+1];
    for(ll i=1;i<=m;i++){
        ll x,y;                   
        cin>>x>>y;            
        //graph[x][y]++;
        mapPower[x-1]++;
        mapPower[y-1]++;
    }

    //Taking Weights in sorted order
    //Decreasing order
    vector<ll> weights;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        weights.push_back(x);
    }
    sort(weights.begin(),weights.begin()+n-1,greater<ll>());
    
    //Creating a refernce vector to keep track for Nodes
    vector<ll> node;
    for(ll i=0;i<n;i++){
        node.push_back(i+1);
    }
    // Sorting Nodes in the decreasing order of their Occurances
    
    sort(node.begin(),node.begin()+n,compare);
    
    // Reference Vector to store the weights for each node
    vector<ll> nodeValues;
    for(ll i=0;i<n;i++){
       nodeValues.push_back(0);
    }
    
    for(ll i=0;i<n;i++){
        nodeValues[node[i]] = weights[i];
    }
    
    for(ll i=1;i<=n;i++){
        cout<<nodeValues[i]<<" ";
    }
    return 0;
}
