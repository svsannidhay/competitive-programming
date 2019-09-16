//problem statement:- https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/lex-finds-beauty-0d0bc1b6/
//easy one
//AC in second attempt 
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull long long int 
using namespace std;
int main(){
    ull n,k;
    cin>>n>>k;
    vector<ull> list;
    for(ull i=0;i<n;i++){
        ull x;
        cin>>x;
        list.push_back(x);
    }
    
    ull sum = 0;
    sort(list.begin(),list.end());
    for(auto it=list.begin();it!=(list.end()-k);it++){
        sum = sum + *it;
    }
    cout<<sum;
    return 0;
}
