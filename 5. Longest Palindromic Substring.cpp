class Solution {
public:
    bool isPalindrome(string &s){
        int size=s.size();
        for (int i=0; i<=size/2; i++){
            if (s[i]!=s[size-1-i]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // string ans="";
        // int size=s.size();
        // for (int i=0; i<size; i++){
        //     for (int j=size-1; j>=i; j--){
        //         int len=j-i+1;
        //         if (len<=ans.size()) break;
        //         string sub=s.substr(i, len);
        //         if (isPalindrome(sub)){
        //             ans=sub;
        //         }
        //     }
        // }
        // return ans;

        int size=s.size();
        // int dp[size+10][size+10]={0};
        vector<vector<int>> dp(size, vector<int>(size, 0));
        int maxLen=1, beginIndex=0;
        for (int i=0; i<size; i++){
            dp[i][i]=1;
            if (i!=size-1 && s[i]==s[i+1]){
                dp[i][i+1]=1;
                beginIndex=i;
                maxLen=2;
            }
        }
        for (int len=3; len<=size; len++){
            for (int i=0; i+len-1<size; i++){
                int j=i+len-1;
                if (s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    maxLen=len;
                    beginIndex=i;
                }
                // dp[i][j]=(s[i]==s[j] && d[i+1][j-1]);
            }
        }
        return s.substr(beginIndex, maxLen);
    }
};
