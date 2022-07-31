//2022.07.29
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // /*
        // 这道题很简单，但是有的细节没写，头脑已经很不清醒了
        // */
        // //行
        // unordered_set<char> st;
        // for (int i=0; i<9; i++){
        //     st.clear();
        //     for (const auto &ch:board[i]){
        //         if (ch!='.'){
        //             if (st.count(ch)) return false;
        //             st.insert(ch);
        //         }
        //     }
        // }
        // for (int col=0; col<9; col++){
        //     st.clear();
        //     for (int row=0; row<9; row++){
        //         if (board[row][col]!='.'){
        //             if (st.count(board[row][col])) return false;
        //             st.insert(board[row][col]);
        //         }
        //     }
        // }
        // auto valid=[&](vector<vector<char>> board, int row, int col){
        //     unordered_set<char> st;
        //     for (int i=row; i<row+3; i++){
        //         for (int j=col; j<col+3; j++){
        //             if (board[i][j]!='.'){
        //                 if (st.count(board[i][j])) return false;
        //                 st.insert(board[i][j]);
        //             }
        //         }
        //     }
        //     return true;
        // };

        // for (int row=0; row<9; row+=3){
        //     for (int col=0; col<9; col+=3){
        //         if (!valid(board, row, col)) return false;
        //     }
        // }
        // return true;

        // //solution2:
        // unordered_set<char> st1, st2;
        // for (int i=0; i<9; i++){
        //     st1.clear();
        //     st2.clear();
        //     for (int j=0; j<9; j++){
        //         if (board[i][j] != '.'){
        //             if (st1.count(board[i][j])) return false;
        //             st1.insert(board[i][j]);
        //         }
        //         if (board[j][i]!='.'){
        //             if (st2.count(board[j][i])) return false;
        //             st2.insert(board[j][i]);
        //         }
        //         if (i%3==0 && j%3==0){
        //             unordered_set<char> st3={};
        //             for (int row=i; row<i+3; row++){
        //                 for (int col=j; col<j+3; col++){
        //                     char ch=board[row][col];
        //                     if (ch!='.'){
        //                         if (st3.count(ch)) return false;
        //                         st3.insert(ch);
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // return true;


        //solution3:
        int row[9][10]={0};
        int col[9][10]={0};
        int subBox[3][3][10]={0};
        /*
        hashTable能想到，但是二维和三维的hashTable没想到
        subBox命名不错，row可以改为rowHash， 小数独编号为i/3, j/3挺巧妙的
        */
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j]=='.') continue;
                int num=board[i][j]-'0';
                if (++row[i][num]>1) return false;
                if (++col[j][num]>1) return false;
                if (++subBox[i/3][j/3][num]>1) return false;
            }
        }
        return true;
    }
};
