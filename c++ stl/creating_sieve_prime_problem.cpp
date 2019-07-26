https://www.hackerearth.com/problem/algorithm/prime-problem/
creating sieve 
#include<iostream>
#define  fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    fio;
    vector< int > sieve;
    for(int i=2;i<1000001;i++){
        sieve.push_back(i);
    }
    for(int i=2;i<=400;i++){
        for(auto j=sieve.begin();j!=sieve.end();j++){
            
            if(((*j)>=(i*i))&&(*j)%i==0){
               *j = -1;
            }
            
        }
    }
    sort(sieve.begin(),sieve.end());
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long int x;
        cin>>x;
        bool present = binary_search(sieve.begin(),sieve.end(),x);
        if(present == true){
            cout<<"True";
            cout<<"\n";
        }
        if(present == false){
            cout<<"False";
            cout<<"\n";
        }
    }
    
}
//generalised condition for sieve
#include<iostream>
#define  fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
    fio;
    vector< int > sieve;
    for(int i=2;i<100000;i++){
        sieve.push_back(i);
    }
    for(int i=2;i<=sqrt(100000);i++){
        for(auto j=sieve.begin();j!=sieve.end();j++){
            
            if(((*j)>=(i*i))&&(*j)%i==0){
               *j = -1;
            }
            
        }
    }
    sort(sieve.begin(),sieve.end());
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long int x;
        cin>>x;
        bool present = binary_search(sieve.begin(),sieve.end(),x);
        if(present == true){
            cout<<"True";
            cout<<"\n";
        }
        if(present == false){
            cout<<"False";
            cout<<"\n";
        }
    }
    
}
