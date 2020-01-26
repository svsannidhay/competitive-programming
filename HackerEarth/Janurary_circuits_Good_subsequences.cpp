//problem statement:-
//Hard dp
// Cant apply dp  
//Partially solved
/*
    Brute force approach :-
        Generate all the subsequences
            Time complexity :- O(2^n)
        now keeping the track of digts for each element in subsequence 
            Time complexity :- O(n*9) //Worst case i.e All elements are of 9 digits
    
    
    
    --------Sannidhay Vashal\
    -----NIT SRINAGAR
*/

#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define ull unsigned long long int
#define cinll(i) ll i;cin>>i;
using namespace std; 

  
// This function calculates the mask frequencies 
// for every present in the array 
void calculateMaskFrequencies(ll arr[], ll n, 
                 unordered_map<ll, ll>& freq) 
{ 
    // Iterate over the array 
    for (ll i = 0; i < n; i++) { 
  
        ll num = arr[i]; 
  
        // Creating an empty mask 
        ll mask = 0; 
  
        // Extracting every digit of the number 
        // and updating corresponding bit in the 
        // mask 
        while (num > 0) { 
            mask = mask | (1 << (num % 10)); 
            num /= 10; 
        } 
  
        // Update the frequency array 
        freq[mask]++; 
    } 
} 
  
// Function return the number of valid pairs 
ll countPairs(ll arr[], ll n) 
{ 
    // Store the mask frequencies 
    unordered_map<ll, ll> freq; 
  
    calculateMaskFrequencies(arr, n, freq); 
  
    long long int numberOfPairs = 0; 
  
    // Considering every possible pair of masks 
    // and calculate pairs according to their  
    // frequencies 
    for (ll i = 0; i < 1024; i++) { 
        numberOfPairs += (freq[i] * (freq[i] - 1)) / 2; 
        for (ll j = i + 1; j < 1024; j++) { 
  
            // if it contains a common digit 
            if (i & j) 
                numberOfPairs += (freq[i] * freq[j]); 
        } 
    } 
    return numberOfPairs; 
} 
 
ll nCrModp(ll n, ll r) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (ll i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (ll j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1]); 
    } 
    return C[r]; 
} 

  
int main() 
{ 
    cinll(n);
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    //for(ll i=0;i<n;i++){
      //  cout<<arr[i]<<" ";
    //}
    ll count = n;
    ll total = nCrModp(n,2)%1000000007;
    ll size = sizeof(arr) / sizeof(arr[0]); 

    count += (total - (countPairs(arr, size)%1000000007)); 
    //cout<<countPairs(arr,n);
    cout<<count%1000000007;
    return 0; 
} 
