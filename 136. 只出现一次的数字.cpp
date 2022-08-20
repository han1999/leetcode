class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        我瞎写的，竟然直接通过了
        主要性质： 
        a^a=0
        a^0=a
        满足交换律，结合律
        */
        int ans=0;
        for(const auto &num:nums){
            ans^=num;
        }
        return ans;
    }
};
