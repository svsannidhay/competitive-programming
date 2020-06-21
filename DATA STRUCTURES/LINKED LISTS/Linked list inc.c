/*
    Apporach:- 
        Brute force will be good enough
    Complexity :- 
        time complexity  :- O(n) 
        Space complexity :- O(n)     

    Coded and tested on visual studio code
    --> Ai can be 10^18 as all the integers are set to long long int          
    ///////////////////////////
        Solution by 
           ------Sannidhay Vashal
           --------- NIT srinagar
           2018BITE026
    ////////////////////////////

*/
#include<stdio.h>
#include <stdlib.h>
#define ll long long int
//Structure
struct node{
    ll data;
    struct node *next;
};
struct node *head = NULL; //Global

//Returns new node with given data poiting to NULL
struct node * createNewNode(ll data){
    struct node * temp = malloc(sizeof(*temp));
    temp->data = data;
    temp->next = NULL;
    return temp;
} 

//Inserts at begining
void insertBeg(ll data){
    struct node * current = createNewNode(data);
    if(head==NULL){
        head = current;
    }else{
        current->next = head;
        head = current;
    }
} 
// Print the linked list
void printit(){
    struct node * traverse = head; 
    while(traverse!= NULL){                   //O(n)
        printf("%lld ",(traverse->data));
        traverse = traverse->next;
    }
}
//Delete a node at given position 
void delete(ll pos){
    struct node * traverse = head;
    if(pos==1){
        struct node * deleteit = head;
        head = head->next;
        free(deleteit);
    }else{
        for(ll i=1;i<pos-1;i++){               // O(n) worst case
            traverse = traverse->next;
        }
        struct node *prev = traverse; 
        struct node * deleteit = traverse->next;
        traverse = traverse->next;
        prev->next = traverse->next;
        free(deleteit);
    }   
}
// Function to insert a value at a position
void insertAtPos(ll pos,ll val){
    struct node * current = createNewNode(val);
    if(pos==1){
        current->next = head;
        head = current;
    }else{
        struct node * traverse = head;
        for(ll i=1;i<pos-1;i++){            //O(n) worst case
            traverse = traverse->next;
        } 
        current->next = traverse->next;
        traverse->next = current;
    }
}
//main working function
void solve(ll length){
    if(length%2!=0){
        ll postodelete = length/2+1;
        struct node * traverse = head;
        for(ll i=1;i<postodelete;i++){           //O(n) worst case
            traverse = traverse->next;
        }
        printf("%lld \n",(traverse->data));
        delete(postodelete);
        printf("List after prossesing \n");
        printit();
    }else{
        ll postodelete1 = length/2;
        ll postodelete2 = length/2+1;
        struct node * travpos1 = head;
        struct node * travpos2 = head;
        for(ll i=1;i<postodelete1;i++){        //O(n)  worst case
            travpos1 = travpos1->next;
        }
        for(ll i=1;i<postodelete2;i++){      //O(n) worst case
            travpos2 = travpos2->next;
        }
        printf("%lld ",travpos1->data);
        printf("%lld \n",travpos2->data);
        ll valnew = travpos1->data + travpos2->data;
        delete(postodelete1);
        delete(postodelete2-1);
        insertAtPos(postodelete1,valnew);
        printf("List After processing\n");
        printit();
    }
}

int main(){
    ll n = 2;      //no of elements in linked list
    insertBeg(5);
    insertBeg(4);
    insertBeg(3);
    insertBeg(2);
    insertBeg(1);
    solve(n);
    return 0;
}