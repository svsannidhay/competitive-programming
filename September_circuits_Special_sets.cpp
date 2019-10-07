// problem statement:- https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/goodset-d526c2cb/
// medium - hard

#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
int main(){
    ull n;
    fio;
    cin>>n;
    ull number = n;            /*
                                 formula used (n-p)Cr = (n-p)!/((n-p-r)!*r!)
                                  ignore r!  here  p is the minimum integral gap b/w two elements
                                  and r is the no of elements in ordered set 
                                  calculate this from n = 2 to n/2+1 
                               */
    ull product = 1;
    vector<ull> fact;
    fact.push_back(1);
    for(ull i=1;i<=2000;i++){
        product = product * i;
        fact.push_back(product);
    }
    /*
    for(int i=0;i<=n;i++){
        cout<<fact[i]<<" ";
    }
    */
    //cout<<"\n";
    //number = number + (n-2)*(n-2+1);
    for(ull i=2;i<=(n/2)+1;i++){
      ull gap = i-1;
      ///fact[n-gap] = fact[n-gap]%1000000007;
      ///fact[n-gap-i] = fact[n-gap-i]%1000000007;
      //cout<<fact[n-gap]<<" ";
      //cout<<fact[n-gap-i]<<" ";
      ull x = n-gap;
      ull y = n-gap-i;
      ull permutation = 1;
      for(ull i=x;i>y;i--){
          permutation  = permutation*i;
          permutation = permutation%1000000007;
      }
      //ull permutation = fact[n-gap]/fact[n-gap-i];
      //cout<<permutation<<"\n";
      number = number + permutation;
    }
    if(n%2==0){
        number = number -1;
    }
    cout<<(number%1000000007);

}

// medium - hard
/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/*
created by :- Sannidhay 
created on 26.09.2019

*/
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
int main(){
    ull n;
    fio;
    cin>>n;
    ull number = n;            /*
                                 formula used (n-p)Cr = (n-p)!/((n-p-r)!*r!)
                                  ignore r!  here  p is the minimum integral gap b/w two elements
                                  and r is the no of elements in ordered set 
                                  calculate this from n = 2 to n/2+1 
                               */
    ull product = 1;
    vector<ull> fact;
    fact.push_back(1);
    for(ull i=1;i<=2000;i++){
        product = product * i;
        fact.push_back(product);
    }
    /*
    for(int i=0;i<=n;i++){
        cout<<fact[i]<<" ";
    }
    */
    //cout<<"\n";
    //number = number + (n-2)*(n-2+1);
    for(ull i=2;i<=(n/2)+1;i++){
      ull gap = i-1;
      ///fact[n-gap] = fact[n-gap]%1000000007;
      ///fact[n-gap-i] = fact[n-gap-i]%1000000007;
      //cout<<fact[n-gap]<<" ";
      //cout<<fact[n-gap-i]<<" ";
      ull x = n-gap;
      ull y = n-gap-i;
      ull permutation = 1;
      for(ull i=x;i>y;i--){
          permutation  = permutation*i;
          permutation = permutation%1000000007;
      }
      //ull permutation = fact[n-gap]/fact[n-gap-i];
      //cout<<permutation<<"\n";
      number = number + permutation;
    }
    if(n%2==0){
        number = number -1;
    }
    cout<<(number%1000000007);

}
