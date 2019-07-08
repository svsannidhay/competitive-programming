//https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/practice-problems/algorithm/prime-ministers-number/
// implimentation for sieve's algorithm to find prime numbers // time complexity 
//study links
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
                                                    /*
                                                    for(int i=a;i<=b;i++){
                                                        int temp,sum=0,flag = 0,cond1=0;
                                                        if(i%2!=0){
                                                        for(int j=2;j<(i/2)+1;j++){
                                                            if(i%j==0){
                                                                cond1=1;
                                                            }
                                                        }

                                                        if(cond1==0){    
                                                            temp = i;                        //ordinary approach
                                                            while(temp>0){
                                                                int digit = temp%10;
                                                                sum = sum + digit;
                                                                temp = temp/10;
                                                            }
                                                            for(int i=2;i<(sum/2)+1;i++){
                                                                if(sum%i==0){
                                                                    flag =1;
                                                                }
                                                            }
                                                            if(flag==0){
                                                                cout<<i<<" ";
                                                            }

                                                        }

                                                    }
                                                    }
                                                    */
    int arr[(b-a)+1];
    int index =1;
    for(int i=a;i<=b;i++){
        arr[index] = i;                          //using sieve algorithm
        index ++;
        
    }
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=(b-a)+1;j++){
            if(arr[j]>=(i*i)&&arr[j]%i==0){
                arr[j] = 0;
            }
        }
    }
    for(int i=1;i<=(b-a)+1;i++){
        if(arr[i]!=0){
            int sum =0,temp,flag=0;
            temp = arr[i];
            while(temp>0){
                sum = sum + temp%10;
                temp =temp/10;
            }
            for(int i=2;i<sum;i++){
                if(sum%i==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<arr[i]<<" ";
            }
        }
    }
    
    
    return 0;
    
}
