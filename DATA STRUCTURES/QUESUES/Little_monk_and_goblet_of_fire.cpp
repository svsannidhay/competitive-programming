//problem statement:-https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/little-monk-and-goblet-of-fire/
//easy-medium
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fio ios_base::sync_with(stdio);cin.tie(NULL)
#define ll long long int
using namespace std;
int main(){
    ll q;
    cin>>q;
    queue<ll> que[5],q_order;
    for(ll i=0;i<q;i++){
        char c;
        cin>>c;
        if(c=='E'){
            ll a,b;
            cin>>a>>b;
            if(que[a].empty()){
                q_order.push(a);
            }
            que[a].push(b);
        }
        if(c=='D'){
            ll x = q_order.front();
            cout<<x<<" "<<que[x].front()<<"\n";
            que[x].pop();
            if(que[x].empty()){
                q_order.pop();
            }
        }
        
    }
    
    
    return 0;
}
