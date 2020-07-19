/*
	Solution by:- 
	--------------Sannidhay Vashal
	----------------NIT SRINAGAR
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<climits>
#include<set>
#include<unordered_map>
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll            long long int
#define ull           unsigned long long int
#define cinll(x)      ll x;cin>>x;
#define cini(x)       int x;cin>>x;
#define cins(x)       string x;cin>>x;
#define vect(x)       vector<ll> x;
#define vect1(x)      vector<ll> x;x.push_back(0);
#define pb(x)         push_back(x)
#define mp(x,y)       make_pair(x,y)
#define MAX           1e18
#define MIN           -1e18
#define MOD           1000000007
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}

using namespace std;

void buildSegtree(vector<ll> &arr,vector<ll> &segtree,ll start,ll end,ll treenode){
    if(start==end){
        segtree[treenode] = arr[start];
        return ;
    }
    ll mid = (start+end)/2;
    buildSegtree(arr,segtree,start,mid,2*treenode);
    buildSegtree(arr,segtree,mid+1,end,2*treenode+1);
    segtree[treenode] = max(segtree[2*treenode],segtree[2*treenode+1]);
}

ll query(vector<ll> &segtree,ll treenode,ll start,ll end,ll l,ll r){
    if(r<start||l>end){
        return 0;
    }
    if(start>=l&&end<=r){
        return segtree[treenode];
    }
    ll mid = (start+end)/2;
    ll left = query(segtree,2*treenode,start,mid,l,r);
    ll right = query(segtree,2*treenode+1,mid+1,end,l,r);
    return max(left,right);
}


ll getSumUtil(vector<ll> &lazy,vector<ll> &tree,ll start,ll end,ll qs,ll qe,ll treenode){ 
    if (lazy[treenode] != 0){ 
        tree[treenode] += (end-start+1)*lazy[treenode]; 
        if(start != end){ 
            lazy[treenode*2] += lazy[treenode]; 
            lazy[treenode*2+1] += lazy[treenode]; 
        } 
        lazy[treenode] = 0; 
    } 
    if (start>end || start>qe || end<qs) 
        return 0; 
 
    if (start>=qs && end<=qe) 
        return tree[treenode]; 

    ll mid = (start + end)/2; 
    return getSumUtil(lazy,tree,start, mid, qs, qe, 2*treenode) + getSumUtil(lazy,tree,mid+1, end, qs, qe, 2*treenode+1); 
} 

void updateRangeUtil(vector<ll> &lazy,vector<ll> &tree,ll treenode,ll start,ll end,ll us,ll ue,ll diff){ 
    if (lazy[treenode] != 0){ 
        tree[treenode] += (end-start+1)*lazy[treenode]; 
        if (start != end){ 
            lazy[treenode*2] += lazy[treenode]; 
            lazy[treenode*2 + 1] += lazy[treenode]; 
        } 
        lazy[treenode] = 0; 
    } 
    if (start>end || start>ue || end<us) 
        return ; 

    if (start>=us && end<=ue){ 
        tree[treenode] += (end-start+1)*diff; 
        if (start != end){ 
            lazy[treenode*2]   += diff; 
            lazy[treenode*2 + 1]   += diff; 
        } 
        return; 
    } 
    ll mid = (start+end)/2; 
    updateRangeUtil(lazy,tree,treenode*2,start, mid, us, ue, diff); 
    updateRangeUtil(lazy,tree,treenode*2+1, mid+1, end, us, ue, diff); 
    tree[treenode] = tree[treenode*2] + tree[treenode*2+1]; 
} 



int main(){
    //fio;
    cinll(n);cinll(q);
    vector<ll> heights;
    for(ll i=0;i<n;i++){
        cinll(x);heights.pb(x);
    }
    vector<ll> taste;
    for(ll i=0;i<n;i++){
        cinll(x);taste.pb(x);
    }
    
    vector<ll> segtree(4*n);
    buildSegtree(heights,segtree,0,n-1,1);
    
    ///////////////////////////////////////////////////////////
    vector<ll> pref;
    set<ll> trackpref;
    pref.pb(taste[0]);
    vector<ll> indprev(n,-1);
    vector<ll> indfron(n,-1);
    stack< pair<ll,ll> > one;
    for(ll i=n-1;i>=0;i--){
        while(!one.empty()&&one.top().first<heights[i]){
            indprev[one.top().second] = i;
            one.pop();
        }
        one.push(mp(heights[i],i));
    }
    stack< pair<ll,ll> > one2;
    for(ll i=0;i<n;i++){
        while(!one2.empty()&&one2.top().first<=heights[i]){
            indfron[one2.top().second] = i;
            one2.pop();
        }
        one2.push(mp(heights[i],i));
    }
    for(ll end = 1;end<n;end++){
        if(indprev[end]==-1){
            pref.pb(taste[end]); 
        }else{
            pref.pb(pref[indprev[end]] + taste[end]);
        }
    }
  //////////////////////////////////////////////////////////  


    vector<ll> revheights;
    vector<ll> revtaste;
    for(ll i=n-1;i>=0;i--){
        revheights.pb(heights[i]);
        revtaste.pb(taste[i]);
    }
    vector<ll> suff;
    vector<ll> indprev2(n,-1);
    vector<ll> indfron2(n,-1);
    stack< pair<ll,ll> > two;
    for(ll i=n-1;i>=0;i--){
        while(!two.empty()&&two.top().first<revheights[i]){
            indprev2[two.top().second] = i;
            two.pop();
        }
        two.push(mp(revheights[i],i));
    }
    stack< pair<ll,ll> > two2;
    for(ll i=0;i<n;i++){
        while(!two2.empty()&&two2.top().first<=revheights[i]){
            indfron2[two2.top().second] = i;
            two2.pop();
        }
        two2.push(mp(revheights[i],i));
    }
    suff.pb(revtaste[0]);
    for(ll end = 1;end<n;end++){
        if(indprev2[end]==-1){
            suff.pb(revtaste[end]); 
        }else{
            suff.pb(suff[indprev2[end]] + revtaste[end]);
        }
    }
    ///////////////////////////////////////////////////////////
    vector<ll> segpref(4*n+1);
    vector<ll> lazypref(4*n,0);
    buildSegtree(pref,segpref,0,n-1,1);
    vector<ll> segsuff(4*n+1);
    vector<ll> lazysuff(4*n,0);
    buildSegtree(suff,segsuff,0,n-1,1);
    
    while(q--){
        cinll(type);
        if(type==1){
            cinll(idx);cinll(val);
            ll add = val - taste[idx-1];
            //inprefarray
            //range idx-1 to indfron[idx-1]
            taste[idx-1] = val;
            ll startprev = idx-1;
            ll endprev = indfron[idx-1]-1;
            if(endprev<0) endprev = n-1;
            // for(ll i=startprev;i<=endprev;i++){
            //     pref[i] += add;
            // }
            updateRangeUtil(lazypref,segpref,1,0,n-1,startprev,endprev,add);
            //cout<<idx<<" "<<indfron[idx-1]<<" "<<add<<"\n";
            //in suffixarry
            //range n-idx to indfron[n-idx]
            revtaste[n-idx] = val;
            ll startprev2 = n-idx;
            ll endprev2 = indfron2[n-idx]-1;
            if(endprev2<0) endprev2 = n-1;
            // for(ll i=startprev2;i<=endprev2;i++){
            //     suff[i] += add;
            // }
            updateRangeUtil(lazysuff,segsuff,1,0,n-1,startprev2,endprev2,add);
        }else{
            cinll(start);cinll(end);
            ll height;
            bool ispossible = true;
            if(start<end){
                height = query(segtree,1,0,n-1,start,end-1);
                if(height>=heights[start-1]){
                    ispossible = false;
                }
            }else{
                height = query(segtree,1,0,n-1,end-1,start-2);
                if(height>=heights[start-1]){
                    ispossible = false;
                }
            }
            if(ispossible){
                if(end>start){
                    cout<<getSumUtil(lazypref,segpref,0,n-1,end-1,end-1,1) - 
                    getSumUtil(lazypref,segpref,0,n-1,start-1,start-1,1)  + taste[start-1]<<"\n";
                    //cout<<pref[end-1]-pref[start-1]+taste[start-1]<<"\n";
                }else{
                    cout<<getSumUtil(lazysuff,segsuff,0,n-1,n-end,n-end,1) - 
                    getSumUtil(lazysuff,segsuff,0,n-1,n-start,n-start,1) + revtaste[n-start]<<"\n";
                    //cout<<suff[n-end]-suff[n-start]+revtaste[n-start]<<"\n";
                }
            }else{
                cout<<-1<<"\n";
            }
        }
    }
    
    return 0;
}
/*
9 4
8 6 7 4 2 4 3 7 10
8 6 7 4 2 4 3 7 10
1 5 7
2 5 8
2 4 8
2 9 1

*/