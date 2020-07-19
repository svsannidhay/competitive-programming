#include<iostream>
#define ll long long int
using namespace std;
int main(){
    ll arr[6][6] = {0};
    ll ans = 0;
    for(ll i=1;i<=5;i++){
        for(ll j=1;j<=5;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                //cout<<abs(i-3)<<" "<<abs(j-3)<<"\n";
                ans = abs(i-3) + abs(j-3);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/*
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

*/