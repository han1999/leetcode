//2022.07.28 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for (i=nums.size()-2; i>=0; i--){
            if (nums[i]<nums[i+1]) break;
        }
        /*
        如果 i==-1 代表，遍历完了，中间都没有break
        */
        if (i!=-1){
            for (j=nums.size()-1; j>=0; j--){
                if (nums[j]>nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }
        // /**
        // 这个通过swap实现reverse的效果
        // */
        // int temp=i+nums.size();
        // for (int k=i+1; k<temp-k; k++){
        //     // int temp=i+nums.size();
        //     swap(nums[k], nums[temp-k]);
        // }

        //或者直接用库函数。vector和string的迭代器可以加减操作
        reverse(nums.begin()+i+1, nums.end());
        
    }
};
