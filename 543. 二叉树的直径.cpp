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
    �������Ǽ��⣬����д�˲���ʱ��,����ȵ��Ǻܿ죬��Ҫ��û�뵽ÿ���ڵ㶼��һ��max
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
