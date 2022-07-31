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
        //�Ѽ�����֦�ķ���һ��if����
        if (index==candidates.size() || sum>target) return;
        /**
        Ҳ�У�Ч��Ӧ�õ�һ��
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
