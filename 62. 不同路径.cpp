class Solution {
public:
    // int getPath(int m, int n)
    double fac(long long a){
        double ans=1;
        while (a){
            ans*=a--;
        }
        return ans;
    }
    double  C(long long  a, long long  b){
        double ans=1;
        for (long long i=0; i<b; i++){
            ans*=(a-i);
        }
        while (b){
            ans/=b--;
        }
        return ans;
    }

    int uniquePaths(int m, int n) {
        /**
        这道题很明显可以用组合数学来写，右为1，下为0，结果就是C(m+n=2, m-1);
        */
        // //solution1: 超时了，不行，但是思路差不多
        // if (m==1 || n==1) return 1;
        // return uniquePaths(m-1,n)+uniquePaths(m, n-1);

        // //solution2: 用long long 都不行，超出范围了 用double 也不行，损失精度了太大了结果会差1
        // return fac(m+n-2)/fac(m-1)/fac(n-1);

        //solution2.1 这里用long long也不行，只有用double才行，精度问题不会出问题
        // return C(m+n-2, min(m-1, n-1));

        // //solution3: 考虑到C的分母分子其实因子个数是相同的，可以大大减少计算范围
        // long long ans=1;
        // for (int i=0; i<n-1; i++){
        //     /*
        //     顺序很重要，反过来就不行了
        //     一个从m开始， 一个从1开始, 慢慢往上加, 都能整除
        //     如果一个从m+n-2开始， 一个从n-1开始，往下减，那么不能整除
        //     */
        //     int up=m+i;
        //     int down=1+i;
        //     ans=ans*up/down;
        // }
        // return ans;

        //solution4: 杨辉三角，简单dp， 递推形式，递归形式更简单
        vector<vector<int>> dp(m+1, vector(n+1, 0));
        for (int i=1; i<=m; i++){
            dp[i][1]=1;
        }
        for (int i=1; i<=n; i++){
            dp[1][i]=1;
        }
        for (int i=2; i<=m; i++){
            for (int j=2; j<=n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];

    }
};
