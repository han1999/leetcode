class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
        头脑很不清楚了，总是出小问题 这次出的小问题，是初始化第一行第一列的时候，i,j从0开始，i-1,j-1溢出了
        但是这次答案，除了变量命名不一样以外，更标准答案，一模一样
        */
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0]=grid[0][0];
        for (int i=1; i<m; i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for (int j=1; j<n; j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
