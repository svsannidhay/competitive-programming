//memoized solution
class Solution {
public:
    int memo[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo,-1,sizeof(memo));
        return lcsmemo(text1,text2,text1.length()-1,text2.length()-1);
    }
    int lcsmemo(string & s1,string & s2,int i,int j){
        if(i<0||j<0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s1[i]==s2[j]){
            memo[i][j] = 1 + lcsmemo(s1,s2,i-1,j-1);
            return memo[i][j];
        }
        memo[i][j] = max(lcsmemo(s1,s2,i,j-1),lcsmemo(s1,s2,i-1,j));
        return memo[i][j];
    }
};
// dp solution 
class solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int dp[1005][1005];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=s1.length();i++) dp[i][0] = 0;
        for(int i=0;i<=s2.length();i++) dp[0][i] = 0;
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};