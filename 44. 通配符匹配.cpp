class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        dp[0][0]=1;
        for (int i=1; i<=p.size(); i++){
            if (p[i-1]!='*') break;
            dp[0][i]=1;
        }
        /**
        ����֪��˼·�����ǹ����±�����⣬���Ƿǳ����׳���
        */
        for (int i=1; i<=s.size(); i++){
            for (int j=1; j<=p.size(); j++){
                if (islower(p[j-1])){
                    dp[i][j]= s[i-1]==p[j-1] && dp[i-1][j-1];
                }else if (p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else {
                    /**
                    *����������� i����Ҫ��jƥ�䣬*�����
                    i��Ҫ��jƥ�䣬ƥ�����Ժ�i-1���Ժ�jƥ�䣬*����ƥ��iǰ��������ַ�
                    ƥ��ǰ�������ַ��������������һ��ƥ�䵽�ˣ��ڶ��֣�ûƥ�䵽������һֱƥ�䵽dp[0][j]
                    */
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
