/*

Solution by 
     ---------Sannidhay Vashal
	 --------NIT SRINAGAR
 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<vector>
 
#define ll long long int
#define ull unsigned long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define cinll(x) ll x;cin>>x;
#define cout(x) cout<<x;
#define MOD 1000000007
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef0(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
 
using namespace std;

int main(){
  fio;
  cinll(t);
  for(ll i=0;i<t;i++){
	  cinll(n);
	  vector<ll> king;
	  vector<ll> queen;
	  for(ll i=0;i<=n;i++){
		  king.push_back(1);
		  queen.push_back(1);
	  }
	  ll op=0;
	  for(ll i=1;i<=n;i++){
		  cinll(num);
		  for(ll j=1;j<=num;j++){
				cinll(x);
				if(king[x]==1&&queen[i]==1){
					queen[i] = 0;
					king[x] = 0;
					op++;
				}
		  }
	  }
	  if(op==n){
		  cout<<"OPTIMAL"<<"\n";
	  }
	  else{
		  ll q=0;
		  ll k=0;
		  for(ll i=n;i>=1;i--){
			  if(queen[i]==1){
				  q = i;
				  for(ll j=1;j<=n;j++){
					  if(king[j]==1){
						  k = j;
						  break;
					  }
				  }
			  }
		  }
		  if(k>0&&q>0){
			  cout<<"IMPROVE"<<"\n";
			  cout<<q<<" "<<k<<"\n";
		  }
		  else{
			  cout<<"OPTIMAL"<<"\n";
		  }


	  }

  }
  return 0;
}