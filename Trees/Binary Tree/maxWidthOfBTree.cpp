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

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
        long long ans = -1;
        q.push({root, 0});
        while(!q.empty()){
            long long min_id = q.front().second;
            int n =  q.size();
            long long id;
            for(int i = 0; i < n;i++){
                auto *it = q.front().first;
                id = q.front().second - min_id;
                q.pop();
                if(it->left){
                    q.push({it->left, id*2});
                }
                if(it->right){
                    q.push({it->right, id*2+1});
                }
            }
            ans= max(ans, id);
        }    

        return ans+1;
    }
};
