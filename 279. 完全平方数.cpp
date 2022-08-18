class Solution {
public:
    int numSquares(int n) {
        /*
        ���·���������
        */
        // vector<int> square(101);
        // for (int i=0; i<square.size(); i++){
        //     square[i]=i*i;
        // }
        // int cnt=0;
        // int pos=100;
        // while (n){
        //     cout<<n<<"    ";
        //     if (n-square[pos]>=0) {
        //         n-=square[pos];
        //         cnt++;
        //     }else {
        //         pos--;
        //     }
        // }
        // return cnt;

        //���ټ��Ķ�̬�滮��
        vector<int> dp(n+1);
        for (int i=1; i<=n; i++){
            int minPre=INT_MAX;
            for (int j=1; j*j<=i; j++){
                minPre=min(minPre, dp[i-j*j]);
            }
            dp[i]=minPre+1;
        }
        return dp[n];
    }
};
