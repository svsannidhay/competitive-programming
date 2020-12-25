#include <iostream>
#include <vector>
#include <cstring>

#define pb(x) push_back(x);
#define ll long long int
#define cinll(x) \
    ll x;        \
    cin >> x;
#define INF 1e18

using namespace std;

ll dp[1000][1000];
ll seq[1000][1000];

void mcm_dp(vector<ll> d, ll n)
{
    memset(dp, 0, sizeof(dp));
    memset(seq, 0, sizeof(seq));
    for (ll j = 2; j <= n; j++)
    {
        ll i = 1;
        ll checkpt = j;
        while (i <= n && j <= n)
        {
            ll min = -1;
            ll minval = INF;
            for (ll k = i; k < j; k++)
            {
                ll val = dp[i][k] + dp[k + 1][j] + (d[i - 1] * d[k] * d[j]);
                if (val < minval)
                {
                    minval = val;
                    min = k;
                }
            }
            dp[i][j] = minval;
            seq[i][j] = min;
            i++;
            j++;
        }
        j = checkpt;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << seq[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int main()
{
    cinll(n);
    vector<ll> d;
    for (ll i = 0; i < n; i++)
    {
        cinll(a);
        cinll(b);
        if (i == n - 1)
        {
            d.pb(a);
            d.pb(b);
        }
        else
        {
            d.pb(a);
        }
    }
    mcm_dp(d, n);
    return 0;
}