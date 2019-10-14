//problem statement :-https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-monk-and-balanced-parentheses/
// medium
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll> vec;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
        
    }
    stack<ll> s;
    ll count = 0;
    ll max = 0;
    ll flag = 0;
    ll noofrun = 0;
    for(ll i=0;i<n;i++){
        if(s.size()==0){
            flag ++;
            s.push(vec[i]);
            if(count>max){
                max = count;
            }
            count = 0;
            //cout<<i<<" size "<<count<<"\n";
        }else{
            if(s.top()+vec[i]==0){
                s.pop();
                count++;
                noofrun++;
                
                
                //cout<<i<<" "<<count<<"\n";
                if(count>max){
                    max = count;
                }
                if(flag == 1&&noofrun>1){
                    max = max + count;
                }
                flag = 0;
                
            }
            else{
                flag ++;
                s.push(vec[i]);
                if(count>max){
                    max = count;
                }
                count = 0;
                //cout<<i<<" push "<<count<<"\n";
                
            }
        }
    }
    cout<<max*2;
    return 0;
}
