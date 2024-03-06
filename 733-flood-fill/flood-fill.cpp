class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans= image;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc]=color;
        while(!q.empty()){
            auto it = q.front();
            int cr = it.first;
            int cc = it.second;
            int data = image[cr][cc];
            q.pop();
            for(int i=0; i<4; i++){
                int nr = cr+dr[i];
                int nc = cc+dc[i];

                if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==data and ans[nr][nc]!=color){
                    q.push({nr, nc});
                    ans[nr][nc]=color;
                }
            }
        }
        return ans;
    }
};