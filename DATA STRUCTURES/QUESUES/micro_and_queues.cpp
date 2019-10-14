// very basic just learning syntax n stuff
#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        char c ;
        cin>>c;
        if(c=='E'){
            int x;
            cin>>x;
            q.push(x);
            cout<<q.size();
            cout<<"\n";
        }
        if(c=='D'){
            if(q.size()!=0){
                cout<<q.front()<<" ";
                q.pop();
                cout<<q.size()<<"\n";
            }
            else{
                cout<<-1<<" "<<q.size()<<"\n";
            }
        }
    }
}
