//class Solution {
//public:
//    bool isPalindrome(int x) {
//        string s=to_string(x);
//        int size=s.size();
//
//        //i<size/2 is ok, not need <=
//        for (int i=0; i<size/2; i++){
//            if (s[i]!=s[size-1-i]) return false;
//        }
//        return true;
//    }
//};

//2022.07.21
//solution1: 尝试用递归写法 
class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome(to_string(x));
    }
    
    bool isPalindrome(string s){
        if (s.size()==1) return true;
        if (s.size()==2){
            if (s[0]==s[1]) return true;
            return false;
        }
        return isPalindrome(s.substr(1, s.size()-2)) && s[0]==s[s.size()-1];
    }
};


//solution2: 题解做法，有点巧妙：
class Solution {
public:
    bool isPalindrome(int x) {
        /**
        题解的方法太巧妙
        */
        if (x<0) return false;
        if (x==0) return true;
        if (x%10==0) return false;
        int rev=0;
        while (x>rev){
            int num=x%10;
            rev=rev*10+num;
            x/=10;
        }
        return x==rev || x==rev/10;
    }
}; 

 
