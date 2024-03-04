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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root){
            return {};
        }
        q.push(root);
        int cnt =0;
        while(!q.empty()){
            vector<int>td;
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }

                td.push_back(it->val);
                q.pop();
            }
            if(cnt&1){
                reverse(td.begin(), td.end());
            }
            cnt++;
            ans.push_back(td);
            
        }
        return ans;
    }
};