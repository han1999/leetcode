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
	������deque�����ݽṹ��vectorҲ��ʵ��
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
        ֮ǰ����Ҳ���������������⣬����root����������nullptr��bfs�ͻ����
        */
        vector<vector<int>> vt;
        bfs(root, vt);
        return vt;
    }
};
