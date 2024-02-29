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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        bool even = true;
        while(!q.empty()){
            int num;
            if(even){
                num = -1;
            }
            else{
                num = 1e6+1;
            }
            int k = q.size();
            for(int i = 0; i < k;i++){
                auto x = q.front();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                if(even){
                    if(x->val > num && x->val%2 != 0){
                        num = x->val;
                    q.pop();
                }
                else{
                    return false;
                }
                }
                else{
                    if(x->val < num && x->val%2 == 0){
                    num = x->val;
                    q.pop();
                }
                else{
                    return false;
                }
                }
            }
            even = !even;
        }
        return true;
    }
};