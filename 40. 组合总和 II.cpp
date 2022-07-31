//2022.07.30
class Solution {
public:
    /*
    unordered_set<vector<int>> st;竟然不合法，也就是说unordered_set里面竟然不能放stl容器
    */
    set<vector<int>> st;
    int lastVal;
    void dfs(int index, int sum, vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int target){
        if (sum==target){
            // if (find(ans.begin(), ans.end(), temp)==ans.end()) ans.emplace_back(temp);
            // if (!st.count(temp)){
            //     st.insert(temp);
            //     ans.emplace_back(temp);
            // }
            ans.emplace_back(temp);
            lastVal=temp.back();
            return;
        }
        if (sum>target || index==candidates.size()) return;
        temp.emplace_back(candidates[index]);
        dfs(index+1, sum+candidates[index], ans, temp, candidates,target);
        temp.pop_back();
        /*
        这一步剪枝得当
        */
        // while (index+1!=candidates.size() && candidates[index]==candidates[index+1]){
        //     index++;
        // }
        // dfs(index+1, sum, ans, temp, candidates,target);
        //下面这种写法也行
        while (++index!=candidates.size() && candidates[index]==candidates[index-1]);
        dfs(index, sum , ans ,temp , candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, 0, ans, temp, candidates, target);
        return ans;
    }
};
