class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int size=s.size();

        //i<size/2 is ok, not need <=
        for (int i=0; i<size/2; i++){
            if (s[i]!=s[size-1-i]) return false;
        }
        return true;
    }
};
