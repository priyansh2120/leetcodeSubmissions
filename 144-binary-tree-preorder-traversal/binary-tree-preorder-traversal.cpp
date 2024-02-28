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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(!root){
            return {};
        }
        st.push(root);
        while(!st.empty()){
            auto it= st.top();
            ans.push_back(it->val);
            st.pop();
            if(it->right){
                st.push(it->right);
            }
            if(it->left){
                st.push(it->left);
            }
            
            

        }
        return ans;
        
    }
};