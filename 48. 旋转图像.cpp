class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //00->02
        //01->12
        //02->22
        //10->01
        //(11->11)
        //12->21
        //20->00
        //21->10
        //22->20
        //solution1: ������Ҫ�󣬵�����ͨ��:
        // int n=matrix.size();
        // vector<vector<int>> temp(n, vector<int>(n));
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<n; j++){
        //         temp[i][j]=matrix[n-1-j][i];
        //     }
        // }
        // matrix=temp;

        //solution2: ��תת��Ϊ��ת����: ��ת�ã��ٷ�ת
        int n=matrix.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);                
            }
        }
    }
};
