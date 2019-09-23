//problem statement:-https://www.hackerearth.com/challenges/competitive/september-circuits-19/algorithm/going-to-office-e2ef3feb/
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull long long int 
using namespace std;
int main(){
    fio;
    ull D,Donline,Doffline;
    cin>>D;
    Donline = D;
    Doffline = D;
    
    ull Oc,Of,Od;
    cin>>Oc>>Of>>Od;
    
    ull costonline = 0;
    costonline = costonline + Oc;
    Donline = Donline - Of;
    costonline = costonline + (Donline * Od);
    
    
    ull Cs,Cb,Cm,Cd;
    cin>>Cs>>Cb>>Cm>>Cd;
    ull costclassic = Cb;
    costclassic = costclassic + ((D/Cs)*Cm) + D*Cd;
    if(costonline<=costclassic){
        cout<<"Online Taxi";
    }
    else{
        cout<<"Classic Taxi";
    }
    
    return 0;
}

//very easy
