class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        int ans=dp[0];
        for (int i=1; i<n; i++){
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            ans=max(ans, dp[i]);
        }
        //这个函数挺方便的
        // return *max_element(dp.begin(), dp.end());
        return ans;
    }
};
