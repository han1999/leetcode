class Solution {
public:
    string replaceSpace(string s) {
        int pos=s.find(' ');
        string s2="%20";
        while (pos!=s.npos){
            s.replace(pos, 1, s2);
            pos=s.find(' ');
        }
        return s;
    }
};

