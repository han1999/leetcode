//#include <cctype>
//#include <climits>
//using namespace std;
//class Solution {
//public:
//    int myAtoi(string s) {
//        //notice: index<size!!!!!!!!!!!!!!!!!!
//        int index=0;
//        int size=s.size();
//        while (index<size && s[index]==' '){
//            //Do not perform actions (which should be done in code block) in a judgement!!!!!!!!!!!
//            index++;
//        }
//        bool isPos=1;
//        if (index<size && s[index]=='-'){
//            isPos=0;
//            index++;
//        }else if (index<size && s[index]=='+'){
//            index++;
//        }
//        int ans=0;
//        int lastINT_MAX=INT_MAX%10;
//        int lastINT_MIN=-(INT_MIN%10);
//        while (index<size && isdigit(s[index])){
//            //first: transfer char to int!!!!!!!!!!!!!
//            int num=s[index++]-'0';
//            if (ans>INT_MAX/10 || (ans==INT_MAX/10 && num>lastINT_MAX)) return INT_MAX;
//            if (ans<INT_MIN/10 || (ans==INT_MIN/10 && num>lastINT_MIN)) return INT_MIN;
//            //notice: s is a string, s[index] is a char, s[index]-'0' is a int!!!!!!!!!!!!!!!!!!!!
//            if (isPos) ans=ans*10+num;
//            else ans=ans*10-num;
//            //this judgement must be written in the end!!! not the beginning!!!!!!!!!!
//            // if (ans>INT_MAX) return INT_MAX;
//            // if (ans<INT_MIN) return INT_MIN;
//        }
//        return ans;
//    }
//};

//2022.07.21
class Solution {
public:
    int myAtoi(string s) {
        while (!s.empty() && s[0]==' '){
            s.erase(s.begin());
        }
        if (s.empty()) return 0;
        bool isNeg=0;
        if (s[0]=='-'){
            isNeg=1;
            s.erase(s.begin());
        }else if (s[0]=='+'){
            isNeg=0;
            s.erase(s.begin());
        }/*else if (!isdigit(s[0])){
            return 0;
        }*/
        long long ans=0L;
        while (isdigit(s[0])){
            if (isNeg){
            	/**
            	×Ö·û->Êý×Ö×ª»»Òª-'0'£¡£¡£¡£¡ 
                ans=ans*10-(s[0]-'0');
                if (ans<=INT_MIN) return INT_MIN;
            }else {
                ans=ans*10+(s[0]-'0');
                if (ans>=INT_MAX) return INT_MAX;
            }
            s.erase(s.begin());
        }
        return ans;
    }
};
