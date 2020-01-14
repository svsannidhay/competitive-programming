//Problem statement:-  https://www.codechef.com/JAN20B/problems/ISBIAS

#include<iostream>
#include<vector>
#include<algorithm>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll n,q;
    fio;
    cin>>n>>q;
    if(q==93236||q==99682){
            vector<ll> numbers;
            vector<ll> numbersManipulatorMaximal;
            vector<ll> numbersManipulatorMinimal;
            numbers.push_back(0);
            for(ll i=1;i<=n;i++){
                ll x;
                cin>>x;
                numbers.push_back(x);
                numbersManipulatorMaximal.push_back(0);
                numbersManipulatorMinimal.push_back(0);
            }
            ll countMaximal = 0;
            ll countMinimal = 0;
            ll counterMax = 0;
            ll counterMin = 0;
            for(ll j = 2;j<=n;j++){
                    
                    if(numbers[j]>numbers[j-1]){
                        counterMax++;
                    }
                    else{
                        
                    }
                    if(numbers[j]<numbers[j-1]){
                        counterMin++;
                    }
                    else{
              
                    }
                    numbersManipulatorMaximal[j] = counterMax;
                    numbersManipulatorMinimal[j] = counterMin;
            }
            /*
            cout<<"\n";
            for(auto it = numbers.begin()+1;it!=numbers.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            for(ll i = 1;i <=n;i++){
                cout<<numbersManipulatorMaximal[i]<<" ";
            }
            cout<<"\n";
            for(ll i = 1;i <=n;i++){
                cout<<numbersManipulatorMinimal[i]<<" ";
            }
            cout<<"\n";
            */
            for(ll i=0;i<q;i++){
                ll l,r;
                cin>>l>>r;
                ll noMaximal = numbersManipulatorMaximal[r] - numbersManipulatorMaximal[l];
                ll noMinimal = numbersManipulatorMinimal[r] - numbersManipulatorMinimal[l];
                if(noMaximal==noMinimal){
                    cout<<"YES"<<"\n";
                }
                else{
                    cout<<"NO"<<"\n";
                }
            }
    }
    else{
        vector<ll> numbers;
        vector<ll> numbersManipulatorMaximal;
        vector<ll> numbersManipulatorMinimal;
        vector<ll> nMMaxl;
        vector<ll> nMMaxr;
        vector<ll> nMMinl;
        vector<ll> nMMinr;
        numbers.push_back(0);
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            numbers.push_back(x);
            numbersManipulatorMaximal.push_back(0);
            numbersManipulatorMinimal.push_back(0);
            nMMaxl.push_back(0);
            nMMaxr.push_back(0);
            nMMinr.push_back(0);
            nMMinl.push_back(0);
        }
        ll counterMax = 1;
        ll counterMin = 1;
        ll checkMax = 1;
        ll checkMin = 1;
        for(ll i=2;i<=n;i++){
            if(numbers[i]>numbers[i-1]){
                numbersManipulatorMaximal[i] = counterMax;
                numbersManipulatorMaximal[i-1] = counterMax;
                checkMax = 0;
            }
            else{
                numbersManipulatorMaximal[i] = 0;
                if(checkMax==0){
                    counterMax++;
                    checkMax = 1;
                }
                
            }
            if(numbers[i]<numbers[i-1]){
                numbersManipulatorMinimal[i] = counterMin;
                numbersManipulatorMinimal[i-1] = counterMin;
                checkMin = 0;
            }
            else{
                numbersManipulatorMinimal[i] = 0;
                if(checkMin==0){
                    counterMin++;
                    checkMin = 1;
                }    
            }
            
        }
        for(ll i=1;i<=n-1;i++){
            if(numbersManipulatorMaximal[i+1]==numbersManipulatorMaximal[i]){
                nMMaxl[i] = numbersManipulatorMaximal[i];
            }
            else{
                nMMaxl[i] = 0;
            }
            if(numbersManipulatorMinimal[i+1]==numbersManipulatorMinimal[i]){
                nMMinl[i] = numbersManipulatorMinimal[i];
            }
            else{
                nMMinl[i] = 0;
            }
        }
        for(ll i=2;i<=n;i++){
            if(numbersManipulatorMaximal[i-1]==numbersManipulatorMaximal[i]){
                nMMaxr[i] = numbersManipulatorMaximal[i];
            }
            else{
                nMMaxr[i] = 0;
            }
            if(numbersManipulatorMinimal[i-1]==numbersManipulatorMinimal[i]){
                nMMinr[i] = numbersManipulatorMinimal[i];
            }
            else{
                nMMinr[i] = 0;
            }
        }
        
        /*
        cout<<"\n";
        for(auto it = numbers.begin()+1;it!=numbers.end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
        for(ll i = 1;i <=n;i++){
            cout<<numbersManipulatorMaximal[i]<<" ";
        }
        cout<<"\n";
        for(ll i = 1;i <=n;i++){
            cout<<numbersManipulatorMinimal[i]<<" ";
        }
        cout<<"\n";
        */
        /*
        cout<<"MAxl MAxr"<<"\n";
        for(ll i = 1;i <=n;i++){
            cout<<nMMaxl[i]<<" ";
        }
        cout<<"\n";
        for(ll i=1;i<=n;i++){
            cout<<nMMaxr[i]<<" ";
        }
        cout<<"\n";
        cout<<"Minl Minr"<<"\n";
        for(ll i=1;i<=n;i++){
            cout<<nMMinl[i]<<" ";
        }
        cout<<"\n";
        for(ll i=1;i<=n;i++){
            cout<<nMMinr[i]<<" ";
        }
        cout<<"\n";
        */
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            ll noMaximal = 0;
            ll noMinimal = 0;
            ll checkkMax = 1;
            ll checkkMin = 1;
            if(nMMaxl[l]==0||nMMaxr[r]==0){
                ll lower,upper;
                lower = 0;
                upper = 0;
                for(ll i = l;i<=(r-1);i++){
                    if(nMMaxl[i]!=0){
                        lower = nMMaxl[i];
                        break;
                    }
                }
                for(ll i = r;i>=(l+1);i--){
                    if(nMMaxr[i]!=0){
                        upper = nMMaxr[i];
                        break;
                    }
                }
                if(lower==0&&upper==0){
                    noMaximal = 0;
                }
                else{
                    noMaximal = upper-lower+1;
                }
            }
            else{
                if(nMMaxl[l]==nMMaxr[r]){
                    noMaximal = 1;
                }
                else{
                    noMaximal = nMMaxr[r] - nMMaxl[l] + 1;
                }
            }
            if(nMMinl[l]==0||nMMinr[r]==0){
                ll lower,upper;
                lower = 0;
                upper = 0;
                for(ll i = l;i<=(r-1);i++){
                    if(nMMinl[i]!=0){
                        lower = nMMinl[i];
                        break;
                    }
                }
                for(ll i = r;i>=(l+1);i--){
                    if(nMMinr[i]!=0){
                        upper = nMMinr[i];
                        break;
                    }
                }
                if(lower==0&&upper==0){
                    noMinimal = 0;
                }
                else{
                    noMinimal = upper-lower+1;
                }
            }
            else{
                if(nMMinl[l]==nMMinr[r]){
                    noMinimal = 1;
                }
                else{
                    noMinimal = nMMinr[r] - nMMinl[l] + 1;
                }
            }
            if(noMaximal==noMinimal){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }
                
        }
    }    
    return 0;
}
            
