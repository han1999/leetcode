class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans;
        // int maxNum=INT_MIN;
        // int max2=INT_MIN-1;
        // for (int i=0; i<k; i++){
        //     if (nums[i]>=maxNum){
        //         max2=maxNum;
        //         maxNum=nums[i];
        //     }
        // }
        // ans.push_back(maxNum);
        // int l=1, r=k;
        // int n=nums.size();
        // while(r<n){
        //     if (nums[r]>maxNum){

        //     }
        // }

        // //solution1: 原始但有用的做法
        // multiset<int, greater<int>> st;
        // vector<int> ans;
        // for (int i=0; i<k; i++){
        //     st.insert(nums[i]);
        // }
        // ans.push_back(*st.begin());
        // for (int i=1; i+k-1<nums.size(); i++){
        //     // st.erase(nums[i-1]);
        //     st.erase(st.find(nums[i-1]));
        //     st.insert(nums[i+k-1]);
        //     ans.push_back(*st.begin());
        // }
        // return ans;

        // //以下方法超时了
        // // if (k==1) return nums;
        // vector<int> ans;
        // int n=nums.size();
        // vector<int> dp(n);
        // dp[k-1]=*max_element(nums.begin(), nums.begin()+k);
        // ans.push_back(dp[k-1]);
        // for (int i=k; i<n; i++){
        //     if (nums[i]>=dp[i-1]){
        //         dp[i]=nums[i];
        //     }else {
        //         if (dp[i-1]!=nums[i-1-k+1]){
        //             dp[i]=dp[i-1];
        //         }else {
        //             dp[i]=*max_element(nums.begin()+i-k+1, nums.begin()+i+1);
        //         }
        //     }
        //     ans.push_back(dp[i]);
        // }
        // return ans;

        //solution2:
        /*
        stack: push pop top
        queue: push pop front back
        priority_queue: push pop top
        */
        priority_queue<pair<int, int >> pq;
        for (int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        int n=nums.size();
        vector<int> ans={pq.top().first};
        for (int i=k; i<n; i++){
            pq.push({nums[i], i});
            while (pq.top().second<i-(k-1)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;


    }
};
