//problem statement :-https://www.hackerearth.com/problem/algorithm/a-contest-without-penalty-2eefb637/
//easy one
//AC in one go
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_With_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
using namespace std;
int main(){
    ull t;
    cin>>t;
    for(ull i=0;i<t;i++){
        ull no , n;
        cin>>no>>n;
        cout<<no + n-1;
        cout<<"\n";
    }
}
