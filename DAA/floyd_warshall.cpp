#include<iostream>
#include<cstring>
#include<vector>

#define ll long long int
#define cinll(x) ll x;cin>>x;
#define INF 1e18

using namespace std;

int main(){
    cinll(n);
    ll adjm[n+2][n+2];
    ll adjprev[n+2][n+2];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cinll(x);
            if(x==-1)  adjm[i][j] = INF;
            else  adjm[i][j] = x;
            adjprev[i][j] = adjm[i][j];
        }
    }
    cout<<"\n";
    for(ll i=1;i<=n;i++){
        ll adjcurr[n+2][n+2];
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                adjcurr[j][k] = min(adjprev[j][k],adjprev[j][i]+adjprev[i][k]);
                if(adjcurr[j][k]==INF) cout<<"inf ";
                else cout<<adjcurr[j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                adjprev[j][k] = adjcurr[j][k];
            }
        }
    }
    return 0;
}
