//class Solution {
//public:
//// tag: m, k, n, x, y, z
//    string convert(string s, int numRows) {
//        // int size=s.size();
//        // if (numRows==1 || numRows>=size) return s;
//        // vector<vector<char>> mat(numRows,vector<char>(1010));
//        // int isDown=1;
//        // int x=0, y=0;
//        // int index=0;
//        // // for (auto c:s) is also ok.
//        // while (index<s.size()){
//        //     mat[x][y]=s[index++];
//        //     if (isDown){
//        //         if (x!=numRows-1){
//        //             x++;
//        //         }else {
//        //             isDown=0;
//        //             x--;
//        //             y++;
//        //         }
//        //     }else {
//        //         if (x!=0){
//        //             x--;
//        //             y++;
//        //         }else {
//        //             isDown=1;
//        //             x++;
//        //         }
//        //     }
//        // }
//        // string ans;
//        // for (auto vt:mat){
//        //     for (auto c:vt){
//        //         if (c) ans+=c;
//        //     }
//        // }
//        // return ans;
// 
//        int size=s.size();
//        if (numRows==1 || size<=numRows) return s;
//        int m=2*numRows-2;
//        string ans;
//        vector<vector<char>> mat(numRows, vector<char>(1005));
//        int x=0, y=0;
//        for (int i=0; i<size; i++){
//            mat[x][y]=s[i];
//            if (i%m<numRows-1){
//                x++;
//            }else {
//                x--;
//                y++;
//            }
//        }
//        for (auto &vt:mat){
//            for (auto c:vt){
//                if (c) ans+=c;
//            }
//        }
//        return ans;
//    }
//};

//2022.07.21
//�ϴε�д���и�ֵ�ý���ĵط���������x��y�����һ�� 
#include <vector>
#include <string> 
using namespace std;
class Solution {
class Solution {
public:
    string convert(string s, int numRows) {
    	/**
		solution1��
		*/ 
        // if (numRows==1) return s;
        // /**
        // �����㣬��д
        // 2*row-2 ����ĸ ��Ӧ row-1 �У� size����ĸ����Ӧ�� size/2�У� �ټ���һ��1����һ��
        // */
        // int col=s.size()/2+1;
        // vector< vector<char>> vt2(numRows, vector<char>(col));
        // int nowRow=0, nowCol=0;
        // int isDown=1;
        // string ans;
        // for (auto ch:s){
        //     vt2[nowRow][nowCol]=ch;
        //     /** 
        //     nowRow+1���д��������Ԥ��
        //     */
        //     if (isDown){
        //         if (nowRow+1<numRows){
        //             nowRow++;
        //         }else {
        //             isDown=0;
        //             nowRow--;
        //             nowCol++;
        //         }
        //     }else {
        //         if (nowRow-1>=0){
        //             nowRow--;
        //             nowCol++;
        //         }else {
        //             isDown=1;
        //             nowRow++;
        //         }
        //     }
        // }
        // for (auto vt:vt2){
        //     for (auto ch:vt){
        //         if (ch){
        //             ans+=ch;
        //         }
        //     }
        // }
        // return ans;
        
        //solution2:
        if (numRows==1) return s;
        vector<vector<char>> vt2(numRows);
        int nowRow=0;
        int isDown=1;
        for (auto ch:s){
            vt2[nowRow].push_back(ch);
            if (isDown){
                if (nowRow+1<numRows){
                    nowRow++;
                }else {
                    isDown=0;
                    nowRow--;
                }
            }else {
                if (nowRow-1>=0){
                    nowRow--;
                }else{
                    isDown=1;
                    nowRow++;
                }
            }
        }
        string ans;
        for (auto vt:vt2){
            for (auto ch:vt){
                ans+=ch;
            }
        }
        return ans;
    }
};
