// https://www.hackerearth.com/problem/algorithm/subtracting-till-possible-36230482/
// just a simple question no need of any s.material ... (basic problem   ) //very easy
#include<iostream>
using namespace std;
int main(){
    long long int n,m,k;
    cin>>n>>m>>k;
    long int moves=0;
    long int i=0;
    while(n>=0){
        n = n - (m - i);
        moves++;
        i++;
        if((i-1)==k){
            i=0;
        }
        
    }
    cout<<moves;
    return 0;
}
