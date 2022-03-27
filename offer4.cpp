class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        if (rows==0) return false;
        int cols=matrix[0].size();
        if (cols==0) return false;
        int col=cols-1, row=0;
        while (row<rows && col>=0){
            // if (matrix[row][col]>target){
            //     col--;
            // }
            // if (col<0) break;
            // if (matrix[row][col]<target){
            //     row++;
            // }
            // if(row>=rows) break;
            // if (matrix[row][col]==target) return true;
            int now=matrix[row][col];
            if (now==target) return true;
            else if (now>target){
                col--;
            }else {
                row++;
            }
        }
        return false;
    }
};
