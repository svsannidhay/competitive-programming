#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long int

using namespace std;

bool solveNQueen(ll board[][10],ll i,ll n){
    //base case
    if(i==n){
        //we have sucessfully placed n queens on n*n board 
        //print the board
        return true;
    }
    for(ll j=0;j<n;j++){
        //check if i,j position is safe or not 
    }
}

int main()
{
    ll n;
    ll board[10][10];
    memset(board, 0, sizeof(board));

    return 0;
}