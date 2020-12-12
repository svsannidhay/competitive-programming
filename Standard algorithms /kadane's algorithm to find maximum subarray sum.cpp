//Problem statemnt :- Find the subarray with maximum sum and print its sum
//Kadane's algorithm find the maximum subarray sum ending at each i and find the the maximum one thats it here you go
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define cinll(x) \
  ll x;          \
  cin >> x;
#define pb(x) push_back(x)
using namespace std;

ll solvedp(vector<ll> &arr, ll n)
{
  vector<ll> dp(n, 0);
  dp[0] = arr[0];
  ll ans = dp[0];
  for (ll i = 1; i < n; i++)
  {
    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main()
{
  cinll(t);
  while (t--)
  {
    cinll(n);
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
      cinll(x);
      arr.pb(x);
    }
    cout << solvedp(arr, n);
  }
  return 0;
}