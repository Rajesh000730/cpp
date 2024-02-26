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
    TreeNode* helper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &inOrder) {
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inorderRoot = inOrder[root->val];
        int left = inorderRoot - is;
        root->left = helper(preorder, ps + 1, ps + left,
        inorder, is, inorderRoot - 1, inOrder);
        root->right = helper(preorder, ps + left + 1, pe,
        inorder, inorderRoot + 1, ie, inOrder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrder;
        for(int i=0; i<inorder.size(); i++) {
            inOrder[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder, 0, preorder.size() - 1,
        inorder, 0, inorder.size() - 1, inOrder);
        return root;
    }
};