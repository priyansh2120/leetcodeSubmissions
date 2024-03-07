class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int>adj[n];
        vector<int>in(n, 0);
        vector<int>ans;
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        queue<int>q;
        for(int i= 0; i<in.size(); i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int it = q.front();
            q.pop();
            cnt++;
            ans.push_back(it);
            for(auto it:adj[it]){
                in[it]--;
                if(in[it]==0)
                    q.push(it);
            }
        }
        if(cnt==n){
            return ans;
        }
        else{
            return {};
        }

    }
};