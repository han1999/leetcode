class Solution {
public:
    int cnt=0;
    string ans, temp;
    bool findAns=false;
    vector<int> vis;
    void trackback(int index,int n, int k){
        if (index==n){
            if (++cnt==k){
                ans=temp;
                findAns=true;
            }
            return;
        }
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                vis[i]=1;
                temp+=i+'0';//temp.push_back()应该也行， 经测试确实可以，string和vector太相似了
                trackback(index+1, n, k);
                if (findAns) return;
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        //solution1：
        // vis.resize(n+1,0);
        // trackback(0, n, k);
        // return ans;

        //solution2:
        /*
        其实类似于贪心
        */
        vector<int> fac(n+1);
        fac[0]=1;
        for(int i=1; i<=n; i++){
            fac[i]=i*fac[i-1];
        }
        vector<int> valid(n+1, 1);
        string ans;
        for (int i=1; i<=n; i++){
            /*
            这里最关键，涉及到一个编号的问题
            第k个元素是从1编号的，计算机是从0编号的，
            从1开始的第k个元素，相当于从0开始的第k-1个元素
            后面的+1,是转换计算机->现实（从1开始）
            */
            int order=(k-1)/fac[n-i]+1;
            for (int j=1; j<=n; j++){
                /**
                这个第order大的元素的方法，值得借鉴
                */
                order-=valid[j];
                if (order==0){
                    valid[j]=0;
                    ans+='0'+j;
                    break;
                }
            }
            k=(k-1)%fac[n-i]+1;
        }
        return ans;
    }
};
