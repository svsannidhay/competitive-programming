//problem statement:- https://www.hackerearth.com/problem/algorithm/too-many-numbers-a6a8ff18/
// hard to score AC
// MAX score yet 80/100 //issue TLE
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
using namespace std;
int main(){
    fio;
    ull n,m;
    cin>>n>>m;
    ull l,r;
    cin>>l>>r;
    ull k;
    cin>>k;
    vector<ull> list;
    ull check = n%m;
    ull checkk = 0;
    for(ull i=l;i<=r;i++){
        if(n%i==check&&i!=m){
            list.push_back(i);
            checkk++;
            if(checkk>k){
                cout<<-1<<"\n";
                break;
            }
        }
    }
    if(checkk<=k){
        cout<<checkk<<"\n";
        for(auto it=list.begin();it!=list.end();it++){
            cout<<*it<<" ";
        }
    }
    return 0;
}
