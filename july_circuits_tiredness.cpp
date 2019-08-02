problem statement:- https://www.hackerearth.com/problem/approximate/saye-5d0558c3/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int xi,yi,xf,yf,co;
    cin>>xi>>yi>>xf>>yf>>co;
    int x[n],y[n],fx[n],fy[n],cc[n];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>fx[i]>>fy[i]>>cc[i];
        if(x[i]>=xf||y[i]>=yf){
            x[i]=-1;
            //cout<<x[i]<<y[i]<<endl;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            m++;
        }
    }
    cout<<m+2<<endl;
    cout<<xi<<" "<<yi<<" ";
    int l=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            if(l==0){
            cout<<x[i]<<" "<<y[i]<<" "<<0<<"\n"<<x[i]<<" "<<y[i]<<" "<<fx[i]<<" "<<fy[i]<<" "<<i<<endl;
            l=i;
            }
            else{
                cout<<x[i-1]<<" "<<y[i-1]<<" "<<x[i]<<" "<<y[i]<<i<<endl;
            }
        }
    }
    cout<<x[l]<<" "<<y[l]<<" "<<xf<<" "<<yf<<" "<<0;
    
    
    return 0;
}
*/
/*
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int xi,yi,xf,yf,co;
    cin>>xi>>yi>>xf>>yf>>co;
    int x[n],y[n],fx[n],fy[n],cc[n];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>fx[i]>>fy[i]>>cc[i];
        if(x[i]>=xf||y[i]>=yf){
            x[i]=-1;
            //cout<<x[i]<<y[i]<<endl;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            m++;
        }
    }
    //cout<<m+2<<endl;
    cout<<100000+1<<endl;
    cout<<xi<<" "<<yi<<" ";
    int l=0;
    for(long long int i=1;i<=100000 - 1;i++){
        //if(x[i]!=-1){
            if(l==0){
            cout<<1<<" "<<1<<" "<<0<<"\n"<<1<<" "<<1<<" "<<100000<<" "<<100000<<" "<<0<<endl;
            l++;
            }
            else if(l%2==0){
                cout<<1<<" "<<1<<" "<<100000<<" "<<100000<<" "<<0<<endl;
                l++;
            }
            else if(l%2!=0){
                cout<<100000<<" "<<100000<<" "<<1<<" "<<1<<" "<<0<<endl;
                l++;
            }
        //}
    }
    if(l%2!=0){
    cout<<100000<<" "<<100000<<" "<<xf<<" "<<yf<<" "<<0;
    }
    if(l%2==0){
    cout<<1<<" "<<1<<" "<<xf<<" "<<yf<<" "<<0;    
    }
    
    
    return 0;
}
*/
/*
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int xi,yi,xf,yf,co;
    cin>>xi>>yi>>xf>>yf>>co;
    int x[n],y[n],fx[n],fy[n],cc[n];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>fx[i]>>fy[i]>>cc[i];
        if(x[i]>=xf||y[i]>=yf){
            x[i]=-1;
            //cout<<x[i]<<y[i]<<endl;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            m++;
        }
    }
    //cout<<m+2<<endl;
    cout<<100000+1<<endl;
    cout<<xi<<" "<<yi<<" ";
    int l=0;
    for(int i=1;i<=100000 - 1;i++){
        //if(x[i]!=-1){
            if(l==0){
               
               
                  cout<<1<<" "<<1<<" "<<0<<"\n"<<1<<" "<<1<<" "<<100000<<" "<<100000<<" "<<0<<endl;
                  l++;
               
               
            }
            else if(l%2==0){
                cout<<1<<" "<<1<<" "<<100000<<" "<<100000<<" "<<0<<endl;
                l++;
            }
            else if(l%2!=0){
                cout<<100000<<" "<<100000<<" "<<1<<" "<<1<<" "<<0<<endl;
                l++;
            }
        //}
    }
    if(l%2!=0){
    cout<<100000<<" "<<100000<<" "<<xf<<" "<<yf<<" "<<0;
    }
    if(l%2==0){
    cout<<1<<" "<<1<<" "<<xf<<" "<<yf<<" "<<0;    
    }
    
    
    return 0;
}
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main(){
    int n,d;
    fio;
    cin>>n>>d;
    int xi,yi,xf,yf,co;
    cin>>xi>>yi>>xf>>yf>>co;
    int x[n],y[n],fx[n],fy[n],cc[n];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>fx[i]>>fy[i]>>cc[i];
        if(x[i]>=xf||y[i]>=yf){
            x[i]=-1;
            //cout<<x[i]<<y[i]<<endl;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            m++;
        }
    }
    //cout<<m+2<<endl;
    cout<<5+1<<endl;
    cout<<xi<<" "<<yi<<" ";
    int l=0;
    for(int i=1;i<=5 - 1;i++){
        //if(x[i]!=-1){
            if(l==0){
            cout<<1<<" "<<1<<" "<<0<<"\n"<<1<<" "<<1<<" "<<5<<" "<<5<<" "<<0<<endl;
            l++;
            }
            else if(l%2==0){
                cout<<1<<" "<<1<<" "<<5<<" "<<5<<" "<<0<<endl;
                l++;
            }
            else if(l%2!=0){
                cout<<5<<" "<<5<<" "<<1<<" "<<1<<" "<<0<<endl;
                l++;
            }
        //}
    }
    if(l%2!=0){
    cout<<5<<" "<<5<<" "<<xf<<" "<<yf<<" "<<0;
    }
    if(l%2==0){
    cout<<1<<" "<<1<<" "<<xf<<" "<<yf<<" "<<0;    
    }
    
    
    return 0;
}
/*
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int xi,yi,xf,yf,co;
    cin>>xi>>yi>>xf>>yf>>co;
    int x[n],y[n],fx[n],fy[n],cc[n];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>fx[i]>>fy[i]>>cc[i];
        if(x[i]>=xf||y[i]>=yf){
            x[i]=-1;
            //cout<<x[i]<<y[i]<<endl;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            m=m+2;
        }
    }
    cout<<m+1<<endl;
    cout<<xi<<" "<<yi<<" ";
    
    int l=0;
    int last = 0;
    int cond=0;
    for(int i=1;i<=n;i++){
        if(x[i]!=-1){
            if(l==0){
              if(xi==1&&yi==1){    
                    cout<<x[i]<<" "<<y[i]<<" "<<0<<endl;
                    l++;
                    last = i;
                }
                else{
                   cout<<1<<" "<<1<<" "<<0<<"\n"<<1<<" "<<1<<" "<<x[i]<<" "<<y[i]<<" "<<0<<"\n";;
                   last=i;
               }  
            
                
                if(l==1){
                    //cout<<x[i]<<" "<<y[i]<<" "<<fx[i]<<" "<<fy[i]<<" "<<i<<endl;
                    last = i;
                }
                if(l==0){
                    //cout<<x[i]<<" "<<y[i]<<" "<<fx[i]<<" "<<fy[i]<<" "<<i<<endl;
                    last = i;
                    l++;
                }
                
            }
            if(l>=1){
                if(x[i]!=-1){
                cout<<x[i]<<" "<<y[i]<<" "<<fx[i]<<" "<<fy[i]<<" "<<i<<endl;
                cout<<fx[i]<<" "<<fy[i]<<" ";
                for(int j=i+1;j<=n;j++){
                   if(x[j]!=-1){
                   cout<<x[j]<<" "<<y[j]<<" "<<0<<endl;
                   cond = 1;
                   break;
                       
                   }
                    
                }
                }
                l++;
                last = i;
            }
            
        }
    }
    
    /*if(l%2!=0)*///{
    //if(cond==1){
    //cout/*<<fx[last]<<" "<<fy[last]<<" "*/<<xf<<" "<<yf<<" "<<0;
    //}
    //}
    //else if(cond==0){
     //       cout<<fx[last]<<" "<<fy[last]<<" "<<xf<<" "<<yf<<" "<<0;
    //}
    /*
    if(l%2==0){
    cout<<fx[last]<<" "<<fy[last]<<" "<<xf<<" "<<yf<<" "<<0;    
    }
    */
    //cout<<fx[l]<<" "<<fy[l]<<" "<<xf<<" "<<yf<<" "<<0;
    
    
  //  return 0;
//}
//*/
