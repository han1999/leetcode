//2022.07.27 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l=1;
        int r=1;
        /**
        这都快成套路了，跳过重复元素，if + continue
        */
        while (r!=nums.size()){
            //solution1.1:
            // while (r!=nums.size() && nums[r]==nums[r-1]){
            //     r++;
            // }
            // if (r!=nums.size()) nums[++l]=nums[r++];

            //solution1.2:
            if (nums[r]==nums[r-1]){
                r++;
                continue;
            }
            nums[l++]=nums[r++];

            //  //solution2:
            // if(nums[r]!=nums[r-1]){
            //     nums[l++]=nums[r++];
            // }else {
            //     r++;
            // }
        }
        return l;
    }
};
