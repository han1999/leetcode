class Solution {
public:
// tag: m, k, n, x, y, z
    string convert(string s, int numRows) {
        // int size=s.size();
        // if (numRows==1 || numRows>=size) return s;
        // vector<vector<char>> mat(numRows,vector<char>(1010));
        // int isDown=1;
        // int x=0, y=0;
        // int index=0;
        // // for (auto c:s) is also ok.
        // while (index<s.size()){
        //     mat[x][y]=s[index++];
        //     if (isDown){
        //         if (x!=numRows-1){
        //             x++;
        //         }else {
        //             isDown=0;
        //             x--;
        //             y++;
        //         }
        //     }else {
        //         if (x!=0){
        //             x--;
        //             y++;
        //         }else {
        //             isDown=1;
        //             x++;
        //         }
        //     }
        // }
        // string ans;
        // for (auto vt:mat){
        //     for (auto c:vt){
        //         if (c) ans+=c;
        //     }
        // }
        // return ans;
 
        int size=s.size();
        if (numRows==1 || size<=numRows) return s;
        int m=2*numRows-2;
        string ans;
        vector<vector<char>> mat(numRows, vector<char>(1005));
        int x=0, y=0;
        for (int i=0; i<size; i++){
            mat[x][y]=s[i];
            if (i%m<numRows-1){
                x++;
            }else {
                x--;
                y++;
            }
        }
        for (auto &vt:mat){
            for (auto c:vt){
                if (c) ans+=c;
            }
        }
        return ans;
    }
};
