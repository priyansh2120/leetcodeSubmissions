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
//  class Solution {
// private:
//     int pathsum(TreeNode* root){
//         if(!root){
//             return 0;
//         }
//         return root->val+max(pathsum(root->left), pathsum(root->right));
//     }
// public:
//     int maxPathSum(TreeNode* root) {
//         if(!root){
//             return 0;
//         }
//         int pl = pathsum(root->left);
//         int pr = pathsum(root->right);
//         cout<<root->val<<" "<<pl<<' '<<pr<<endl;
        
//         if(root->left ==NULL and root->right == NULL){
//             return root->val;
//         }
//         if(root->left == NULL){
//             return max({root->val+pr, maxPathSum(root->right), root->val});
//         }
//         if(root->right == NULL){
//             return max({root->val+pl, maxPathSum(root->left), root->val});
//         }
//         return max({root->val+pl+pr,maxPathSum(root->left), maxPathSum(root->right), root->val, root->val+pr, root->val+pl}); 
//     }
// };
class Solution {
private:
    int height(TreeNode* root, int &maxi){
        if(!root){
            return 0;
        }
        int l = max(0,height(root->left, maxi));
        int r = max(0,height(root->right, maxi));

        maxi = max(root->val+l+r, maxi);

        return max(root->val+l, root->val+r);
    }
public:
    int maxPathSum(TreeNode* root) {
        // kadane's + height concept
        int maxi = root->val;
        int h = height(root, maxi);
        return maxi;

    }
};