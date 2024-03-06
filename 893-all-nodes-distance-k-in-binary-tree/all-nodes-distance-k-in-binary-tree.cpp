/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // find the parent using bfs
        unordered_map<TreeNode*, TreeNode*>parent;
        parent[root]=NULL;
        TreeNode* temp = root; 
        queue<TreeNode*>q;
        q.push(temp);
        unordered_map<TreeNode*, bool>vis;
        while(!q.empty()){
            auto it = q.front();
            vis[it]=false;
            q.pop();
            if(it->left){
                parent[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                parent[it->right]= it;
                q.push(it->right);
            }
        }   

        queue<pair<TreeNode*,int>>q2;
        q2.push({target, 0});
        vector<int>ans;
        
        while(!q2.empty()){
            auto it = q2.front();
            TreeNode* curr = it.first;
            int dis = it.second;
            q2.pop();
            vis[curr]=true;

            if(dis==k){
                ans.push_back(curr->val);
                continue;
            }
            if(dis>k){
                continue;
            }

            if(curr->left and !vis[curr->left]){
                q2.push({curr->left,dis+1});
            }
            if(curr->right and !vis[curr->right]){
                q2.push({curr->right, dis+1});
            }
            if(parent[curr]!=NULL and !vis[parent[curr]]){
                q2.push({parent[curr], dis+1});
            }
        }
        return ans;
    }
};