//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        queue<TreeNode *>q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            vector<int>temp;
            
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *t = q.front();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                q.pop();
            }
            if(flag==1)reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};
