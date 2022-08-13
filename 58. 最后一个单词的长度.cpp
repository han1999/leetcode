class Solution {
public:
    int lengthOfLastWord(string s) {
        //很简单的一道题写了很久，逻辑其实很难判断
        //solution1:
        // int ans=0;
        // int lastAns=0;
        // for (int i=0; i<s.size(); i++){
        //     if (s[i]==' '){
        //         ans=lastAns==0?ans:lastAns;
        //         lastAns=0;
        //     }else {
        //         lastAns++;
        //     }
        // }
        // return lastAns?lastAns:ans;

        // //solution2: 这种方法明星啊更好点，一开始咋没想到呢
        // //遇到特例的时候，我们可以先对特进行处理
        // int ans=0;
        // while (!s.empty() && s.back()==' '){
            /*
            string和vector是唯二的可以对迭代器进行加减操作的容易
            */
        //     s.erase(s.end()-1);
        // }
        // for (const auto &ch:s){
        //     if (ch==' '){
        //         ans=0;
        //     }else {
        //         ans++;
        //     }
        // }
        // return ans;

        //solution3:
        int ans=0;
        int i=s.size()-1;
        while (i>=0 && s[i]==' '){
            i--;
        }
        while (i>=0 && s[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};
