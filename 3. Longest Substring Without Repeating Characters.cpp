class Solution {
public:
    // //oh my god, boolean is not cpp's key word!
    // bool notRepeating(string s){
    //     int hashTable[255]={0};
    //     for (auto ch:s){
    //         if (hashTable[ch]) return false;
    //         hashTable[ch]++;
    //     }
    //     return true;
    // }
    int lengthOfLongestSubstring(string s) {
        // int len=s.size();
        // while (len>0){
        //     for (int i=0; i<s.size()-len+1; i++){
        //         string sub=s.substr(i, len);
        //         if (notRepeating(sub)) return len;
        //     }
        //     len--;//I find I always forget to change the value of conditional variable
        // }
        // return 0;
        // //solution1:
        // int maxLen=0;
        // int left=0, right=0;
        // int size=s.size();
        // for (left=0; left<size; left++){
        //     while (right<size && notRepeating(s.substr(left, right-left+1))){
        //         right++;
        //     }
        //     int len=right-left;
        //     if (len>maxLen){
        //         maxLen=len;
        //     }
        // }
        // return maxLen;

        //solution2:
        int l=0, r=0, maxLen=0;
        int size=s.size();
        set<char> st;
        for (l=0; l<size; l++){
            if (l) st.erase(s[l-1]);
            while (r<size){
                if (st.find(s[r])!=st.end()) break;
                st.insert(s[r++]);
            }
            int len=r-l;
            if (len>maxLen) maxLen=len;
        }
        return maxLen;
    }
};
