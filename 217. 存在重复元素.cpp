class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (const auto &num:nums){
            if (st.count(num)) return true;
            st.insert(num);
        }
        return false;
    }
};
