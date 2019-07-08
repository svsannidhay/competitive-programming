//https://www.hackerearth.com/challenges/competitive/june-circuits-19/algorithm/determine-the-winner-june-circuits-2019-f4713f29/
//A basic question from game theory
//smaterial links
//https://www.youtube.com/watch?v=HdRgnzRk56Q   (day 3 lecture 3 codechef)  //good one
// solution
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n,k;
        cin>>n>>k;
       
        if(k==1){
            if(n%2==0){
                cout<<"Dishant";
                cout<<"\n";
            }
            else{
                cout<<"Arpa";
                cout<<"\n";
            }
        }
        if(k>1){
            if(n%(k+1)==0){
                cout<<"Dishant";
                cout<<"\n";
            }
            else{
                cout<<"Arpa";
                cout<<"\n";
            }
            
        }
        
    }
    return 0;
}
