//problem statement:- https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/tablets/
// easy
// don't bother for recursion wasted my 1 hour
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull  long long int
#define MOD 1000000007
using namespace std;
int main()
{
    ull n;
    fio;
    vector<ull> a;
    vector<ull> dp(1000000);
    ull sum=0;
    cin>>n;
    for(ull i=0;i<n;i++){
        ull x;
        cin>>x;
        a.push_back(x);
        dp[i] = 1;
    }
    for(ull i = 1;i<=n-1;i++){
        if(a[i]>a[i-1]){
            dp[i] = 1 + dp[i-1];
        }
    }
    for(ull i=n-2;i>=0;i--){
        if(a[i]>a[i+1] && dp[i]<=dp[i+1]){
            dp[i] = dp[i+1]+1;
        }
    }
    for(ull i=0;i<n;i++){
        sum = sum + dp[i];
    }
    cout<<sum%MOD;
}
