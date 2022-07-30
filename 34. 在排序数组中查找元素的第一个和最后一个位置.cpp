//2022.07.29
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // /**
        // ����Ʒ�������Ȼ������һ�����
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
            ans��ֵ��-1���У����Է��ش�ġ����ܷ���-1��û�ҵ��Ļ���num.size()�����߼���-1������
            */
            int ans=nums.size();
            while (l<=r){
                int mid=(l+r)/2;
                // bool needNext=isLower?nums[mid]>=target:nums[mid]>target;
                if (/*needNext*/ isLower?nums[mid]>=target:nums[mid]>target){
                    /*
                    ��ͣ����ans
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
        ��ʵ����lower_bound()��upper_bound()
        */
        int lLimit=binarySearch(nums, target, true);
        int rLimit=binarySearch(nums, target, false)-1;
        if (lLimit>=0 && lLimit<nums.size() && nums[lLimit]==target) return {lLimit, rLimit};
        else return {-1, -1};
    }
};
