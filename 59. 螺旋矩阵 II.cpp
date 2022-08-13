class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x=0, y=0;
        //pair��ʼ��
        vector<pair<int, int>> dir={{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int dirIndex=0;
        /*
        �����������ȫ����Ҫ�ģ�����ͨ���ж�ans[i][j]�Ƿ����0���ó���û�з��ʹ�
        */
        vector<vector<int>> vis(n, vector<int>(n));
        /*
        ��Χ�ǵ�n*n ������n ֮ǰд������ʱ��Ҳ�������������, ��������
        */
        for (int i=0; i<n*n; i++){
            // cout<<x<<" "<<y<<endl;
            ans[x][y]=i+1;
            vis[x][y]=1;
            int nextX=x+dir[dirIndex].first;
            int nextY=y+dir[dirIndex].second;
            /*
            nextX�� nextY�����������ƴ��
            */
            if (nextX<n && nextX>=0 && nextY<n && nextY>=0 && !vis[nextX][nextY]){
                x=nextX;
                y=nextY;
            }else {
                // cout<<"we get here"<<endl;
                /*
                ����������һ���ؼ����ؾ��ǣ�
                ���������һ���ڵ㣬�����Ľڵ㣬�ڵ�ǰ������ײǽ�󣬻������򣬾����Լ�����
                */
                dirIndex=(dirIndex+1)%4;
                x+=dir[dirIndex].first;
                y+=dir[dirIndex].second;
            }
        }
        return ans;
    }
};
