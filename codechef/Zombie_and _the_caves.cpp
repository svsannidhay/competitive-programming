//problem statement :- https://www.codechef.com/AUG19A/problems/ZOMCAV
//easy-medium
// difference_arrays
// partially solved
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main(){
    int t;
    fio;
    cin>>t;
    while(t--){
        int n,t;
        cin>>n;
        t = n;
        vector<int> radpow;
        vector<int> health;
        vector<int> radlvl;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            radpow.push_back(x);
        }
         for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            health.push_back(x);
        }
        for(int i=1;i<=n;i++){
            radlvl.push_back(0);
        }
        for(int i=1;i<=n;i++){
            int iminci = i- radpow[i-1];
            int iplusci = i + radpow[i-1];
            if(iminci<=0){
             iminci = 1;   
            }
            if(iplusci>n){
                iplusci = n;
            }
            for(int i= iminci;i<=iplusci;i++){
                radlvl[i-1]++;
            }
        }
        
        sort(radlvl.begin(),radlvl.end());
        sort(health.begin(),health.end());
        for(int i=1;i<=n;i++){
            if(radlvl[i-1]!=health[i-1]){
                cout<<"NO"<<"\n";
                break;
            }
            if(i==n){
                cout<<"YES"<<"\n";
            }
        }
        
        /*
        for(auto it = radlvl.begin();it!=radlvl.end();it++){
            cout<<*it<<" ";
        }
        */
        
        
        
    }
    
}
