https://www.hackerearth.com/problem/algorithm/shortest-way/
//Basic optimization problem 
#include<iostream>
#include<vector>
#define fio ios_basE::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll x,y;
        ll count_steps = 0;
        cin>>x>>y;
        while(x!=1||y!=1){
            if(x>y){
                if(x>1){
                    ll rem = (x-1)%y;
                    count_steps += (x-1)/y;
                    x = rem + 1;
                }
                if(y>x){
                    if(y>1){
                        ll rem = (y-1)%x;
                        count_steps += (y-1)/x;
                        y = rem + 1;
                    }
                }
            }
            else{
                if(y>x){
                    if(y>1){
                        ll rem = (y-1)%x;
                        count_steps += (y-1)/x;
                        y = rem + 1;
                    }
                }
                if(x>y){
                    if(x>1){
                        ll rem = (x-1)%y;
                        count_steps += (x-1)/y;
                        x = rem + 1;
                    }
                }
            
            }
        }
    cout<<count_steps<<"\n";
    }
    return 0;
}
