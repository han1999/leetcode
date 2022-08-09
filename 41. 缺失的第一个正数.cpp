//2022.07.31 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //solution1:
        // map<int, int> mp;
        // for (const auto &num:nums){
        //     if (num>0){
        //         mp[num]++;
        //     }
        // }
        // if (!mp.count(1)) return 1;
        // for (const auto &[num, cnt]:mp){
        //     if (!mp.count(num+1)) return num+1;
        // } 
        // return -1;

        //solution2:
        // sort(nums.begin(), nums.end());
        // int i=0;
        // if (nums.back()<=0) return 1;
        // while (nums[i]<=0){
        //     i++;
        // }
        // if (nums[i]!=1) return 1;
        // while (i<nums.size()){
        //     if (i+1<nums.size() && (nums[i]==nums[i+1] || nums[i]+1==nums[i+1])){
        //         i++;
        //     }else {
        //         break;
        //     }

        // }
        // return nums[i]+1;
        
        // //solution3:
        // vector<int> hashTable(nums.size()+2);
        // for (const auto &num:nums){
        //     if (num>0 && num<=nums.size()){
        //         hashTable[num]++;
        //     }
        // }
        // for (int i=1; i<hashTable.size(); i++){
        //     if (hashTable[i]==0){
        //         return i;
        //     }
        // }
        // return -1;

        //solution4: 上面的解法都不符合题目要求
        // for (auto &num:nums){
        //     if (num<=0) num=INT_MAX;
        // }
        // for (int i=0; i<nums.size(); i++){
        //     /*
        //     这题复杂在，做标记的时候，也不改变值，只能采用取负号的方式
        //     符号代表，index+1这个数出现过了
        //     */
        //     int val=abs(nums[i]);
        //     if (val<=nums.size()){
        //         nums[val-1]=-abs(nums[val-1]);
        //     }
        // }
        // for (int i=0; i<nums.size(); i++){
        //     if (nums[i]>0) return i+1; 
        // }
        // return nums.size()+1;

        //solution4：
        /**
        值得借鉴，交换排好序
        */
        for (int i=0; i<nums.size(); i++){
            // if (nums[i]<=0 || nums[i]>=n+1) continue;
            /*
            第三个判断是多余的，但能够加强理解
            第四个判断是；某个数重复出现了
            */
            while (nums[i]>0 && nums[i]<=nums.size() && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};
