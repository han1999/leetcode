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
    //             不要在while中改变判断变量的值，例如while(i++<m)
    //             那么i==m是， i++<m成立，但是在{}里面i==m+1了， 已经溢出了
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
    //     这里的j从1出发，根本想不到，如果从0出发，就会让第一行全变成0
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

        //solution2:常规解法
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i=0; i<m && obstacleGrid[i][0]==0; i++){
            /*
            头脑很不清醒了，把dp写成obstacleGrid了
            */
            dp[i][0]=1;
        }
        for (int j=0; j<n && obstacleGrid[0][j]==0; j++){
            dp[0][j]=1;
        }
 
        /*
        在这里报了一个错，这是因为，多加了一个}
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
