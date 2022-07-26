// 2022.07.25
 class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /**
        有剪枝的方法,但是没有必要
        */
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for (int first=0; first<n; first++){
            if (first!=0 && nums[first]==nums[first-1]){
                continue;
            }
            for (int second=first+1; second<n; second++){
                if (second!=first+1 && nums[second]==nums[second-1]){
                    continue;
                }
                int third=second+1, four=n-1;
                while (third<four){
                    if (third!=second+1 && nums[third]==nums[third-1]){ 
                        third++;
                        continue;
                    }
                    if (four!=n-1 && nums[four]==nums[four+1]) {
                        four--;
                        continue;
                    }
                    // long long sum=nums[first]+nums[second]+nums[third]+nums[four]+0LL;
                    /**
                    本题最大的坑就是这个范围， 0LL 写到最前面才有用
                    */
                    long long sum=0LL+nums[first]+nums[second]+nums[third]+nums[four];
                    // cout<<nums[first]<<" "<<nums[second]<<" "<<nums[third]<<" "<<nums[four]<<" "<<sum<<endl;
                    if (sum>target){
                        four--;
                    }else if (sum==target){
                        ans.push_back({nums[first], nums[second], nums[third], nums[four]});
                        third++;
                        four--;
                    }else {
                        third++;
                    }
                }
            }
        }
        return ans;
    }

    // /**
    // 需不需要考虑 范围的问题 long long 确实是要用的
    // 时间复杂度太高
    // */
    // //cnt其实可以用temp.size()来代替
    // void dfs(int index, int cnt, long long sum, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums, int &target){
    //     if (cnt==4){
    //         if (sum==target && find(ans.begin(), ans.end(), temp)==ans.end()){
    //             ans.push_back(temp);
    //         }
    //         return;
    //     }
    //     if (index>nums.size()-1) return;
    //     if (sum>target && nums[index]>0) return;
    //     // if (sum<target && nums[index]<0) return;
    //     temp.push_back(nums[index]);
    //     dfs(index+1,cnt+1, sum+nums[index], temp, ans, nums, target);
    //     temp.pop_back();
    //     dfs(index+1, cnt, sum, temp, ans, nums, target);
    // }


};
