class Solution {
public:
    //solution1:
    // void trackback(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp){
    //     if (index==nums.size()){
    //         ans.emplace_back(temp);
    //         return;
    //     }
    //     for (const auto &num:nums){
    //         if (find(temp.begin(), temp.end(), num)==temp.end()){
    //             temp.emplace_back(num);
    //             trackback(index+1, nums, ans, temp);
    //             temp.pop_back();
    //         }
    //     }
    // }

    //solutiion2: 第一次大概明白排列树用swap的原因 
    //这样做不是按照顺序来的
    void trackback(int index, vector<int> &nums, vector<vector<int>> &ans){
        if (index==nums.size()){
            ans.emplace_back(nums);
            for (const auto &num:nums){
                printf("%d ", num);
            }
            cout<<endl;
            return;
        }
        for (int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            trackback(index+1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }

    /**
    标准全排列, 由于数太少了，都不用hash来存储有没有放进去
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        // trackback(0, nums, ans, temp);
        trackback(0, nums, ans);
        return ans;
    }
};
