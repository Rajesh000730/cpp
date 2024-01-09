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
    void util(TreeNode *root, vector<int>&vec){
        if(!root)return;
        
        util(root->left, vec);
        if(!root->left && !root->right){
            vec.emplace_back(root->val);
        }
        util(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2)return false;
        vector<int>vec1;
        vector<int>vec2;
        util(root1, vec1);
        util(root2, vec2);
        if(vec1.size()!=vec2.size()) return false;
        int n = vec1.size();
        for(int i = 0; i < n;i++){
            if(vec1[i]!=vec2[i]) return false;
        }
        return true;


    }
};
