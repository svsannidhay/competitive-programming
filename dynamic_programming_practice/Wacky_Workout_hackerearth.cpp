//problem statement :- https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/description/
// easy 
//However, since N is upto 10^18, you must use matrix exponentiation to find the answer in O(log n) time.
//dp(n) = dp(n-1) + dp(n-2)
#include<iostream>
#include<algorithm>
#include<vector>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull long long int
#define MOD 1000000007
using namespace std;
vector <int> dp(10000000);
void multiply(ull F[2][2], ull M[2][2]) 
{ 
  ull x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  ull y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  ull z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  ull w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x%MOD; 
  F[0][1] = y%MOD; 
  F[1][0] = z%MOD; 
  F[1][1] = w%MOD; 
}
void power(ull F[2][2], ull n)
{
    if( n == 0 || n == 1)
    return;
    ull M[2][2] = {{1,1},{1,0}};
    
    power(F, n/2);
    multiply(F, F);
    
    if (n%2 != 0)
    multiply(F, M);
}

ull recursive_func(ull n) 
{ 
  ull F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0;
  power(F, n-1); 
  
  return F[0][0]%MOD; 
} 
int main(){
    int t;
    fio;
    cin>>t;
    for(int i=0;i<t;i++){
        ull n;
        cin>>n;
        cout<<recursive_func(n+2)%MOD<<"\n";
    }
    return 0;
}
