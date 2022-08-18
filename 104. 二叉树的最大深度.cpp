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
    int ans=0;
    // void dfs(TreeNode *node, int depth){
    //     if (node==nullptr){
    //         ans=max(ans, depth);
    //         return;
    //     }
    //     dfs(node->left, depth+1);
    //     dfs(node->right, depth+1);
    // }

    int bfs(TreeNode *node){
        /*
        竟然有传空指针的情况
        */
        if (node==nullptr) return 0;
        int level=0;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty()){
            int levelSize=q.size();
            for (int i=0; i<levelSize; i++){
                TreeNode *now=q.front();
                q.pop();
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
            level++;
        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        //solution1:
        // dfs(root, 0);
        // return ans;

        //solution2:
        // return root==nullptr?0:max(maxDepth(root->left), maxDepth(root->right))+1;
        
        //solution3:
        return bfs(root);
    }
};
