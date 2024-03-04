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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+ max(height(root->left), height(root->right));
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        
        return max(hl+hr, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));

    }
};