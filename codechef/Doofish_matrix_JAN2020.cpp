//Problem statement :- https://www.codechef.com/JAN20B/problems/DFMTRX/
#include<iostream>
#include<math.h>
#include<vector>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll t;
    fio;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        if(n==1){
            cout<<"Hooray"<<"\n";
            cout<<1<<"\n";
            continue;
        }
        if(n%2!=0){
            cout<<"Boo"<<"\n";
        }
        else{
            n = n/2;
            ll dfmtrxA[2*n+1][2*n+1];
            for(ll i=1;i<=2*n;i++){
                for(ll j=1;j<=2*n;j++){
                    dfmtrxA[i][j] = 0;
                }
            }
            for(ll i=1;i<=2*n;i++){
                dfmtrxA[i][i] = (4*n)-1;
            }
            for(ll B=1;B<=(2*n)-1;B++){
                dfmtrxA[B][2*n] = B;
                dfmtrxA[2*n][B] = B + (2*n) -1;
                ll arr[2*n-1];
                ll x = B;
                ll y = B;
                for(ll i=1;i<=n-1;i++){
                    x--;
                    if(x == 0){
                        x = (2*n)-1;
                    }
                    y++;
                    if(y == (2*n)){
                        y = 1;
                    }
                    if(x>y){
                        dfmtrxA[y][x] = B;
                        dfmtrxA[x][y] = B + (2*n) -1;
                        //cout<<y<<","<<x<<"\n";
                    }
                    else{
                        dfmtrxA[x][y] = B;
                        dfmtrxA[y][x] = B + (2*n)-1;
                        //cout<<x<<","<<y<<"\n";
                    }
                }
            }
            cout<<"Hooray"<<"\n";
            for(ll i=1;i<=2*n;i++){
                for(ll j=1;j<=2*n;j++){
                    cout<<dfmtrxA[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        /*
        if(n%2!=0){
            cout<<"Boo"<<"\n";
        }
        else{
            ll start = 2;
            ll noOfEx = sqrt(n);
            ll dfmtrxA[2000][2000];
            dfmtrxA[1][1] = 1;
            dfmtrxA[1][2] = 2;
            dfmtrxA[2][1] = 3;
            dfmtrxA[2][2] = 1;
            ll dfmtrxB[2000][2000];
            ll dfmtrxC[2000][2000];
            for(ll i = 1;i<=2;i++){
                    for(ll j=1;j<=2;j++){
                        dfmtrxB[i][j] = dfmtrxA[i][j] + 4; 
                    }
            }
            for(ll i=1;i<=2;i++){
                for(ll j=1;j<=2;j++){
                    dfmtrxC[i][j] = dfmtrxB[i][j];
                    if(i == j){
                        dfmtrxC[i][j] = 2 * 2;
                    }
                }
            }
            
            for(ll ex = 4;ex<=n;ex*=2){
                for(ll i=((ex/2)+1);i<=ex;i++){
                    for(ll j=((ex/2)+1);j<=ex;j++){
                        dfmtrxA[i][j] = dfmtrxA[(i-(ex/2))][(j-(ex/2))];
                    }
                }
                
                for(ll i=1;i<=ex/2;i++){
                    for(ll j=((ex/2)+1);j<=ex;j++){
                        dfmtrxA[i][j] = dfmtrxB[i][j-ex/2];
                    }
                }
                for(ll i=((ex/2)+1);i<=ex;i++){
                    for(ll j=1;j<=ex/2;j++){
                        dfmtrxA[i][j] = dfmtrxC[i-ex/2][j];    
                    }
                }
    
                for(ll i = 1;i<=ex;i++){
                    for(ll j=1;j<=ex;j++){
                        dfmtrxB[i][j] = dfmtrxA[i][j] + (2*ex); 
                    }
                }
                for(ll i=1;i<=ex;i++){
                    for(ll j=1;j<=ex;j++){
                        dfmtrxC[i][j] = dfmtrxB[i][j];
                        if(i == j){
                            dfmtrxC[i][j] = 2 * (ex);
                        }
                    }
                }
                
            }
        
            cout<<"Hooray"<<"\n";
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    cout<<dfmtrxA[i][j]<<" "; 
                }
                cout<<"\n";
            }
        }
        */
    }
    return 0;
}
