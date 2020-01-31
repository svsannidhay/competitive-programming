/*
  suppose you are given of array of n elements then there will be (n*(n+1))/2 non-empty subarrays.

for ex A[]={1,2,3} the subarrays are:- {1},{2},{3},{1,2},{2,3},{1,2,3}

(3*(3+1))/2 i.e, 6 non-empty subarrays

you can generate all subarrays as follow:-

We will run three nested loops, the outermost loop(first loop ) picks starting element and second outer loop considers all elements on right of the picked elements as ending element of subarray and the innermost loop (third loop) will print all elements between the start and the end element.


Time complexity :- O(n^3) //Obviously not a good one lol


*/
//Implementation
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    ll n = 5;
    for(ll i=0;i<n;i++){   //To pic up starting element
        for(ll j=i;j<n;j++){ //To pic up last element
            for(ll k=i;k<=j;k++){  //To select in between elements
                cout<<arr[k]<<" ";
            }
            cout<<"\n";
        }
        
    }
    return 0;
} 

