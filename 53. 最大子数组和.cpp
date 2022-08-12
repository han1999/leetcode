class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //solution1.1:
        // /*
        // 用动态规划的逻辑来写
        // */
        // int ans=nums[0];
        // vector<int> dp(nums.size());
        // dp[0]=nums[0];
        // for (int i=1; i<nums.size(); i++){
        //     dp[i]=max(nums[i], dp[i-1]+nums[i]);
        //     ans=max(ans, dp[i]);
        // }
        // return ans;

        //solution1.2: 简化了一个形式
        int ans=nums[0];
        int pre=0;
        for (const auto &num:nums){
            pre=max(num, pre+num);
            ans=max(ans, pre);
        }
        return ans;
    }
};
