#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int 
using namespace std;
struct Node{
    ll data;
    struct Node *next;
};
struct Node *head ;
void insert_rear(ll x){
    struct Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head==NULL){
        temp->next = head;
        head = temp;
    }
    else{
        struct Node *temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}
void print(){
    struct Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void delete_node(ll n){
    struct Node *temp1 = head;
    if(n==1){
        head = temp1->next;
        delete temp1;
    }
    else{
        for(int i=1;i<=n-2;i++){
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}
int main(){
    ll n;
    cin>>n;
    while(n>0){
        n--;
        ll x;
        cin>>x;
        insert_rear(x);
    }
    print();
    cout<<"\n";
    ll x;
    
    cin>>x;
    while(x>0){
        x--;
        ll n;
        cin>>n;
        delete_node(n);
        print();
        cout<<"\n";
    }
    
    
}
