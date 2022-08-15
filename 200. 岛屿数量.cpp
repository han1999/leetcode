class Solution {
public:
    //solution1: dfs写法
    vector<vector<int>> dir={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool valid(int i, int j, int m, int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int m, int n){
        vis[i][j]=1;
        for (int index=0; index<dir.size(); index++){
            int nowI=i+dir[index][0];
            int nowJ=j+dir[index][1];
            if (valid(nowI, nowJ, m, n) && !vis[nowI][nowJ] && grid[nowI][nowJ]=='1'){
                /*
                第三个条件 grid[nowI][nowJ]非常重要
                */
                dfs(nowI, nowJ, grid, vis, m, n);
            }
        }

    }

    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int m, int n){
        queue<pair<int, int>> q;
        // pair<int, int> nowPos={i, j};
        /*
        pair的这种写法真方便
        */
        q.push({i, j});
        vis[i][j]=1;
        while (!q.empty()){
            pair<int, int> pos=q.front();
            // cout<<pos.first<<" "<<pos.second<<endl;
            q.pop();
            for (int index=0; index<dir.size(); index++){
                int nowI=pos.first+dir[index][0];
                int nowJ=pos.second+dir[index][1];
                if (valid(nowI, nowJ, m, n) && grid[nowI][nowJ]=='1' && !vis[nowI][nowJ]){
                    /*
                    这里出现一个严重错误，nowI, nowJ写成i,j导致死循环了
                    */
                    q.push({nowI,nowJ});
                    vis[nowI][nowJ]=1;
                }
            }
        }
    }
    vector<int> father;
    int findFather(int i){
        int temp=i;
        while (i!=father[i]){
            i=father[i];
        }
        while (temp!=father[temp]){
            int nowF=father[temp];
            father[temp]=i;
            temp=nowF;
        }
        return i;
    }
    /*
    Union要大写，否则和关键字冲突
    */
    void Union(int a, int b){
        int faA=findFather(a);
        int faB=findFather(b);
        if (faA!=faB){
            father[faA]=faB;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // int m=grid.size();
        // int n=grid[0].size();
        // vector<vector<int>> vis(m, vector<int>(n));
        // int cnt=0;
        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         if (grid[i][j]=='1' && !vis[i][j]){
        //             cnt++;
        //             //solution1：dfs写法
        //             // dfs(i, j, grid, vis, m, n);

        //             //solution2: bfs写法
        //             bfs(i, j, grid, vis, m, n);
        //         }
        //     }
        // }
        // return cnt;

        //solution3: 这tm竟然通过了，而且效率还是最高的
        int m=grid.size();
        int n=grid[0].size();
        father.resize(m*n);
        for (int i=0; i<m*n; i++){
            father[i]=i;
        }
        int cnt=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int nowIndex=i*n+j;
                if (grid[i][j]=='1'){
                    for (int k=0; k<dir.size(); k++){
                        int nextX=i+dir[k][0];
                        int nextY=j+dir[k][1];
                        if (valid(nextX, nextY, m, n) && grid[nextX][nextY]=='1'){
                            int nextIndex=nextX*n+nextY;
                            Union(nowIndex, nextIndex);
                            // grid[nowX][nowY]='0';
                        }
                    }
                }
                // grid[i][j]='0';
            }
        }
        //计数方法1：
        // unordered_set<int> st;
        // for (int i=0; i<m*n; i++){
        //     /*
        //     这个竟然和m没有关系！！
        //     */
        //     if (grid[i/n][i%n]=='1'){
        //         st.insert(findFather(i));
        //     }
        // }
        // return st.size();

        //计数方法2：
        vector<int> isRoot(m*n);
        for (int i=0; i<m*n; i++){
            if (grid[i/n][i%n]=='1'){
                isRoot[findFather(i)]=1;
            }
        }
        for (int i=0; i<m*n; i++){
            cnt+=isRoot[i];
        }
        return cnt;
    }
};
