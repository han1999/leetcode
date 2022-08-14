class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x=0, y=0;
        //pair初始化
        vector<pair<int, int>> dir={{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int dirIndex=0;
        /*
        这个数组是完全不需要的，可以通过判断ans[i][j]是否等于0来得出有没有访问过
        */
        vector<vector<int>> vis(n, vector<int>(n));
        /*
        范围是到n*n ，不是n 之前写数独的时候，也遇到过这个问题, 不长记性
        */
        for (int i=0; i<n*n; i++){
            // cout<<x<<" "<<y<<endl;
            ans[x][y]=i+1;
            vis[x][y]=1;
            int nextX=x+dir[dirIndex].first;
            int nextY=y+dir[dirIndex].second;
            /*
            nextX和 nextY很相近，容易拼错
            */
            if (nextX<n && nextX>=0 && nextY<n && nextY>=0 && !vis[nextX][nextY]){
                x=nextX;
                y=nextY;
            }else {
                // cout<<"we get here"<<endl;
                /*
                能这样做的一个关键因素就是：
                除非是最后一个节点，其他的节点，在当前方向上撞墙后，换个方向，均可以继续走
                */
                dirIndex=(dirIndex+1)%4;
                x+=dir[dirIndex].first;
                y+=dir[dirIndex].second;
            }
        }
        return ans;
    }
};
