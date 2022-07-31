//2022.07.26
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        // trackback(0, 0, temp, ans, n);
        trackback(temp, ans, n);
        return ans;
    }
    
    //solution1�� 
    // void trackback(int lCnt, int rCnt, string &temp, vector<string> &ans, int n){
    //     if (temp.size()==2*n){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     if (lCnt<n){
    //         temp.push_back('(');
    //         trackback(lCnt+1, rCnt, temp, ans, n);
    //         temp.pop_back();
    //     }
    //     if (rCnt<lCnt){
    //         temp.push_back(')');
    //         trackback(lCnt, rCnt+1, temp, ans, n);
    //         temp.pop_back();
    //     }
    // }
    /**
    solution2��
    Ӳö��
    */
    bool valid(string temp){
        /** 
        lCnt��rCnt������balance���棬���������һ��
        */
        int lCnt=0, rCnt=0;
        for (auto const &ch:temp){
            if (ch=='('){
                lCnt++;
            }else {
                rCnt++;
            }
            if (rCnt>lCnt){
                return false;
            }
        }
        return lCnt==rCnt;
    }
    void trackback(string &temp, vector<string> &ans, int n){
        if (temp.size()==2*n){
            if (valid(temp)) ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        trackback(temp, ans, n);
        temp.pop_back();

        temp.push_back(')');
        trackback(temp, ans, n);
        temp.pop_back();
    }
};
