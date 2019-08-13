problem statement :- https://www.codechef.com/AUG19A/problems/DSTAPLS
easy one 
/*
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
using namespace std;
int main()
{
    fio;
    int t;
    cin>>t;
    while(t--)
    {
        ull n,k;
        ull flag=0,f=0;
        cin>>n>>k;
        if(k==1)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
        vector<ull> boxes;
        while(n>0)
        {
        for(ull i=0;i<k;i++)
        {
            boxes.push_back(k);
            n = n - k;
            if(n<=0&&i<k-1)       //simple approach 30 score
            {
                cout<<"YES"<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        }
        if(flag==0)
        {
            cout<<"NO"<<"\n";
        }
        }
       
    }
    
}
*/
/*
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
using namespace std;
int main()
{
    fio;
    int t;
    cin>>t;
    while(t--)
    {
        ull n,k;
        ull flag=0,f=0;
        cin>>n>>k;
        if(k==1)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
        ull l =1;
            while(n-(l*k*k)>0){
                l++;
            }
            
            l--;                     // 30 score again TLE in rest
            if(n-(l*k*k)==0){
                cout<<"NO"<<"\n";
                
            }
            else{
                cout<<"YES"<<"\n";
            }
    
            
        }
       
    }
    
}
*/

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long 
using namespace std;
int main()
{
    fio;
    int t;
    cin>>t;
    while(t--)
    {
        ull n,k;
        ull flag=0,f=0;
        cin>>n>>k;
        if(k==1)
        {
            
            cout<<"NO"<<"\n";
            
            
            
        }
        else
        {  
           ull m = k%1000000007;   // as k = 10^18 
           if(n%(m*m)==0){                        // generalising the loops to form a condition AC 100 score
               cout<<"NO"<<"\n";
           }
           else{
               cout<<"YES"<<"\n";
           }
        }
       
    }
    
}
