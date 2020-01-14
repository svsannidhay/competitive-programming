// Problem statement :- https://www.codechef.com/JAN20B/problems/DYNAMO
#include<iostream>
#include<vector>
#include<math.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007;
using namespace std;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        ll a;
        cin>>a;
        ll number = pow(10,n);
        ll s = (number*2);
        s = s + a;
        cout<<s<<endl;
        ll b;
        cin>>b;
        ll c;
        c = (number) - b;
        cout<<c<<endl;
        ll d;
        cin>>d;
        ll e = (s - (a + b + c + d));
        cout<<e<<endl;
        ll correct;
        cin>>correct;
        if(correct==1){
            continue;
        }
        else{
            return 0;
        }
    }
    return 0;
}
