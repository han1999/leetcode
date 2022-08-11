class Solution {
public:
    //solution1:
    // /**
    // ��ô�㶼��ͨ���� ����һ��Ч������
    // */
    // set<vector<int>> st;
    // void trackback(int index, vector<vector<int>> &ans, vector<int> &nums){
    //     if (index==nums.size()){
    //         //solution1.1: ֱ����vector������
    //         // if (find(ans.begin(), ans.end(), nums)==ans.end()){
    //         //     ans.emplace_back(nums);
    //         // }

    //         //solution1.2: ����insert�� ʱ���Ϊԭ��1/15
    //         if (!st.count(nums)){
    //             st.insert(nums);
    //             ans.emplace_back(nums);
    //         }
    //         return;
    //     }
    //     for (int i=index; i<nums.size(); i++){
    //         swap(nums[i], nums[index]);
    //         trackback(index+1, ans, nums);
    //         swap(nums[i], nums[index]);
    //     }
    // }

    void trackback(int index, vector<vector<int>> &ans, vector<int> temp, vector<int> &nums, vector<int> &vis){
        if (index==nums.size()){
            ans.emplace_back(temp);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            /*
            continue�ܼ򻯺ܶ����
            ���� ������ 1 1 1 1 �����Ǳ��1234�� �����1234��1243�� ��ʵ����1111�����������1111����֤������1234�Ϳ�����
            */
            if (vis[i] || (i>0 && nums[i]==nums[i-1] && !vis[i-1])){
                continue;
            }
            temp.emplace_back(nums[i]);
            vis[i]=1;
            trackback(index+1, ans, temp, nums, vis);
            vis[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<vector<int>> ans;
        // trackback(0, ans, nums);
        // return ans;

        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size(), 0);
        trackback(0, ans, temp, nums, vis);
        return ans;
    }



};
