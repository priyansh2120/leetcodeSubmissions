class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>>mpp;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode *curr = it.first;
            int cr = it.second.first;
            int cc = it.second.second;
            mpp[cc][cr].insert(curr->val);
            cout<<curr->val<<" "<<cr<<" "<<cc<<endl;
            if(curr->left){
                q.push({curr->left,{cr+1, cc-1}});
            }
            if(curr->right){
                q.push({curr->right,{cr+1, cc+1}});
            }
        }
        for(auto it:mpp){
            int col = it.first;
            vector<int>coldata;
            for(auto i:it.second){
                
                
                for(auto x:i.second){
                    coldata.push_back(x);
                }
                
            }
            ans.push_back(coldata);
        }
        return ans;
    }
};

