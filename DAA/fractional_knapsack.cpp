#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)

using namespace std;

bool compare(pair<ll,double> a,pair<ll,double> b){
    return a.second>b.second;
}

double solveKnapsack(vector<double> w,vector< pair<ll,double> > r,ll wt){
    double ans = 0;
    for(ll i=0;i<r.size();i++){
        if(w[r[i].first]<=wt){
            wt-=w[r[i].first];
            ans += w[r[i].first]*r[i].second;
        }else{
            ans += (wt)*r[i].second;
            break;
        }
    }
    return ans;
}

int main(){
    cinll(n);cinll(wt);
    vector<double> p;
    vector<double> w;
    for(ll i=0;i<n;i++){
        cinll(x);
        p.pb(x);
    }
    for(ll i=0;i<n;i++){
        cinll(x);
        w.pb(x);
    }
    vector< pair<ll,double> > ratios;
    for(ll i=0;i<n;i++){
        double r = p[i]/w[i];
        ratios.pb(mp(i,r));
    }
    sort(ratios.begin(),ratios.end(),compare);
    cout<<solveKnapsack(w,ratios,wt);
    return 0;
}