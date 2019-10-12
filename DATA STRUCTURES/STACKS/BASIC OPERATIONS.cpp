void push(int stack[],int x,int n){
   if(top==n-1){
      cout<<"Stack is full overflow";
   }
   else{
      top = top + 1;  
      stack[top] = x;
   }
}
void pop(int stack[],int n){
    if(isEmpty()==true){
        cout<<"Stack is empty underflow";
    }
    else{
        top = top -1;  
    }

}
int topElement(){
    return stack[top];
}
bool isEmpty(){
   if(top==-1){
       return true;   
   }
   else{
       return false;
   } 

}
int size(){
   return top+1;
}