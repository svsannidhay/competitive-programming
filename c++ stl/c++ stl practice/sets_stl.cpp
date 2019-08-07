problem statement :- https://www.hackerrank.com/challenges/cpp-sets/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


int main() {
    long long int n;
    fio;
    cin>>n;
    set<long long int> s;
    for(long long int i=0;i<n;i++ ){
        long long int x,y;
        cin>>x>>y;
        if(x==1){
         s.insert(y);
        }
        if(x==2){
            s.erase(y);
        }
        if(x==3){
            auto it = s.find(y);
            if(it==s.end()){
                cout<<"No"<<"\n";
            }
            else{
                cout<<"Yes"<<"\n";
            }
        }
    }

    return 0;
}
