class Solution {
public:
    //solution1:
    // /**
    // 怎么搞都能通过， 就是一个效率问题
    // */
    // set<vector<int>> st;
    // void trackback(int index, vector<vector<int>> &ans, vector<int> &nums){
    //     if (index==nums.size()){
    //         //solution1.1: 直接在vector中搜索
    //         // if (find(ans.begin(), ans.end(), nums)==ans.end()){
    //         //     ans.emplace_back(nums);
    //         // }

    //         //solution1.2: 引入insert， 时间变为原来1/15
    //         if (!st.count(nums)){
    //             st.insert(nums);
    //             ans.emplace_back(nums);
    //         }
    //         return;
    //     }
    //     for (int i=index; i<nums.size(); i++){
    //         swap(nums[i], nums[index]);
    //         trackback(index+1, ans, nums);
    //         swap(nums[i], nums[index]);
    //     }
    // }

    void trackback(int index, vector<vector<int>> &ans, vector<int> temp, vector<int> &nums, vector<int> &vis){
        if (index==nums.size()){
            ans.emplace_back(temp);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            /*
            continue能简化很多操作
            这里 假设有 1 1 1 1 把他们编号1234， 则出现1234和1243， 其实都是1111，对于任意的1111，保证他出现1234就可以了
            */
            if (vis[i] || (i>0 && nums[i]==nums[i-1] && !vis[i-1])){
                continue;
            }
            temp.emplace_back(nums[i]);
            vis[i]=1;
            trackback(index+1, ans, temp, nums, vis);
            vis[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<vector<int>> ans;
        // trackback(0, ans, nums);
        // return ans;

        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size(), 0);
        trackback(0, ans, temp, nums, vis);
        return ans;
    }



};
