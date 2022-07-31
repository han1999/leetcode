// 2022.07.30
class Solution {
public:
    vector<pair<int, int>> blank;
    //������ ����
    /*
    [][]={0}�൱��ȫ����ֵ0��
    */
    int row[9][10]={0};
    int col[9][10]={0};
    int subBox[3][3][10]={0};
    /**
    valid�ǳ���Ҫ��һ���ҵ�һ���𰸣�����ֹ֮��ĵݹ�
    valid����trackback()����һ�������ܴﵽ���Ч��,��ֹ���л��˲���������λ�ö�����
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
                ��ס���+'0'
                */
                board[i][j]=num+'0';
                row[i][num]=col[j][num]=subBox[i/3][j/3][num]=1;
                trackback(index+1, board);
                if (valid) return;
                /*
                ������ô����������Ĵ��ڶ�������֮ǰ��Ӱ�죬���Ե��£����board�������һ����
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
                    //pair��ô��д 
                    /*
                    ������д��blank.emplace_back(i, j); 
                    blank.emplace_back({i,j})�ǲ��е�, �Ҳ²�������Ϊemplace_back��i, j��Ϊ����������pair�Ĺ��췽��
                    ����blank.push_back({i, j})�ǿ��Ե�
                    */
                    // blank.emplace_back(i,j);
                    blank.push_back({i,j});
                }else {
                    int num=board[i][j]-'0';
                    //�Ȳ����жϣ���������н�
                    row[i][num]=col[j][num]=subBox[i/3][j/3][num]=1;
                }
            }
        }
        trackback(0, board);
    }
};
