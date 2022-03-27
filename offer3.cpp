class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int hashTable[100000+10]={0};
        for (auto num:nums){
            if (hashTable[num]){
                return num;
            }
            hashTable[num]++;
        }
        return -1;
    }
};
