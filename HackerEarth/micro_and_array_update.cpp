problem statement:- https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main(){
    int t;
    fio;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        long long int t=0;
        cin>>n>>k;
        vector < int > v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        t = k-(*min_element(v.begin(), v.end()));
        if(t>0){
        cout<<t<<"\n";
        }
        if(t<=0){
            cout<<0<<"\n";
        }
    }
    return 0;
}
