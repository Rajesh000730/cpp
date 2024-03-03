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
    vector<vector<int>>ans;
public:
    void util(TreeNode *root, int target, vector<int>path, int sum){
        if(root){
            if(!root->left && !root->right){
                if(sum+root->val == target){
                    path.push_back(root->val);
                    ans.push_back(path);
                    return;
                }
            }
            path.push_back(root->val);
            sum+=root->val;
            util(root->left, target, path, sum);
            util(root->right,target, path, sum);

        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        util(root, targetSum, path, 0);
        return ans;
    }
};
