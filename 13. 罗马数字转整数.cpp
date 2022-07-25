//2022.07.22
class Solution {
public:
    int romanToInt(string s) {
        
        // const pair<string, int> symbol2Value[]={
        //     {"M", 1000},
        //     {"CM", 900},
        //     {"D", 500},
        //     {"CD", 400},
        //     {"C",100},
        //     {"XC", 90},
        //     {"L", 50},
        //     {"XL", 40},
        //     {"X", 10},
        //     {"IX", 9},
        //     {"V", 5},
        //     {"IV",4},
        //     {"I",1},
        // };
        // int ans=0;
        // for (const auto &[symbol, value]:symbol2Value){
        //     while (!s.empty() && s.find(symbol)==0){
        //         ans+=value;
        //         s.erase(0, symbol.size());
        //     }
            
        // }
        // return ans;

        //solution2:
        // 这方法时空效率还没我的好呢
        unordered_map<char, int> mp={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans=0;
        for (int i=0; i<s.size(); i++){
            int value=mp[s[i]];
            if (i<s.size()-1){
               if (value<mp[s[i+1]]){
                   ans-=value;
               }else {
                   ans+=value;
               }
            }else {
                ans+=value;
            }
        }
        return ans;
    }
};
