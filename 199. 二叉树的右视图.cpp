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
    ע��node��Ϊnullptr
    ��׼�����棬�ṩ��һ�֣���ȡÿ���ڵ��depth�ķ����������һ���飬queue������¼depth��depthQ��qͬ��ͬ��
    */
    void bfs(TreeNode *node, vector<int> &vt){
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty()){
            int size=q.size();
            for (int i=0; i<size; i++){
                TreeNode *now=q.front();
                q.pop();
                if (i==size-1){
                    vt.push_back(now->val);
                }
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> vt;
        bfs(root, vt);
        return vt;
    }
};
