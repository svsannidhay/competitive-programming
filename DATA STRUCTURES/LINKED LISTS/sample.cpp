#include<iostream>
#define ll long long int
using namespace std;
struct node{
    ll data;
    struct node *link;
};
node *root = NULL;
node *get(ll data){
    node *tmp = new node;
    tmp->data = data;
    tmp->link = NULL;
    return tmp;
}
void insert_beg(ll data){
    if(root==NULL){
        root = get(data);
    }else{
        node *tmp = get(data);
        tmp->link = root;
        root = tmp;
    }
}
void insert_end(ll data){
    node *travel = root;
    while(travel->link!=NULL){
        travel = travel->link;
    }
    travel->link = get(data);
}
void insert_pos(ll data,ll pos){
    node *travel = root;
    for(ll i=0;i<pos-2;i++){
        travel = travel->link;
    }
    node *n = get(data);
    n->link = travel->link;
    travel->link = n;
}
void print(){
    node *trv = root;
    while(trv!=NULL){
        cout<<trv->data<<" ";
        trv = trv->link;
    }
} 
int main(){
    insert_beg(5);
    insert_beg(10);
    insert_beg(12);
    insert_end(1);
    insert_pos(3,3);
    print();
    return 0;
}