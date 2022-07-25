//class Solution {
//public:
//    bool isPalindrome(string &s){
//        int size=s.size();
//        for (int i=0; i<=size/2; i++){
//            if (s[i]!=s[size-1-i]) return false;
//        }
//        return true;
//    }
//    string longestPalindrome(string s) {
//        // string ans="";
//        // int size=s.size();
//        // for (int i=0; i<size; i++){
//        //     for (int j=size-1; j>=i; j--){
//        //         int len=j-i+1;
//        //         if (len<=ans.size()) break;
//        //         string sub=s.substr(i, len);
//        //         if (isPalindrome(sub)){
//        //             ans=sub;
//        //         }
//        //     }
//        // }
//        // return ans;
//
//        int size=s.size();
//        // int dp[size+10][size+10]={0};
//        vector<vector<int>> dp(size, vector<int>(size, 0));
//        int maxLen=1, beginIndex=0;
//        for (int i=0; i<size; i++){
//            dp[i][i]=1;
//            if (i!=size-1 && s[i]==s[i+1]){
//                dp[i][i+1]=1;
//                beginIndex=i;
//                maxLen=2;
//            }
//        }
//        for (int len=3; len<=size; len++){
//            for (int i=0; i+len-1<size; i++){
//                int j=i+len-1;
//                if (s[i]==s[j] && dp[i+1][j-1]){
//                    dp[i][j]=1;
//                    maxLen=len;
//                    beginIndex=i;
//                }
//                // dp[i][j]=(s[i]==s[j] && d[i+1][j-1]);
//            }
//        }
//        return s.substr(beginIndex, maxLen);
//    }
//};


#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        vector< vector<int> > dp(size, vector<int>(size));
        // fill(dp[0], dp[0]+size*size, 0);
        string maxS=s.substr(0,1);
        for (int i=0; i<size; i++){
            dp[i][i]=1;
            if (i!=size-1){
                if (s[i]==s[i+1]){
                    dp[i][i+1]=1;
                    maxS=s.substr(i, 2);
                }
            }
        }
        for (int len=3; len<=size; len++){
            int j;
            for (int i=0; j=i+len-1, j<size; i++){
                if (s[i]==s[j] && dp[i+1][j-1]){
                	cout<<i<<" "<<" "<<j<<" "<<s.substr(i, j-i+1)<<endl;
                    if (j-i+1>maxS.size()){
                    	dp[i][j]
                        maxS=s.substr(i, j-i+1);
                    }
                }
            }
        }
        return maxS;
    }
};

int main(){
	Solution solution;
	string ans=solution.longestPalindrome("aaaaa");
	cout<<ans<<endl;
}


/**
妈的， c++真是坑多
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        vector< vector<int> > dp(size, vector<int>(size));
        int begin=0;
        int maxL=1;
        for (int i=0; i<size; i++){
            dp[i][i]=1;
            if (i!=size-1){
                if (s[i]==s[i+1]){
                    dp[i][i+1]=1;
                    maxL=2;
                    begin=i;
                }
            }
        }

        for (int len=3; len<=size; len++){
            for (int i=0; i+len-1<size; i++){
                int j=i+len-1;
                if (s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                    if (dp[i][j] && j-i+1>maxL){
                        maxL=j-i+1;
                        begin=i;
                    }
                }
            }
        }
        return s.substr(begin, maxL);
    }
}; 
