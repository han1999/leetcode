//2022.07.27 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle=="") return 0;
        // return haystack.find(needle);
        int len=needle.size();
        for (int i=0; i+len-1<haystack.size(); i++){
            if (haystack.substr(i, len)==needle) return i;
        }
        return -1;
    }
};
