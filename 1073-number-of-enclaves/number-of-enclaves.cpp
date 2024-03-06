class Solution {
private:
    void solve(vector<vector<int>>& board) {
            int n = board.size();
            int m = board[0].size();

            queue<pair<int, int>>q;

            for(int i=0; i<m; i++){
                if(board[0][i]==1){
                    q.push({0,i});
                    board[0][i]=-1;
                }
                if(board[n-1][i]==1){
                    q.push({n-1, i});
                    board[n-1][i]=-1;
                }
            }
            for(int i=0; i<n; i++){
                if(board[i][0]==1){
                    q.push({i,0});
                    board[i][0]=-1;
                }
                if(board[i][m-1]==1){
                    q.push({i, m-1});
                    board[i][m-1]=-1;
                }
            }
            int dr[] = {0, 0, -1, 1};
            int dc[] = {-1, 1, 0, 0};
            while(!q.empty()){
                auto it = q.front();
                int cr = it.first;
                int cc = it.second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = cr+dr[i];
                    int nc = cc+dc[i];

                    if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]==1){
                        board[nr][nc]=-1;
                        q.push({nr, nc});
                    }
                }


            }
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>board = grid;
        solve(board);
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]==1){
                    ans++;
                    while(!q.empty()){
                        auto it = q.front();
                        int cr = it.first;
                        int cc = it.second;
                        q.pop();
                        for(int i=0; i<4; i++){
                            int nr = cr+dr[i];
                            int nc = cc+dc[i];

                            if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]==1){
                                board[nr][nc]=-1;
                                q.push({nr, nc});
                            }
                        }


                    }
                }
            }
        }
        return ans;
    }   
};