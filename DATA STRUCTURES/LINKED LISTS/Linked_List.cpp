#include<iostream>
#include<vector>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigend long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
struct Node{
    ll data;
    struct Node *next;
};



void insertBeg( ll value,struct Node ** pointerToHead){
    struct Node *temp = new Node;
    temp->data = value;
    temp->next = *pointerToHead;
    *pointerToHead = temp;
} 
void insertEnd( ll value,struct Node ** pointerToHead){
    struct Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(*pointerToHead == NULL){
        *pointerToHead = temp;
    }
    else{
        struct Node *traversal = *pointerToHead;
        while(traversal->next!=NULL){
            traversal = traversal->next;
        }
        traversal->next = temp;
    }
}
void insertPosition(ll value, ll pos,struct Node ** head){
    struct Node *temp = new Node ;
    temp->data = value;
    temp->next = NULL;
    struct Node *traversal = *head;
    if(pos==1){
        temp->next = *head;
        *head = temp;
    }
    for(ll i = 1;i<=pos-2;i++){
        traversal = traversal->next;  
    }
    struct Node * prev = traversal;
    struct Node * front = traversal->next; 
    prev->next = temp;
    temp->next = front;

}

void deleteNode(ll pos,struct Node **ptrToHead){
    if(pos == 1){
        struct Node * prev = *ptrToHead;
        *ptrToHead = (*ptrToHead)->next;
        delete(prev);
    }
    else{
        struct Node *traversal = *ptrToHead;
        struct Node *prev, *current;
        for(ll i=1;i<=pos-2;i++){
            traversal = traversal->next;
        }
        prev = traversal;
        current = traversal->next;
        prev->next = current->next;
        delete(current);
    }

}

void reverseLinkedList(struct Node **ptrToHead){
    struct Node *traversal , *prev ,*current ,*front ;
    prev = NULL;
    traversal = *ptrToHead;
    while(traversal!=NULL){
        current = traversal;
        front = traversal->next;
        current->next = prev;
        traversal = front;
        prev = current;
    }
    *ptrToHead = prev;
}
void printLinkedList(struct Node ** pointerToHead){
    struct Node *traversal = *pointerToHead;
    while(traversal!=NULL){
        cout<<traversal->data<<" ";
        traversal = traversal->next;
    }
}
void printLinkedListRecursive(struct Node** pointerToHead){
     if(*pointerToHead == NULL){

     }
     else{
         struct Node * current = *pointerToHead;
         cout<<current->data<<" ";
        printLinkedListRecursive(&(current->next));
     }   
}
void printLinkedListRecursiveReverse(struct Node** pointerToHead){
     if(*pointerToHead == NULL){
         return;
     }
     else{
        struct Node * current = *pointerToHead; 
        printLinkedListRecursive(&(current->next));
        cout<<current->data<<" ";
     }   
}

int main(){
    struct Node * head = NULL;
    insertBeg(3, & head);
    insertBeg(4, & head); 
    insertEnd(8, & head);
    insertEnd(9, & head);
    insertBeg(1, & head);
    insertPosition(5,3, & head);
    insertPosition(4,4, & head);
    insertBeg(2, & head);
    insertEnd(9, & head);
    insertPosition(7,1,&head);
    insertPosition(6,10,&head);
    deleteNode(1,&head);
    reverseLinkedList(&head);
    printLinkedList( & head);
    cout<<"\n";
    printLinkedListRecursive(& head);
    cout<<"\n";
    printLinkedListRecursiveReverse(& head);
    return 0;
}