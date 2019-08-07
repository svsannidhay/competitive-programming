problem statement :- https://www.hackerrank.com/challenges/cpp-lower-bound/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


int main() {
    int n;
    fio;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);

    }   
    sort(v.begin(),v.end());
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        auto it = lower_bound(v.begin(),v.end(),n);
        if(*it==n){
            cout<<"Yes"<<" "<<(it-v.begin())+1<<"\n";
        }
        else{
            cout<<"No"<<" "<<(it-v.begin())+1<<"\n";
        }
    }
    return 0;
}
