// 2022.07.29 15.44
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // //��Ȼ�ܼ򵥣����Ǳ߽��������������˺ü��βų���
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
        // ���nums[mid]>target�� ��ôtarget�Ϳ���ռ��mid��λ��(��target����midǰ��)
        // ���� targetռ�ݵ�λ����mid�ĺ�һ��λ��
        // */
        // if (nums[mid]>target) return mid;
        // else return mid+1;

        // //solution2: lower_bound()
        // return lower_bound(nums.begin(), nums.end(), target)-nums.begin();

        //solution3:
        int l=0, r=nums.size()-1, ans=nums.size();
        while (l<=r){
            //>> ���ȼ���+-���� ��ô������
            //l �� 1 �������û���һģһ��
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
