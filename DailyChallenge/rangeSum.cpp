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
    int ans;
public:
    void util(TreeNode*root, int l, int h){
        if(root == NULL){
            return;
        }
        if(root->val >= l&& root->val <= h){
            ans+=root->val;
        }
        util(root->left, l, h);
        util(root->right, l, h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        util(root, low, high);
        return ans;


    }
};
