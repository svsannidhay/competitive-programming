problem statement :- https://www.hackerrank.com/challenges/vector-erase/problem
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);    
    }
    int a;
    int b,c;
    cin>>a;
    cin>>b>>c;
    v.erase(v.begin()+a-1);
    v.erase(v.begin()+b-1,v.begin()+c-1);
    vector<int>::iterator it;
    cout<<(v.begin()-v.end())*-1<<"\n";
    for(it =v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
