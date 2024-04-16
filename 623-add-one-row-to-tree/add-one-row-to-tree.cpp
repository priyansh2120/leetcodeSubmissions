/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, int val, int depth) {
        if (depth == 0) {

            TreeNode* lc = root->left;
            TreeNode* rc = root->right;
            TreeNode* nn1 = new TreeNode(val);
            TreeNode* nn2 = new TreeNode(val);
            root->left = nn1;
            nn1->left = lc;
            root->right = nn2;
            nn2->right = rc;
            return;
        }
        if (root->left) {
            helper(root->left, val, depth - 1);
        }
        if (root->right) {
            helper(root->right, val, depth - 1);
        }
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nn = new TreeNode(val);
            nn->left= root;
            return nn;
        }
        helper(root, val, depth - 2);
        return root;
    }
};