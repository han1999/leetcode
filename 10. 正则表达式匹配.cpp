//2022.07.22 
class Solution {
public:
    bool isMatch(string s, string p) {
        /*
        ��������ܱ�����������д������
        �����˼·֪�������Ǻܶ�ϸ���벻�������ܵ��Ե��ò���ʱ��
        */
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1));
        dp[0][0]=1;
        auto matches=[&](int i, int j){
            if (i==0) return false;
            if (p[j-1]=='.') return true;
            return s[i-1]==p[j-1];
        };

        for (int i=0; i<=s.size(); i++){
            for (int j=1; j<=p.size(); j++){
                if (p[j-1]=='*'){
                    if (matches(i,j-1)){
                        dp[i][j]= dp[i-1][j] || dp[i][j-2];
                    }else {
                        //����j>=2
                        dp[i][j]=dp[i][j-2];
                    }
                }else {
                    if (matches(i,j)){
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
};
