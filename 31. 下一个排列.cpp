//2022.07.28 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for (i=nums.size()-2; i>=0; i--){
            if (nums[i]<nums[i+1]) break;
        }
        /*
        ��� i==-1 �����������ˣ��м䶼û��break
        */
        if (i!=-1){
            for (j=nums.size()-1; j>=0; j--){
                if (nums[j]>nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }
        // /**
        // ���ͨ��swapʵ��reverse��Ч��
        // */
        // int temp=i+nums.size();
        // for (int k=i+1; k<temp-k; k++){
        //     // int temp=i+nums.size();
        //     swap(nums[k], nums[temp-k]);
        // }

        //����ֱ���ÿ⺯����vector��string�ĵ��������ԼӼ�����
        reverse(nums.begin()+i+1, nums.end());
        
    }
};
