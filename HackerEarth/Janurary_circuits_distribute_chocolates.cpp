//Problem statement:- https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/distribute-chocolates-70c2c2ab/
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
using namespace std;
int main(){
    ull t;
    fio;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll c,n;
        cin>>c>>n;
        ll tmpc = c;
        tmpc = tmpc - (n*(n+1))/2;
        if(tmpc<0){
            cout<<c<<"\n";
        }
        else{
            cout<<tmpc%n<<"\n";
        }
    }
    return 0;
}
