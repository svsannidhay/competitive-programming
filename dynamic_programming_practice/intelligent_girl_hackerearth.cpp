//problem statement:- https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/intelligent-girl-1/
// esay#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
vector<ull> dp;
ull index = 0;
ull create_dp(string s){
    if(index == s.length()){
            return 0;
    }
    if((s[index])%2==0){
        //s.pop_back();
        index++;
        ull val = 1 + create_dp(s);
        dp.push_back(val);
        return val;
    }
    else{
        //s.pop_back();
        index++;
        ull val = create_dp(s);
        dp.push_back(val);
        return val;
    }
    
}
int main(){
    string s,test;
    fio;    
    cin>>s;
    test = s;
    (create_dp(test));
    for(auto it = dp.end()-1;it!=dp.begin();it--){
        cout<<*it<<" ";
    }
    if(s[s.length()-1]%2==0){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
vector<ull> dp;
ull index = 0;
ull create_dp(string s){
    if(index == s.length()){
            return 0;
    }
    if((s[index])%2==0){
        //s.pop_back();
        index++;
        ull val = 1 + create_dp(s);
        dp.push_back(val);
        return val;
    }
    else{
        //s.pop_back();
        index++;
        ull val = create_dp(s);
        dp.push_back(val);
        return val;
    }
    
}
int main(){
    string s,test;
    fio;    
    cin>>s;
    test = s;
    (create_dp(test));
    for(auto it = dp.end()-1;it!=dp.begin();it--){
        cout<<*it<<" ";
    }
    if(s[s.length()-1]%2==0){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
