//problem statement:- https://www.codechef.com/BIT22019/problems/BIT2A
// tags - easy
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull long long int
using namespace std;
int main(){
    ull t;
    fio;
    cin>>t;
    for(ull i=0;i<t;i++){
        vector<ull> A;
        ull n;
        cin>>n;
        int B[n] = {0};
        for(int i=0;i<n;i++){
            ull x;
            cin>>x;
            A.push_back(x);
            for(ull j=0;j<i;j++){
                if(A[j]<x){
                    B[j]++;
                }
            }
        }
        for(ull i=0;i<n;i++){
            cout<<B[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
