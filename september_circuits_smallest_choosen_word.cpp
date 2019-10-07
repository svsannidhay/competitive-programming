//problem statement:- https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/smallest-chosen-word-0108fd21/
// medium one
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std; 
bool compare(string a, string b) 
{ 
    return (a+b < b+a); 
}

string lexSmallest(string a[], int n) 
{ 
    sort(a, a+n, compare); 
    string answer = ""; 
    for (int i = 0; i < n; i++) 
        answer += a[i]; 
  
    return answer; 
}

string getSmallest(string s, int k) 
    { 
        string currStr = s.substr(0, k); 
        string lexMin = currStr; 
        string lexMax = currStr; 
        for (int i = k; i < s.length(); i++)  
        { 
            currStr = currStr.substr(1, k) + s[i]; 
            if (lexMin >currStr) 
                lexMin = currStr;      
        } 
        return lexMin ; 

    } 

string subsequence(string s, int binary, int len) 
{ 
    string sub = ""; 
    for (int j = 0; j < len; j++) 
  
        // check if jth bit in binary is 1 
        if (binary & (1 << j)) 
  
            // if jth bit is 1, include it 
            // in subsequence 
            sub += s[j]; 
  
    return sub; 
} 
      
    
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    string str1,str2,str3;
    cin>>str1>>str2>>str3;
    //sort(str2.begin(), str2.end()); 
    //auto res = unique(str2.begin(), str2.end());
    //str2.erase(res, str2.end());
    string stringop;
    stringop.append(str1);
    stringop.append(str3);
    int n = str2.length();
    string substring;
    /*
    if(n<10){
        
        //vector<string> sorted_subsequence; 
        int len = str2.size();
        //long long int limit = 100000;
        unsigned long long int limit = pow(2, len); 
        for (int i = 1; i <= limit - 1; i++) {  
            string sub = subsequence(str2, i, len); 
                //cout<<sub<<"\n";
                string s;
                s.append(str1);
                s.append(sub);
                s.append(str3);
                if( lexicographical_compare(s.begin(), s.end(), stringop.begin(), stringop.end()))
                {
                    stringop = s;
                }
                else{
                    stringop = stringop;
                }
            }    
            
    } 
    
   else{*/
        string test = str2;
        sort(test.begin(),test.end());
        auto res = unique(test.begin(), test.end());
        test.erase(res, test.end());
        int currindex =0;
        for(int i=0;i<test.length();i++){
            char check = test[i];
            
            for(int j=currindex;j<str2.length();j++){
                if(str2[j]==check){
                    substring += check;
                    currindex = j;
                    
                }
                
            }
            
        }

  // }
    
    string s;   
    s.append(str1);
    s.append(str2);
    s.append(str3);
    if( lexicographical_compare(s.begin(), s.end(), stringop.begin(), stringop.end()))
            {
                stringop = s;
            }
            else{
                stringop = stringop;
            }
          
       
    string strtest = str2;
    sort(strtest.begin(),strtest.end());
    auto it1 = lower_bound(strtest.begin(),strtest.end(),'a');
    auto it2 = upper_bound(strtest.begin(),strtest.end(),'a');
    int limita = it2 - it1;
    
        
    string ss;
    ss.append(str1);
    for(int i=0;i<limita;i++){
        char put = 'a';
        ss += put;
    }
    ss.append(str3);
    if( lexicographical_compare(ss.begin(), ss.end(), stringop.begin(), stringop.end()))
            {
                stringop = ss;
            }
            else{
                stringop = stringop;
            }
           
    string final ;
    final.append(str1);
    for(int i=0;i<substring.length();i++){
        
        if(substring[i]==str3[0]||substring[i]>str3[0]){
            break;
        }
        else{
            char a = substring[i];
            final += a;
        }
        
    }
    //final.append(substring);
    final.append(str3);
    if( lexicographical_compare(final.begin(), final.end(), stringop.begin(), stringop.end()))
            {
                stringop = final;
            }
            else{
                stringop = stringop;
            }
    cout<<stringop;
    
}
