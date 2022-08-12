class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //solution1:
        // //竟然一次通过了，连语法报错都没有
        // vector<int> ans;
        // int m=matrix.size();
        // int n=matrix[0].size();
        // int flag=0;
        // int x=0, y=0;
        // int maxX=m-1,minX=0,maxY=n-1,minY=0;
        // while (x<=maxX && x>=minX && y<=maxY && y>=minY){
        //     ans.push_back(matrix[x][y]);
        //     if (flag==0){
        //         // ans.push_back(matrix[x][y]);
        //         if (y+1<=maxY){
        //             y++;
        //         }else {
        //             flag=1;
        //             minX++;
        //             x++;
        //         }
        //     }else if (flag==1){
        //         // ans.push_back(matrix[])
        //         if (x+1<=maxX){
        //             x++;
        //         }else {
        //             flag=2;
        //             maxY--;
        //             y--;
        //         }
        //     }else if (flag==2){
        //         if (y-1>=minY){
        //             y--;
        //         }else {
        //             flag=3;
        //             maxX--;
        //             x--;
        //         }
        //     }else if (flag==3){
        //         if (x-1>=minX){
        //             x--;
        //         }else {
        //             flag=0;
        //             minY++;
        //             y++;
        //         }
        //     }
        // }
        // return ans;

        //solution2: 其实也是模，dir值得借鉴
        int m=matrix.size();
        int n=matrix[0].size();
        int total=m*n;
        vector<int> ans;
        int x=0, y=0;
        //控制方向，很多时候可以用dir数组
        int dir[][2]={{0,1}, {1, 0}, {0, -1}, {-1, 0}};//二维数组的第二维必须写，第一维不用写
        int dirIndex=0;
        //dirIndex的原理是基于，右下左上是轮流的
        vector<vector<int>> vis(m, vector<int>(n,0));
        /*
        很重要的一点，怎么判断遍历结束，其实很简单，元素个数小于total，说明仍然都可以遍历
        */
        for (int i=0; i<total; i++){
            ans.push_back(matrix[x][y]);
            vis[x][y]=1;
            int nextX=x+dir[dirIndex][0];
            int nextY=y+dir[dirIndex][1];
            if (nextX<0 || nextX>=m || nextY<0 || nextY>=n || vis[nextX][nextY]){
                /**
                轮流
                */
                dirIndex=(dirIndex+1)%4;
            }
            x+=dir[dirIndex][0];
            y+=dir[dirIndex][1];
        }
        return ans;
    }
};
