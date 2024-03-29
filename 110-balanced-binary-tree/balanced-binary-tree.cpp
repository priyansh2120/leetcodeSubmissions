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
private:
    
    int height(TreeNode* root, bool &ans){
        if(!root){
            return 0;
        }
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        if(abs(left-right)>1){
            ans = false;
        }
        return 1+max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        
        bool ans = true;
        height(root, ans);
        return ans;
    }
};