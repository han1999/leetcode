//2022.07.29 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size()==1) return nums[0]==target?0:-1;
        int l=0, r=nums.size()-1;
        while (l<=r){
            int mid=(l+r)/2;
            if (nums[mid]==target) return mid;
            /*
            一边有序，一边无序
            这里nums[mid]>=nums[l] 其中的 >= 不能是 >
            */
            if (nums[mid]>=nums[l]){
                if (nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }else {
                    l=mid+1;
                }
            }else {
                if (nums[mid]<target && target<=nums[r]){
                    l=mid+1;
                }else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
