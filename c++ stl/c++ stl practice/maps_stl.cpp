problem statement:- https://www.hackerrank.com/challenges/cpp-maps/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


int main() {
    map< string ,int> m;
    fio;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      int quary;
      cin>>quary;
      if(quary==1){
          string s;
          int marks;
          cin>>s;
          cin>>marks;
          map<string,int>::iterator it = m.find(s);
          if(it==m.end()){
          m.insert(pair<string,int> (s,marks));
          }
          else{
              m[s] = m[s] + marks;
          }
      }
      if(quary==2){
          string s;
          cin>>s;
          m.erase(s);
      }
      if(quary==3){
         string s;
         cin>>s;
         cout<<m[s]<<"\n"; 
      }

    }

    return 0;
}
