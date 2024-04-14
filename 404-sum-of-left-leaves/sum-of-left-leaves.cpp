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
    bool isLeaf(TreeNode* root){
        if(root->left==NULL and root->right==NULL){
            return 1;
        }
        return 0;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int l = 0;
        int r = 0;
        if(root->left){
            if(isLeaf(root->left)){
                l = root->left->val;
            }
            else{
                l = sumOfLeftLeaves(root->left);
            }
           
        }
        if(root->right){
            r = sumOfLeftLeaves(root->right);
        }
        return l+r;
    }
};