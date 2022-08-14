class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for (int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        //可以用滚动数组优化，但是没有必要
        return dp[n];
    }
};
