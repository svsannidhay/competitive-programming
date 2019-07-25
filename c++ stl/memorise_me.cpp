https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/memorise-me/
TLE:- using vectors 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector < int > v;
    vector<int >::iterator it;
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       v.push_back(x);
    }
    sort(v.begin(),v.end());
   
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int n;
        cin>>n;
        auto it2 = lower_bound(v.begin(),v.end(),n);
        auto it3 = upper_bound(v.begin(),v.end(),n);
        if((it3-it2)==0){
            cout<<"NOT PRESENT";
            cout<<"\n";
            continue;
        }
        cout<<it3-it2;
        cout<<"\n";
    }
    
    
    
    return 0;
}
TLE removed using fast I/O:-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector < int > v;
    vector<int >::iterator it;
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       v.push_back(x);
    }
    sort(v.begin(),v.end());
   
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int n;
        cin>>n;
        auto it2 = lower_bound(v.begin(),v.end(),n);
        auto it3 = upper_bound(v.begin(),v.end(),n);
        if((it3-it2)==0){
            cout<<"NOT PRESENT";
            cout<<"\n";
            continue;
        }
        cout<<it3-it2;
        cout<<"\n";
    }
    
    
    
    return 0;
}

