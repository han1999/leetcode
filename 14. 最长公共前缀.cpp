// 2022.07.22 21.09-21.21
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
        这样写肯定不会错，但是多一次循环
        */
        int minL=strs[0].size();
        string ans;
        for (auto &str:strs){
            if (str=="") return "";
            if (str.size()<minL) minL=str.size();
        }
        for (int i=0; i<minL; i++){
            char ch=strs[0][i];
            for (auto &str:strs){
                if (str[i]!=ch){
                    return ans;
                }
            }
            ans+=ch;
        }
        return ans;

        // // 好家伙，效率还不如第一次呢
        // string ans;
        // int index=0;
        // if (strs[0]=="") return "";
        // while (1){
        //     char ch=strs[0][index];
        //     for (auto &s:strs){
        //         if (index==s.size() || s[index]!=ch){
        //             return ans;
        //         }
        //     }
        //     ans+=ch;
        //     index++;
        // }
        // return "";
    }
};
