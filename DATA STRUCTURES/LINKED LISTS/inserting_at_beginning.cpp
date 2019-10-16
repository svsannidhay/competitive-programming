#include<iostream>
#include<list>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int 
using namespace std;
struct Node{
    ll data;
    struct Node *next;
};
struct Node *head;
void insert(ll x){
    struct Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print(){
    struct Node *temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    head = NULL;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        insert(x);
    }
    print();
}
