#include<iostream>
#include<vector>
#include<math.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
struct Node {
    ll data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;
struct Node *tail;
void insert_beg(ll val){
    struct Node *temp = new Node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else{
        //head->prev = temp;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        (temp->next)->prev = temp;
    }
}
void insert_end(ll val){

}
void print_dl(){
    struct Node *traversal = tail;
    while(traversal != NULL){
        cout<<traversal->data<<" ";
        traversal = traversal->prev;
    }
}
int main(){
    head = NULL;
    insert_beg(4);
    insert_beg(3);
    insert_beg(2);
    print_dl();
    return 0;
}
