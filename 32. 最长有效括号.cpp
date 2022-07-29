class Solution {
public:
    int longestValidParentheses(string s) {
        // //solution1:
        // int ans=0;
        // stack<int> stk;
        // stk.push(-1);
        // //栈底的)下标代表，最后一个没有匹配的),其他下标减去它（如果只剩下他的时候），就是有效长度,一开始默认从-1开始(理解为-1位置为)）
        // for (int i=0; i<s.size(); i++){
        //     if (s[i]=='('){
        //         stk.push(i);
        //     }else{
        //         /*
        //         很不熟练
        //         */
        //         stk.pop();
        //         if (stk.empty()){
        //             stk.push(i);
        //         }else {
        //             ans=max(ans, i-stk.top());
        //         }
        //     }
        // }
        // return ans;


        /**
        一个括号串有效:
        1. 从起点开始的连续子串都满足 (数量 大于 )数量 （可以用抵消法，来算是否合法）
        2. 到终点结束的时候，左右括号数量相同
        */
        if (s=="") return 0;
        // 分开计算方式：
        auto getValid=[&](string s){
            int ans=0;
            int lCnt=0, rCnt=0;
            for (const auto &ch:s){
                if (ch=='('){
                    lCnt++;
                }else {
                    rCnt++;
                    if (rCnt==lCnt){
                        ans=max(ans, lCnt*2);
                    }else if (rCnt>lCnt){
                        lCnt=rCnt=0;
                    }
                }
            }
            return ans;
        };

        // //抵消法: 这题不能用抵消法，因为要记录cnt的数量
        // auto getValid=[&](string s){
        //     int validSize=0;
        //     int balance=0;
        //     for (const auto &ch:s){
        //         if (ch=='('){
        //             balance++;
        //         }else {
        //             balance--;
        //             if (balance==0){
        //                 validSize=max(validSize, 2)
        //             }
        //         }
        //     }
            
        // }


        int ans=getValid(s);
        reverse(s.begin(), s.end());
        for (auto &ch:s){
            if (ch=='(') ch=')';
            else ch='(';
        }
        ans=max(ans, getValid(s));
        return ans;
    }
};
