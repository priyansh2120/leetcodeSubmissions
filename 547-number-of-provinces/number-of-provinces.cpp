class Solution {
private:
    void bfs(int node, vector<int>&vis, vector<vector<int>>& isConnected){
        queue<int>q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<isConnected.size(); i++){
                if(isConnected[curr][i]==1 and vis[i]==0){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // ek loop chala j
        int n = isConnected.size();
        vector<int>vis(n, 0);
        int cnt= 0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                bfs(i, vis, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};