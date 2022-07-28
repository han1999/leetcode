//2022.07.27
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //solution1:
        // if (nums.empty()) return 0;
        // int r=nums.size()-1;
        // int i;
        // for (i=0; i<nums.size() && nums[i]!=-1; i++){
        //     while (i<nums.size() && nums[i]==val){
        //         /*
        //         vector��[]�±곬��vector��С���ᱨ�ڴ��
        //         */
        //         for (int j=i; j<r; j++){
        //             nums[j]=nums[j+1];
        //         }
        //         // for(int k=0; k<nums.size(); k++) cout<<nums[k]<<" ";
        //         nums[r--]=-1;
        //     }
        //     // for(int k=0; k<nums.size(); k++) cout<<nums[k]<<" ";
        //     // cout<<endl;
        // }
        // cout<<i<<endl;
        // return r+1;


        // //solution2: 
        // /**
        // ������Ĵ��뼸��һģһ��
        // ����һ��ʼ����д��������ֳ��ֳ��Ĵ���
        // */
        // if (nums.empty()) return 0;
        // int l=0;
        // int r=0;
        // while (r!=nums.size()){
        //     if (nums[r]==val){
        //         r++;
        //         continue;
        //     }
        //     nums[l++]=nums[r++];
        // }
        // return l;

        // //solution3:
        // /**
        // �п��������Ǹ�ζ����
        // */
        // int l=0, r=nums.size()-1;
        // while (l<=r){
        //     if (nums[l]==val){
        //         nums[l]=nums[r--];
        //     }else{
        //         l++;
        //     }
        // }
        // return l;

        //solution3:
        return remove(nums.begin(), nums.end(), val)-nums.begin();
    }
};
