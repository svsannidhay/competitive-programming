//Problem Statement :-https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/equal-subarrays-cf01a26a/
 // My fault :- Misinterpreted it as a Dp problem lol wasted a lot of time finding optimal subproblem
 
 
// Simple ad-hoc problem .. Create your own algo .. i dont think its  a proper aglo based question.
 
 
/* 
  Basic brute force approach : - 
      Is to find every subarray and then find the sums and all like a sliding window problem
      
      suppose you are given of array of n elements then there will be (n*(n+1))/2 non-empty subarrays.
 
        for ex A[]={1,2,3} the subarrays are:- {1},{2},{3},{1,2},{2,3},{1,2,3}
         
        (3*(3+1))/2 i.e, 6 non-empty subarrays
         
        you can generate all subarrays as follow:-
         
        We will run three nested loops, the outermost loop(first loop ) picks starting element and second outer loop considers all elements on right of the picked elements as ending element of subarray and the innermost loop (third loop) will print all elements between the start and the end element.
         
         
        Time complexity :- O(n^3) //Obviously not a good one lol
 
  Optimised solution : -
     Lets say we have a array take the sample one
       [1,4,9,3,6]
       now what we will do is iterate through the array once.
       lets first declare 
       sum = 0;  // sum of subarray
       length = 0; //length of subarray satisfying the condition till that element 
        Now we need to check what if adding that element to subarray satisfies 
        if it does then 
          increase length by one
          and sum by current element
        if it doesnot then 
            length = 1;
            and sum = element // i.e we assume that subarray from here now 
        do this till the end of array and have the track of maxLength that will be your Maximum 
        length of subarray.
        
        
        Time complexity :- O(n)   //Surly you will get AC
       
       
       
    -----------Sannidhay Vashal 
    ----------------NIT SRINAGAR
*/
 
 
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
using namespace std;
int main(){
    ll n,k;
    fio;
    cin>>n>>k;
    if(n>10000){    //For larger inputs   O(n) Approach still some side cases are missing
        vector<ll> sieve;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            sieve.push_back(x);
        }
        ll sum =0;
        ll length = 0;
        ll max = 0;
        ll maxLength = 0;
        for(ll i= 0;i<n;i++){
            if(sieve[i]>max){
                max = sieve[i];
            }
            if(( (max*(length+1))  - (sum + sieve[i]) <= k)){
                length++;
                sum = sum + sieve[i];
            }
            else{
                length = 1;
                sum = sieve[i];
                max = sieve[i];
            }
            if(length>maxLength){
                maxLength = length;
            }
        }
        cout<<maxLength<<"\n";
    }
    else{
        vector<ll> sieve;            //O(n^3) solution  
        ll limit = k;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            sieve.push_back(x);
        }
        ll maxCount = 0;
        for(ll i=0;i<n;i++){   //To pic up starting element
            for(ll j=0;j<n;j++){ //To pic up last element
                ll sum = 0;
                ll count = 0;
                ll maxElement = 0;
                for(ll k=i;k<=j;k++){
                    if(sieve[k]>=maxElement){
                        maxElement = sieve[k];
                    }
                }
                for(ll k=i;k<=j;k++){
                    sum = sum + (maxElement - sieve[k]);
                        if(sum<=limit){
                            count++;
                        }
                        else{
                            break;
                        }
                }
                if(count>=maxCount){
                    maxCount = count;
                }
            }
        }   
    cout<<maxCount;
    }
    
}
Language: C++14
