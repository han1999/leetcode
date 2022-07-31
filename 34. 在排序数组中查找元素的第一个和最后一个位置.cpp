//2022.07.29
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // /**
        // 这个破方法，竟然还击败一半的人
        // */
        // if (nums.empty()) return {-1,-1};
        // // if (nums.size()==1) return nums[0]==target?{0,0}:{-1,-1};
        // int l=0, r=nums.size()-1;
        // while (l<=r){
        //     int mid=(l+r)/2;
        //     if (nums[mid]==target){
        //         int lLimit=mid, rLimit=mid;
        //         while (lLimit>=0 && nums[lLimit]==target){
        //             lLimit--;
        //         }
        //         while (rLimit<nums.size() && nums[rLimit]==target){
        //             rLimit++;
        //         }
        //         return {lLimit+1, rLimit-1};
        //     }
        //     if (nums[mid]>target){
        //         r=mid-1;
        //     }else {
        //         l=mid+1;
        //     }
        // }
        // return {-1,-1};


        //solution2:
        if (nums.empty()) return {-1, -1};
        auto binarySearch=[&](vector<int> nums, int target, bool isLower){
            int l=0, r=nums.size()-1;
            // int ans=-1;
            /*
            ans初值是-1不行，可以返回大的。不能返回-1，没找到的话，num.size()符合逻辑，-1不符合
            */
            int ans=nums.size();
            while (l<=r){
                int mid=(l+r)/2;
                // bool needNext=isLower?nums[mid]>=target:nums[mid]>target;
                if (/*needNext*/ isLower?nums[mid]>=target:nums[mid]>target){
                    /*
                    不停更新ans
                    */
                    ans=mid;
                    r=mid-1;
                }else {
                    l=mid+1;
                }
            }
            return ans;
        };
        /*
        其实就是lower_bound()和upper_bound()
        */
        int lLimit=binarySearch(nums, target, true);
        int rLimit=binarySearch(nums, target, false)-1;
        if (lLimit>=0 && lLimit<nums.size() && nums[lLimit]==target) return {lLimit, rLimit};
        else return {-1, -1};
    }
};
