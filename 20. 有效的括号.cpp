// 2022.07.26 很简单的一道题 
class Solution {
public:
    bool isValid(string s) {
        /**
        对stack其实不熟悉，用vector能完成一模一样的动作
        */
        unordered_map<char, char> mp={
            {')', '('},
            {']','['},
            /**
            这里最后一个元素，就算后面加了一个逗号，也能编译通过
            */
            {'}','{'},
        };
        stack<char> stk;
        /**
        因为这道题实在太经典了，所以写法更官方解答也都一模一样
        */
        for (auto const &ch:s){
            //这个if可以用mp.count()代替
            if (ch==')' || ch==']' || ch=='}'){
                if (stk.empty() || stk.top()!=mp[ch]) return false;
                stk.pop();
            }else {
                stk.push(ch);
            }
        }
        //等价于 return stk.empty()
        if (stk.empty()) return true;
        return false; 
    }
};
