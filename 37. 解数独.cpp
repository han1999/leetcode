// 2022.07.30
class Solution {
public:
    vector<pair<int, int>> blank;
    //排列树 问题
    /*
    [][]={0}相当于全部赋值0了
    */
    int row[9][10]={0};
    int col[9][10]={0};
    int subBox[3][3][10]={0};
    /**
    valid非常重要，一旦找到一个答案，就终止之后的递归
    valid放在trackback()的下一条语句就能达到这个效果,终止所有回退操作，其他位置都不行
    */
    bool valid=false;
    void trackback(int index, vector<vector<char>> &board){
        if (index==blank.size()){
            valid=true;
            return;
        }
        // if (valid) return;
        auto &[i, j]=blank[index];
        for (int num=1; num<=9; num++){
            if (row[i][num]==0 && col[j][num]==0 && subBox[i/3][j/3][num]==0){
                /*
                记住这个+'0'
                */
                board[i][j]=num+'0';
                row[i][num]=col[j][num]=subBox[i/3][j/3][num]=1;
                trackback(index+1, board);
                if (valid) return;
                /*
                不管怎么样，这个语句的存在都会消除之前的影响，所以导致，最后board还最初的一个样
                */
                board[i][j]='.';
                row[i][num]=col[j][num]=subBox[i/3][j/3][num]=0;

            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j]=='.'){
                    //pair怎么简写 
                    /*
                    答案上面写：blank.emplace_back(i, j); 
                    blank.emplace_back({i,j})是不行的, 我猜测这是因为emplace_back把i, j作为参数传给了pair的构造方法
                    但是blank.push_back({i, j})是可以的
                    */
                    // blank.emplace_back(i,j);
                    blank.push_back({i,j});
                }else {
                    int num=board[i][j]-'0';
                    //先不做判断，假设真的有解
                    row[i][num]=col[j][num]=subBox[i/3][j/3][num]=1;
                }
            }
        }
        trackback(0, board);
    }
};
