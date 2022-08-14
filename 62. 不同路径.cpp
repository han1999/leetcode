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
        ���������Կ����������ѧ��д����Ϊ1����Ϊ0���������C(m+n=2, m-1);
        */
        // //solution1: ��ʱ�ˣ����У�����˼·���
        // if (m==1 || n==1) return 1;
        // return uniquePaths(m-1,n)+uniquePaths(m, n-1);

        // //solution2: ��long long �����У�������Χ�� ��double Ҳ���У���ʧ������̫���˽�����1
        // return fac(m+n-2)/fac(m-1)/fac(n-1);

        //solution2.1 ������long longҲ���У�ֻ����double���У��������ⲻ�������
        // return C(m+n-2, min(m-1, n-1));

        // //solution3: ���ǵ�C�ķ�ĸ������ʵ���Ӹ�������ͬ�ģ����Դ����ټ��㷶Χ
        // long long ans=1;
        // for (int i=0; i<n-1; i++){
        //     /*
        //     ˳�����Ҫ���������Ͳ�����
        //     һ����m��ʼ�� һ����1��ʼ, �������ϼ�, ��������
        //     ���һ����m+n-2��ʼ�� һ����n-1��ʼ�����¼�����ô��������
        //     */
        //     int up=m+i;
        //     int down=1+i;
        //     ans=ans*up/down;
        // }
        // return ans;

        //solution4: ������ǣ���dp�� ������ʽ���ݹ���ʽ����
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
