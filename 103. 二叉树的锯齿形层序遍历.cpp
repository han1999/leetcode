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
	答案用了deque的数据结构，vector也能实现
	*/ 
    void bfs(TreeNode *node, vector<vector<int>> &vt){
        queue<TreeNode *> q;
        q.push(node);
        bool flag=true;
        while (!q.empty()){
            flag=!flag;
            int size=q.size();
            vector<int> temp;
            for (int i=0; i<size; i++){
                TreeNode *now=q.front();
                temp.push_back(now->val);
                q.pop();
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right); 
            }
            if (flag){
                reverse(temp.begin(), temp.end());
            }
            vt.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr) return {};
        /*
        之前好像也遇到过这样的问题，就是root如果本身就是nullptr，bfs就会出错
        */
        vector<vector<int>> vt;
        bfs(root, vt);
        return vt;
    }
};
