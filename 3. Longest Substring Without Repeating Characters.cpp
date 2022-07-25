//class Solution {
//public:
//    // //oh my god, boolean is not cpp's key word!
//    // bool notRepeating(string s){
//    //     int hashTable[255]={0};
//    //     for (auto ch:s){
//    //         if (hashTable[ch]) return false;
//    //         hashTable[ch]++;
//    //     }
//    //     return true;
//    // }
//    int lengthOfLongestSubstring(string s) {
//        // int len=s.size();
//        // while (len>0){
//        //     for (int i=0; i<s.size()-len+1; i++){
//        //         string sub=s.substr(i, len);
//        //         if (notRepeating(sub)) return len;
//        //     }
//        //     len--;//I find I always forget to change the value of conditional variable
//        // }
//        // return 0;
//        // //solution1:
//        // int maxLen=0;
//        // int left=0, right=0;
//        // int size=s.size();
//        // for (left=0; left<size; left++){
//        //     while (right<size && notRepeating(s.substr(left, right-left+1))){
//        //         right++;
//        //     }
//        //     int len=right-left;
//        //     if (len>maxLen){
//        //         maxLen=len;
//        //     }
//        // }
//        // return maxLen;
//
//        //solution2:
//        int l=0, r=0, maxLen=0;
//        int size=s.size();
//        set<char> st;
//        for (l=0; l<size; l++){
//            if (l) st.erase(s[l-1]);
//            while (r<size){
//                if (st.find(s[r])!=st.end()) break;
//                st.insert(s[r++]);
//            }
//            int len=r-l;
//            if (len>maxLen) maxLen=len;
//        }
//        return maxLen;
//    }
//};
//
//
//
//
//// 2022.07.20：这个时间和空间复杂度，比上面的solution1要好 
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int maxL=0;
//        for (int i=0; i<s.size(); i++){
//            int len=maxL+1;
//            if (i+len-1>=s.size()) break;
//            while (i+len-1<s.size()){
//                string sub=s.substr(i, len);
//                if (!noDuplicated(sub)) break;
//                len++;
//                maxL++;
//            }
//        }
//        return maxL;
//    }
//    bool noDuplicated(string s){
//        unordered_set<char> st;
//        for (auto c:s){
//            auto it=st.find(c);
//            if (it==st.end()) st.insert(c);
//            else return false;
//        }
//        return true;
//    }
//}; 

/**
测试
*/ 
#include <string>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0, r=0, maxL=1;
        st.insert(s[0]);
        for (l=0; l<s.size(); l++){
            if (l) st.erase(s[l-1]);
            while (r+1<s.size() && st.count(s[r+1])==0){
                st.insert(s[++r]);
            }
            maxL=max(maxL, r-l+1);
            
            printf("%d %d %d\n", l, r, maxL);
        }
        return maxL;
    }
};

int main(){
	Solution solution;
	string s="pwwkew";
	solution.lengthOfLongestSubstring(s);
} 



/*
考虑可能出现空串的问题
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s=="") return 0;
        int l=0,r=0,maxL=1;
        unordered_set<char> st;
        st.insert(s[0]);
        for (l=0; l<s.size(); l++){
            if (l) st.erase(s[l-1]);
            while (r+1<s.size() && !st.count(s[r+1])){
                st.insert(s[++r]);
            }
            maxL=max(maxL, r-l+1);
        }
        return maxL;
    }
}; 

/**
左闭右开类型
*/ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if (s=="") return 0;
        int l=0,r=0,maxL=0;
        unordered_set<char> st;
        // st.insert(s[0]);
        for (l=0; l<s.size(); l++){
            if (l) st.erase(s[l-1]);
            while (r<s.size() && !st.count(s[r])){
                st.insert(s[r++]);
            }
            maxL=max(maxL, r-l);
        }
        return maxL;
    }
};
