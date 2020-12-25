#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long int

using namespace std;

bool isSafe(ll board[][100],ll i,ll j,ll n){
    //checking in column
    for(ll row =0;row<i;row++){
        if(board[row][j]==1) return false;
    }
    //checking in left diagonal 
    ll xl = i;ll yl = j;
    while(xl>=0&&yl>=0){
        if(board[xl][yl]==1) return false;
        xl--;yl--;
    }
    //checking in right diagonal
    ll xr = i;ll yr = j;
    while(xr>=0&&yr<n){
        if(board[xr][yr]==1) return false;
        xr--;yr++;
    }
    return true;
}

bool solveNQueen(ll board[][100],ll i,ll n){
    //base case
    if(i==n){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<"X ";
            }
            cout<<"\n";
        }
        return true;
    }
    for(ll j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            // place the queen assuming i,j is the right position
            board[i][j] = 1;
            bool nextQueen = solveNQueen(board,i+1,n);
            if(nextQueen){
                return true;
            }
            // i,j is not the right position as nextQueen can't be placed. so we will backtrack and remove queen we just placed.
            board[i][j] = 0;
        }
    }
    //we have tried for all positions in the current row but could'nt place a queen.
    return false;
}



int main()
{
    ll n;
    cin>>n;
    ll board[100][100];
    // memset(board, 0, sizeof(board));
    // solveNQueen(board,0,n);
    ll sum = 0;
    ll curr = 26;
    ll mul = 1;
    while(sum<1000000000){
        sum += curr*mul;
        mul++;
    }
    cout<<mul<<" ";
    return 0;
}