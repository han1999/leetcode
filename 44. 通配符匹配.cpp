class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        dp[0][0]=1;
        for (int i=1; i<=p.size(); i++){
            if (p[i-1]!='*') break;
            dp[0][i]=1;
        }
        /**
        就算知道思路，但是关于下标的问题，还是非常容易出错
        */
        for (int i=1; i<=s.size(); i++){
            for (int j=1; j<=p.size(); j++){
                if (islower(p[j-1])){
                    dp[i][j]= s[i-1]==p[j-1] && dp[i-1][j-1];
                }else if (p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else {
                    /**
                    *则两种情况： i不需要和j匹配，*代表空
                    i需要和j匹配，匹配完以后，i-1可以和j匹配，*可以匹配i前面的所有字符
                    匹配前面所有字符有两种情况，第一种匹配到了，第二种，没匹配到，所以一直匹配到dp[0][j]
                    */
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
