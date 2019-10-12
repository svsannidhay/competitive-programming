//problem satement:-https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/stakth-1-e6a76632/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll unsigned long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll n,k;
    fio;
    cin>>n>>k;
    vector<ll> vec;
    stack<ll> s;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
    }
    for(auto it=vec.end()-1;it!=vec.begin()-1;it--){
        s.push(*it);
    }
    if(s.size()+1==k){
        //cout<<-1;
        //return 0;
    }
    if(k==1&&n==1){
        cout<<-1;
        return 0;
    }
    if(n==1&&k%2!=0){
        cout<<-1;
        return 0;
    }
    ll max = 0;
    for(ll i=0;i<k-1;i++){
            if(s.size()<1){
                break;
            }
            if(s.top()>max){
                max = s.top();
            }
            if(s.size()>=1){
            s.pop();
            }
    }
    s.push(max);
    ll top1 = s.top();
    if(s.size()>=3){
        s.pop();
        s.pop();
        ll top2 = s.top();
        if(top1>top2){
            cout<<top1;
        }
        else{
            cout<<top2;
        }
    }
    else{
        cout<<top1;
    }
    
    
    
    //cout<<s.top();
    
    return 0;
}
