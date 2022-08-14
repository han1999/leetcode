class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
        ͷ�Ժܲ�����ˣ����ǳ�С���� ��γ���С���⣬�ǳ�ʼ����һ�е�һ�е�ʱ��i,j��0��ʼ��i-1,j-1�����
        ������δ𰸣����˱���������һ�����⣬����׼�𰸣�һģһ��
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
