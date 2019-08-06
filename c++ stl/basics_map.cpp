#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

bool f(int x, int y){
    return x>y;
}
void vectordemo(){
    vector<int> A ={3,11,2,14};
    cout<<A[1]<<endl;
    sort(A.begin(),A.end());   //(NlogN)
    bool present = binary_search( A.begin() , A.end() , 3 ); //true
    cout<<present<<endl;
    present = binary_search( A.begin() , A.end() , 4 );    //false
    cout<<present<<endl;
    
    A.push_back(100);
    present = binary_search( A.begin() ,A.end() , 100);
    cout<<present<<endl;
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    
    /*vector<int>::iterator*/auto it = lower_bound(A.begin(),A.end(),100);  //>= 
    /*vector<int>::iterator*/auto it2 = upper_bound(A.begin(),A.end(),100); //>
    cout<<*it<<" "<<*it2<<endl;
    cout<< it2 - it<<endl;
    
    sort(A.begin(),A.end(),f);   //sorting in desending order
    /*
    vector<int>::iterator it3;
    for(it3 = A.begin();it3 != A.end();it3++){             
        cout<<*it3<<" ";                               //printing a vector
    }
    */
    for(int &x: A){
        x++;              //reference
    }
    for(int x: A){
        cout<<x<<" ";      //printing
    }
    
}
void setDemo(){
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);
    for(int x: S){
        cout<<x<<" ";
    }
    cout<<endl;
    auto it = S.find(-1);
    if(it== S.end()){
        cout<<"NOT PRESENT"<<endl;
    }
    else{
        cout<<"PRESENT"<<endl;
        cout<<*it<<endl;
    }
    auto it2 = S.lower_bound(-1);
    auto it3 = S.upper_bound(-1);
    cout<<"it2 "<<*it2<<endl;
    cout<<"it3 "<<*it3<<endl;
    auto it4 = S.lower_bound(2);
    if(it4== S.end()){
        cout<<"lol\n";
    }
    else{
        cout<<*it4<<endl;
    }
    auto it5 = S.upper_bound(2);
    if(it5==S.end()){
        cout<<"lol\n";
    }
    else{
        cout<<*it5<<endl;
    }
}
void mapDemo(){
    map<int ,int > A;
    A[1]=100;
    A[2]=-1;
    A[3]=200;
    A[100000232]=1;
    
    map<char,int> cnt;
    string x ="sannihday vashalz";
    for(char c: x){
        cnt[c]++;
    }
    cout<<cnt['a']<<" "<<cnt['z']<<endl;
}
void example(){
    set< pair< int ,int > > S;
    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    S.insert({401,450});
    int point = 50;
    auto it = S.upper_bound({point, INT_MAX});
    it--;
    pair<int,int> current = *it;
    cout<<current.first<<" "<<current.second;
    
}
int main(){
    mapDemo();
    //setDemo();
    return 0;
}
// example 
// problem statement :-https://www.hackerrank.com/challenges/cpp-maps/problem
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





