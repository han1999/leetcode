class Solution {
public: 
    int getSteps(int now, long long  n){
        int step=0;
        long long  l=now, r=now;
        while (l<=n){
            step+=r-l+1;
            l=10*l;

            /*
            这里会overflow，好家伙
            */
            r=min(10*r+9, n);
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        // //solution0: 超时不用说的
        // vector<string> vt(n);
        // for (int i=1; i<=n; i++){
        //     vt[i-1]=to_string(i);
        // }
        // sort(vt.begin(), vt.end());
        // return stoi(vt[k-1]);
        
        //因为之前从来没见过这种数据结构，我只能说流弊
        int ans=1;
        k--;
        while (k){
            int steps=getSteps(ans, n);
            if (k>=steps){
                k-=steps;
                ans++;
            }else {
                k--;
                ans*=10;
            }
        }
        return ans;
    }
};
