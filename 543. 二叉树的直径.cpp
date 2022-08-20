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
    /*
    理论上是简单题，但是写了不少时间,求深度倒是很快，主要是没想到每个节点都求一下max
    */
    int ans;
    int dfs(TreeNode *node){
        if (node==nullptr){
            return 0;
        }
        int lDepth=dfs(node->left);
        int rDepth=dfs(node->right);
        ans=max(ans, lDepth+rDepth);
        return max(lDepth, rDepth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
