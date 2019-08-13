//problem statement :- https://www.codechef.com/AUG19A/problems/MSNSADM1
//very-easy
//basic looping and vectors
#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
int main(){
    fio;
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        long long int n;
        cin>>n;
        vector <long long int > goals;
        for(long long int i=0;i<n;i++){
            long long int x;
            cin>>x;
            goals.push_back(x);
        }
        vector <long long int > fouls;
        vector<long long int> score;
        for(long long int i=0;i<n;i++){
            long long int x;
            cin>>x;
            fouls.push_back(x);
            score.push_back(0);
        }
        for(int i=0;i<n;i++){
            score[i] = score[i] + goals[i]*20 - fouls[i]*10;
            if(score[i]<0){
                score[i]=0;
            }
        }
        sort(score.begin(),score.end());
        cout<<score[n-1]<<"\n";
    }
    
}
