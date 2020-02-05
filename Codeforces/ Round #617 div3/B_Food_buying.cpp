//Problem statement:- https://codeforces.com/contest/1296/problem/B
//Ad hoc
/*
 Let's do the following greedy solution: it is obvious that when we buy food that costs exactly 10𝑘 for 𝑘≥1, 
 we don't lose any burles because of rounding. Let's take the maximum power of 10 that is not greater than 𝑠 (let it be 10𝑐),
 buy food that costs 10𝑐 (and add this number to the answer) and add 10𝑐−1 to 𝑠. Apply this process until 𝑠<10 and then 
 add 𝑠 to the answer.

    Time complexity: 𝑂(log𝑠) per test case.

    -------Sannidhay Vashal
    ---NIT SRINAGAR
*/
// Header files
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
 
// I/O manipulations
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define cinll(i) ll i;cin>>i;
#define outll(i) cout<<i;
 
using namespace std;
 
int main(){
  cinll(t);
  for(ll i=0;i<t;i++){
    cinll(n);
    ll sum = 0;
    while(n>=10){
      ll tmprem = n%10;
      sum = sum + n - tmprem;
      n = (n - tmprem)/10 + tmprem;
    }
    cout<<sum+n<<"\n";
  }
  return 0;
}
