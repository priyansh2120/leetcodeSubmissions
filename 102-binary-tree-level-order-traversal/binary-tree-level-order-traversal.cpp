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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector <TreeNode*>curr;

        curr.push_back(root);
        vector<vector<int>> ans;

        while(curr.size()!=0){
            vector<int>temp;
            for(auto it:curr){
                temp.push_back(it->val);
            }
            ans.push_back(temp);
            vector<TreeNode*>copy = curr;
            curr.clear();
            for(auto it:copy){
                if(it->left){
                    curr.push_back(it->left);
                }
                
                if(it->right){
                    curr.push_back(it->right);
                }
            }
        }
        return ans;
    }
};