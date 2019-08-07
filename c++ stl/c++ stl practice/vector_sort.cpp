problem statement :- https://www.hackerrank.com/challenges/vector-sort/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int size=0;
    cin>>size;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto it= v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
