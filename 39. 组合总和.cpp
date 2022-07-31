//2022.07.30 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int index, int sum, vector<int> &candidates, int target){
        // if (sum>target) return;
        if (target==sum){
            ans.emplace_back(temp);
            return;
        }
        // if (index==candidates.size()) return;
        //把几个剪枝的放在一个if里面
        if (index==candidates.size() || sum>target) return;
        /**
        也行，效率应该低一点
        */
        if (index==candidates.size()){
            if (target==sum){
                ans.emplace_back(temp);
            }
            return;
        }
        temp.emplace_back(candidates[index]);
        dfs(index, sum+candidates[index], candidates, target);
        temp.pop_back();
        dfs(index+1, sum, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {{}};
        dfs(0, 0, candidates, target);
        return ans;
    }
};
