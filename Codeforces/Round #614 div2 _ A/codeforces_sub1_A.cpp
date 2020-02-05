#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int 
#define ull unsigned long long int
#define MOD 1000000007
#define cinll(i) ll i;cin>>i;
using namespace std;
int main(){
    fio;
    cinll(t);
    for(ll i=0;i<t;i++){
        cinll(n);
        cinll(s);
        cinll(k);
        vector<ll> floors;
        for(ll i=0;i<k;i++){
            cinll(x);
            floors.push_back(x);
        }
        sort(floors.begin(),floors.end());
        ll count_up = 0;
        ll track_up = s;
        ll count_down = 0;
        ll track_down = s;
        for(auto it=floors.begin();it!=floors.end();it++){
            if(*it == track_up){
                count_up++;
                track_up++;
            }
            else{
                if(track_up>s){
                    break;
                }
            }
        }
        for(auto it=floors.end()-1;it!=floors.begin()-1;it--){
            if(*it == track_down){
                count_down++;
                track_down--;
            }
            else{
                if(track_down<s){
                    break;
                }
            }
        }
        ll ans = 0;
        if(count_up<count_down){
            ans = count_up;
        }
        else{
            ans = count_down;
        }
        if(track_down==0){
            ans = count_up;
        }
        if(track_up==n+1){
            ans = count_down;
        }
        cout<<ans<<"\n";
    }
    return 0;
}