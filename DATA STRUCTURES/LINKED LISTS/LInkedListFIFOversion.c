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
struct node* head = NULL;

//Returns new node with given data pointing to NULL
struct node * createNewNode(ll data){
    struct node * temp = malloc(sizeof(*temp));
    temp->data = data;
    temp->next = NULL;
    return temp;
} 

// Assuming   (This is front) head->1st->2nd->3rd  (this is Rear) 

//Function to add element at the end of list
void addRear(ll data){                 //Time complexity O(n) Worst case
    struct node * newnode = createNewNode(data);
    if(head!=NULL){
        struct node *traverse = head;
        while(traverse->next!=NULL){
            traverse = traverse->next;
        }
        traverse->next = newnode;
    }else{
        head = newnode;
    }
}

// Print the linked list
void printit(){
    struct node * traverse = head; 
    while(traverse!= NULL){                   //O(n)
        printf("%lld ",(traverse->data));
        traverse = traverse->next;
    }
    printf("\n");
}
//Function to pop an element from front this function will pop and return element from the front of linked list
ll popfront(){                          // Time complexity  O(1)
    struct node * front = head;
    head = head->next;
    ll data = front->data;
    free(front);
    return data;
}
int main(){
    addRear(3);
    addRear(2);
    addRear(1);
    printit();
    ll front = popfront();
    printit();
    printf("Front was %lld ",front);
    return 0;
}