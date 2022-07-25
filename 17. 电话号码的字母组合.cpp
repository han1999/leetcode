// 2022.07.23 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits=="") return {};
        vector<string> ans;
        string num2str[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //其实string跟vector很相近
        string s;
        backtrack(0, ans, s, digits, num2str);
        return ans;
    }

    void backtrack(int index, vector<string> &ans, string &s, string &digits, string num2str[]){
        if (index==digits.size()){
            ans.push_back(s);
            return;
        }
        string str=num2str[digits[index]-'0'];
        for (auto ch:str){
            s+=ch;
            backtrack(index+1, ans, s, digits, num2str);
            s.pop_back();
        }
    }
};

