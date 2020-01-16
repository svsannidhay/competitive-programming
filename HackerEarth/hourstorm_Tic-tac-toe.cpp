// problem statement:- https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/tic-tac-toe-thingy-7ce8b17b/
// too many side cases took me 45 min to solve this in an one hour contest
#include<iostream>
using namespace std;
int main(){
    //int arr[3][3];
    int countO=0,countX=0,flag=0,count_=0,x_won=0,o_won=0;
    string s[4];
    for(int i=1;i<=3;i++){
        cin>>s[i];
        for(int j=0;j<=2;j++){
            if(s[i][j]=='O'){
                countO++;
            }
            if(s[i][j]=='X'){
                countX++;
            }
            if(s[i][j]=='.'){
                count_++;
            }
        } 
    }
    
    if(countO>countX){                          //early elimination
        cout<<"Wait, what?";
        flag=1;
        goto x;
    }
    if(countX>=countO+2){
        cout<<"Wait, what?";
        flag=1;
        goto x;
    }                                            // elimination ends
    
    
    for(int i=1;i<=3;i++){                      //checking horizontals cases
        if(s[i]=="XXX"){
            if(countO<countX){
                cout<<"X won.";
                x_won++;
            }
            else if(countO==countX){
                cout<<"Wait, what?";
            }
            flag=1;
            goto x;
        }
        if(s[i]=="OOO"){
            if(countO+1==countX){
            cout<<"O won.";
            o_won++;
            }
            else{
                cout<<"Wait, what?";
            }
            flag=1;
            goto x;
            
        }
    }                                         //horizontal check ends
    
    
    for(int i=1;i<=3;i++){                        //checking verticals cases
        if(s[1][i]=='X'&&s[2][i]=='X'&&s[3][i]=='X'){
            if(countO<countX){
            cout<<"X won.";
            x_won++;
            }
            else{
                cout<<"Wait, what?";
            }
            flag =1;
            goto x;
        }
        if(s[1][i]=='O'&&s[2][i]=='O'&&s[3][i]=='O'){
            if(countX<countO){
            cout<<"O won.";
            o_won++;
            }
            else{
                cout<<"Wait, what?";
            }
            flag=1;
            goto x;
        }   
    }                                                      //vertical check ends
    
    
    
    if(s[1][0]=='X'&&s[2][1]=='X'&&s[3][2]=='X'){         // diagonal checking
        if(countO<countX){
        cout<<"X won.";
        x_won++;
        }
        else{
            cout<<"Wait, what?";
        }
        flag=1;
        goto x;
    }
    if(s[1][0]=='O'&&s[2][1]=='O'&&s[3][2]=='O'){
        cout<<"O won.";
        o_won++;
        flag=1;
        goto x;
    }
    if(s[1][2]=='X'&&s[2][1]=='X'&&s[3][0]=='X'){
        if(countO<countX){
        cout<<"X won.";
        x_won++;
        }
        else{
            cout<<"Wait, what?";
        }
        flag = 1;
        goto x;
    }
    if(s[1][2]=='O'&&s[2][1]=='O'&&s[3][0]=='O'){
        cout<<"O won.";
        o_won++;
        flag = 1;
        goto x;
    }                                                 // diagonals closed
    
    if(x_won==o_won){
        
    }
    
    if(count_>0){                                  // turn calculator
        if(countX==countO){                         
            cout<<"X's turn.";
            flag=1;
            goto x;                       
        }
        if(countX==countO+1){
            cout<<"O's turn.";
            flag=1;
            goto x;                                 
        }
    }
    
    
    x:;
    if(flag==0){                                 // checking draw or not
        cout<<"It's a draw.";
    }

}
