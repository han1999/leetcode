/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        这个判断，反而是最重要的
        */
        if (root==nullptr) return {};
        vector<vector<int>> vt;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            int size=q.size();
            vector<int> temp;
            for (int i=0; i<size; i++){
                TreeNode *now=q.front();
                q.pop();
                temp.push_back(now->val);
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right); 
            }
            vt.push_back(temp);
        }
        return vt;
    }
};
