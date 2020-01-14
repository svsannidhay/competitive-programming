//Problem statement :- https://www.codechef.com/JAN20B/problems/ANTHILL
//Approximation problem
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll n,m,a,r;
    cin>>n>>m>>a>>r;
    ll graph[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            graph[i][j] = -1;
            if(i==j){
                graph[i][j] = -100;   //invalid ones
            }
        }
    }
    ll inputOrder = 1;
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        if(graph[x][y]==-1){
            if(graph[y][x]>=1){
            
            }
            else{
                graph[x][y] = inputOrder;
                inputOrder++;
            }
        }
    }
    inputOrder--;
    ll countIns2 = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(graph[i][j]>=1){
                for(ll k=1;k<=n;k++){
                    if((graph[j][k]>graph[i][j])&&i!=k){
                        if(graph[i][k]>0||graph[k][i]>0){
                        }
                        else{
                            if(graph[i][k]!=0){
                                graph[i][k] = 0;
                                countIns2 ++;
                            }
                        }
                    }
                }
            }
        }
    }

    ll divv=1;
    ll countIns1 = inputOrder/divv;
    if((m%divv)!=0){
        countIns1 = countIns1 + 1;
    }
    countIns2 = 0;
    ll totalNoOfIns = countIns2 + countIns1;
    cout<<totalNoOfIns;
    ll controller = 0;
    ll sum = 0;
    ll arr[10];
    for(ll i=1;i<=inputOrder;i++){
        for(ll j = 1;j<=n;j++){
            for(ll k = 1;k<=n;k++){
                
                if(graph[j][k]==i){
                   cout<<"\n"<<1<<" "<<1<<" "<<j<<" "<<k;
                }

                
            } 
        }
    }
    cout<<"\n";
    if(sum>1000000)
    {
        for(ll i=0;i<100000000000000000;i++){
            cout<<"FUNCK E";
        }
    }
    /*
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(graph[i][j]==0){
                cout<<2<<" "<<i<<" "<<j<<"\n";
            }    
        }
    }
    */
    return 0;
}
