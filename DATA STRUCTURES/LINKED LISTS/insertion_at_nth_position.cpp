#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<map>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
using namespace std;
struct Node{
    ll data;
    struct Node *next;
};
struct Node *head;
void insert(ll x,ll n){
    struct Node *temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    if(n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    
    struct Node *temp2 = head;
    for(ll i=0;i<n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next =  temp2->next;
    temp2->next = temp1;
    
}

void print(){
    struct Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    ll n;
    fio;
    cin>>n;
    while(n>0){
        n--;
        pair<int,int> x;
        cin>>x.first>>x.second;
        insert(x.first,x.second);
    }
    print();
}
