class Solution {
public:
    int trap(vector<int>& height) {
        //solution1:
        // int n=height.size();
        // vector<int> lMax(n ,0);
        // vector<int> rMax(n,0);
        // lMax[0]=height[0];
        // for (int i=1; i<n; i++){
        //     lMax[i]=max(lMax[i-1], height[i]);
        // }
        // rMax[n-1]=height[n-1];
        // int ans=0;
        // for (int i=n-2; i>=0; i--){
        //     rMax[i]=max(rMax[i+1], height[i]);
        //     ans+=min(lMax[i], rMax[i])-height[i];
        // }
        // return ans;

        // //solution2:
        // stack<int> stk;
        // int n=height.size();
        // int ans=0;
        // /**
        // 为什么stk存的是i， 不是height[i]， 因为通过i可以得到height[i]
        // 但是通过Height[i]不能得到i，除非存到一个pair中, 而i需要用来计算宽度
        // */
        // for (int i=0; i<n; i++){
        //     while (!stk.empty() && height[i]>height[stk.top()]){
        //         int preTop=stk.top();
        //         stk.pop();
        //         if (stk.empty()) break;
        //         int left=stk.top();
        //         /**
        //         为什么要有宽度，因为单调栈，栈顶不停弹出来，left在变化，宽度在变化
        //         如果用vector来模拟，说不定效果更好，因为下标能随时得到
        //         */
        //         ans+=(i-left-1)*(min(height[i], height[left])-height[preTop]);
        //     }
        //     stk.push(i);
        // }
        // return ans;

        //solution3:
        int l=0, r=height.size()-1;
        int lMax=height[0], rMax=height.back();//front, back()
        int ans=0;
        while (l<r){
            lMax=max(height[l], lMax);
            rMax=max(rMax, height[r]);
            if (lMax<rMax){
                ans+=lMax-height[l++];
            }else{
                ans+=rMax-height[r--];
            }
        }
        return ans;
    }
};
