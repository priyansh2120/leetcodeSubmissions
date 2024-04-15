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
            return true;
        }
        return false;
    }
    void helper(TreeNode* root, int curr, vector<int>&nums){
        if(isLeaf(root)){
            nums.push_back(curr*10+root->val);
        }
        if(root->left){
            helper(root->left, curr*10+root->val, nums);
        }
        if(root->right){
            helper(root->right, curr*10+root->val, nums);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int>nums;
        helper(root, 0, nums);
        int ans = 0;
        for(auto it:nums){
            cout<<ans<<endl;
            ans+=it;
        }
        return ans;
    }
};