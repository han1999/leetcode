// 2022.07.29 15.44
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // //虽然很简单，但是边界条件，还是试了好几次才出来
        // if (nums.empty()) return 0;
        // int l=0, r=nums.size()-1, mid;
        // while (l<=r){
        //     mid=(l+r)/2;
        //     if (nums[mid]==target) return mid;
        //     if (nums[mid]>target){
        //         r=mid-1;
        //     }else {
        //         l=mid+1;
        //     }
        // }
        // /*
        // 如果nums[mid]>target， 那么target就可以占据mid的位置(把target摆在mid前面)
        // 否则， target占据的位置是mid的后一个位置
        // */
        // if (nums[mid]>target) return mid;
        // else return mid+1;

        // //solution2: lower_bound()
        // return lower_bound(nums.begin(), nums.end(), target)-nums.begin();

        //solution3:
        int l=0, r=nums.size()-1, ans=nums.size();
        while (l<=r){
            //>> 优先级比+-还低 最好打个括号
            //l 和 1 两个长得基本一模一样
            int mid=l+((r-l)>>1);
            if (nums[mid]>=target){
                r=mid-1;
                ans=mid;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }
};
