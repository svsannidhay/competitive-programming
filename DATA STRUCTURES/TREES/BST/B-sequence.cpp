problem statement:- https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/b-sequence-f919fc86/
/*
BST approach 
*/
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
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define MAX INT_MAX;
#define MIN INT_MIN;
#define MOD 1000000007;
 
using namespace std;
 
struct node{
	ll data;
	node *left,*right;
};
node *get(ll data){
	node *tmp = new node;
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
 
node * insert(node * n,ll data){
	if(n==NULL){
		return get(data); 
	}else{
		if(data <= n->data){
			n->left = insert(n->left,data);
		}else{
			n->right = insert(n->right,data);
		}
	}
	return n;
}
 
void inorder(node *root,vector<ll> &vec){
	if(root==NULL){
		return;
	}else{
		inorder(root->left,vec);
		vec.pb(root->data);
		inorder(root->right,vec); 
	}
}
 
void findNode(node *root,ll val,bool & present){
	if(root!=NULL){
		if(root->data == val){
			present = true;
			//cout<<"";
		}
		else{
			if(val<=root->data){
				findNode(root->left,val,present);
			}else{
				findNode(root->right,val,present);
			}
		}
	}
 
}
 
int main(){
	fio;
	cinll(n);
	vector<ll> arr;
	ll max_element = INT_MIN;
	for(ll i=0;i<n;i++){
		cinll(x);arr.pb(x);
		if(x>max_element){max_element = x;}
	}
	vector<ll> inc;
	vector<ll> dec;
	inc.pb(arr[0]);
	ll size = arr.size();
	for(ll i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			inc.pb(arr[i]);
		}else{
			dec.pb(arr[i]);
		}
	}
	node *rootinc = NULL;node *rootdec = NULL;
	if(inc.size()>=1){
		rootinc = insert(rootinc,inc[0]);
		for(ll i=1;i<inc.size();i++){
			insert(rootinc,inc[i]);
		}
	}
	if(dec.size()>=1){
		rootdec = insert(rootdec,dec[0]);
		for(ll i=1;i<dec.size();i++){
			insert(rootdec,dec[i]);
		}
	}
	//Debug
	/*
	inorder(rootinc);
	cout<<"\n";
	inorder(rootdec);
	*/
	cinll(q);
	for(ll i=0;i<q;i++){
		cinll(val);
		if(val == max_element){
			cout<<size<<"\n";
		}else{
			bool presentinc=false,presentdec=false;
			//cout<<val<<" "<<presentinc<<" "<<presentdec<<" ";
			findNode(rootinc,val,presentinc);
			findNode(rootdec,val,presentdec);
			if(presentdec&&presentinc){
				
			}
			else if(presentinc&&presentdec==false){
				size++;
				if(val>max_element){
					max_element = val;
				}
				insert(rootdec,val);
			}
			else if(presentinc==false&&presentdec==false){
				size++;
				insert(rootinc,val);
				if(val>max_element){
					max_element = val;
				}
			}
			cout<<size<<"\n";
		}	
 
	}
	inc.clear();
	dec.clear();
	inorder(rootinc,inc);
	inorder(rootdec,dec);
	for(ll i=0;i<inc.size();i++){
		cout<<inc[i]<<" ";
	}
	for(ll i=dec.size()-1;i>=0;i--){
		cout<<dec[i]<<" ";
	}
	return 0;
}


/*
AC solution using sets 
Easy implementation
*/
/*
	Algorithm Used :-
        You can't use array to map the no of exisistances of a number in. increasing 
        and decreasing parts.Here you will get MLE as Ai can go upto 10^9
        Next approach 
        You can use sets here which are default sorted so what we can do here is 
        perform find method if the element isn't present in both increasing and
        decreasing sets then insert it to increasing set 
        If it is present in the increasing set and isn't present in decreasing part 
        then insert it to decreasing part 
        In this way you can build sets Complexity : O(qlogn + n) worst case
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
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin>>x;
#define cini(x) int x;cin>>x;
#define cout(x) cout<<x;
#define vect(x) vector<ll> x;
#define vect1(x) vector<ll> x;x.push_back(0);
#define vectdef(x,size,val) vector<ll> x;for(ll i=0;i<size;i++){x.push_back(val);}
#define vectdef1(x,size,val) vector<ll> x;for(ll i=0;i<=size;i++){x.push_back(val);}
#define pb(x) push_back(x);
#define MAX INT_MAX;
#define MIN INT_MIN;
#define MOD 1000000007;
 
using namespace std;
 
int main(){
	fio;
	cinll(n);
	vector<ll> arr;
	ll max_element = INT_MIN;
	for(ll i=0;i<n;i++){
		cinll(x);arr.pb(x);
		if(x>max_element){max_element = x;}
	}
	set<ll> inc;
	vector<ll> sieveinc;
	vector<ll> sievedec;
	set<ll> dec;
	inc.insert(arr[0]);
	for(ll i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
		    inc.insert(arr[i]);
		}else{
			dec.insert(arr[i]);
		}
	}
	ll size = arr.size();
	cinll(q);
	for(ll i=0;i<q;i++){
		cinll(val);
		if(val==max_element){
			cout<<size<<"\n";
		}else{
			if(inc.find(val)==inc.end()&&dec.find(val)==dec.end()){
				inc.insert(val);
				if(val>max_element){
					max_element = val;
				}
				size++;
			}
			else if(inc.find(val)!=inc.end()&&dec.find(val)==dec.end()){
				dec.insert(val);
 
				if(val>max_element){
					max_element = val;
				}
				size++;
			}
			cout<<size<<"\n";
		}
	}
    set<ll>::iterator it;
    set<ll>::reverse_iterator itr;
    for(it=inc.begin();it!=inc.end();it++){
        cout<<*it<<" ";
    }
    for(itr=dec.rbegin();itr!=dec.rend();itr++){
        cout<<*itr<<" "; 
    }
	return 0;
}
