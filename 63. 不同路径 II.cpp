class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //solution1:
    //     if (obstacleGrid[0][0]==1) return 0;
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     for (int i=0; i<m; i++){
    //         if (obstacleGrid[i][0]==1){
    //             /*
    //             ��Ҫ��while�иı��жϱ�����ֵ������while(i++<m)
    //             ��ôi==m�ǣ� i++<m������������{}����i==m+1�ˣ� �Ѿ������
    //             */
    //             while (i<m) obstacleGrid[i++][0]=0;
    //         }else obstacleGrid[i][0]=1;
    //     }
    // //    for (auto vt:obstacleGrid){
    // //         for (auto num:vt){
    // //             cout<<num<<" ";
    // //         }
    // //         cout<<endl;
    // //     }        
    //     /*
    //     �����j��1�����������벻���������0�������ͻ��õ�һ��ȫ���0
    //     */
    //     for (int j=1; j<n; j++){
    //         if (obstacleGrid[0][j]==1){
    //             while (j<n) obstacleGrid[0][j++]=0;
    //         }else obstacleGrid[0][j]=1;
    //     }

    //     // for (auto vt:obstacleGrid){
    //     //     for (auto num:vt){
    //     //         cout<<num<<" ";
    //     //     }
    //     //     cout<<endl;
    //     // }
    //     for (int i=1; i<m; i++){
    //         for (int j=1; j<n; j++){
    //             if (obstacleGrid[i][j]==1){
    //                 obstacleGrid[i][j]=0;
    //                 continue;
    //             }
    //             obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
    //         }
    //     }
    //     // for (auto vt:obstacleGrid){
    //     //     for (auto num:vt){
    //     //         cout<<num<<" ";
    //     //     }
    //     //     cout<<endl;
    //     // }
    //     return obstacleGrid.back().back();

        //solution2:����ⷨ
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i=0; i<m && obstacleGrid[i][0]==0; i++){
            /*
            ͷ�Ժܲ������ˣ���dpд��obstacleGrid��
            */
            dp[i][0]=1;
        }
        for (int j=0; j<n && obstacleGrid[0][j]==0; j++){
            dp[0][j]=1;
        }
 
        /*
        �����ﱨ��һ����������Ϊ�������һ��}
        r 5: error: expected member name or ';' after declaration specifiers
        */
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (obstacleGrid[i][j]==0) {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        for (auto vt:dp){
            for (auto num:vt){
                cout<<num<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};
