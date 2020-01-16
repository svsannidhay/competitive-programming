//Problem statement :- https://www.codechef.com/JAN20B/problems/CHFDORA/
/* 
   Brute Force Algorithm :- 
    -> As you need to Check always Around the central element . 
    -> You Just traverse each of the Element of the matrix And find     the number of such Pair of Palindromic subRows and subcolumns
    -> FOR FINDIND THE NUMBER OF PALINDROMIC PAIRS 
    ->Start from the central element we will expand till the maximum    possible Indexes
      and Checking row[i][j-k] = row [i][j+k] && 
      col[i-k][j] = col[i+k][j]
      and if this condition fails Then we can clearly say that None of the left out outer pairs statisfies the condition to be palindromic so we can break Whenever any of these conditions fails
      Time Complexity :-
           Complexity of traverse matrix = O(n*m)
           Complexity to find  The No of pairs (worst Case)= O(min(n,m))
           => Total complexity = O(n*m*min(n,m))
           Assuming n <= m  then 
           min(n,m) = n = sqrt(n)*sqrt(n) <= sqrt(n)*sqrt(m)
           => min(n,m) = (n*m)^(1/2)
         => Complexity Of Brute Force approach is O(nm^(1.5))
         Now seeing the constraints For The given probelem Brute force is fast enough to give You Ac easily 
    There is another  Efficent Algorithm Which can be used to solve The given Problem in O(nm)
    Manacher's Algorithm :-
       // Will Address it soon enough 
       Complexity :- O(2*n*m)


*/
//Brute Force Implementation:-
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
ll FindMin(ll x,ll y,ll a,ll b){
    ll result1;
    if(x<=y){
        result1 = x;
    }
    else{
        result1 = y;
    }
    ll result2;
    if(a<=b){
        result2 = a;
    }
    else{
        result2 = b;
    }
    if(result1<=result2){
        return result1;
    }
    else{
        return result2;
    }
    
}
int main(){
    fio;
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n,m;
        
        cin>>n>>m;
        ll arr[n+1][m+1];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }
        ll countPairs = 0;
        // Traversing 2D grid
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                ll disTop,disBottom,disLeft,disRight,count = 0;
                disTop = i-1;
                disBottom = n-i;
                disLeft = j-1;
                disRight = m-j;
                ll disMin = FindMin(disTop,disBottom,disLeft,disRight);
                if(disMin>=1){
                    ll columnUp;
                    ll columnDown;
                    ll rowLeft;
                    ll rowRight;
                    for(ll k = 1;k<=disMin;k++){
                        columnUp = arr[i-k][j];
                        columnDown = arr[i+k][j];
                        rowLeft = arr[i][j-k];
                        rowRight = arr[i][j+k];
                        if(columnUp == columnDown && rowLeft == rowRight){
                            count++;
                        }
                        else{
                            break;
                        }
                    }
                }
                countPairs = countPairs + count;
            }
        }
        countPairs = countPairs + (n*m);
        cout<<countPairs<<"\n";
    }
}
// Manachers's Algorithm impllimentation :- // Coming soon 

