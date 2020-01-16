//problem statement :-https://www.hackerearth.com/challenges/competitive/september-circuits-19/algorithm/color-the-boxes-47270a3b/
// very easy
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull long long int
using namespace std;
ull fact(ull n)
{   
    ull fact = 1;
    for(ull i =1;i<=n;i++){
        fact = fact * i;
        fact = fact%1000000007;
    }
    return fact;
}

int main(){
    ull n,m;
    cin>>n>>m;
    cout<<fact(m);
    if((fact(m))!=0){
    //cout<<((fact_dp(m)*(n-m+1))%1000000007);
    }
    
    
}
