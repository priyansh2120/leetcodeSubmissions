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
    vector<int> postorderTraversal(TreeNode* root) {
    //    iterative using 1 stack
        int num =1;
        vector<int>pre; 
        vector<int>in;
        vector<int>post;
        stack<pair<TreeNode*, int>>st;
        st.push({root, 1});
        if(!root){
            return {};
        }
        while(!st.empty()){
            auto it = st.top();
            int num = it.second;
            TreeNode* curr = it.first;
            if(num==1){
                pre.push_back(curr->val);
                st.top().second++;
                if(curr->left){
                    st.push({curr->left, 1});
                }
            }
            else if(num==2){
                in.push_back(curr->val);
                st.top().second++;
                if(curr->right){
                    st.push({curr->right, 1});
                }
            }
            else{
                post.push_back(curr->val);
                st.pop();
            }
        }
        return post;
    }
};