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
    if(head == NULL){
        head = temp;
    }
    else{
        struct Node *p = head;
        while((p->next) != NULL){
            p = p->next;
        }
        p->next= temp;
    }
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
    cin>>n;
    while(n>0){
        n--;
        ll x;
        cin>>x;
        insert(x);
    }
    print();
}
