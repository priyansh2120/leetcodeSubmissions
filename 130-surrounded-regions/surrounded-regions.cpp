class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        queue<pair<int, int>>q;

        for(int i=0; i<m; i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='-';
            }
            if(board[n-1][i]=='O'){
                q.push({n-1, i});
                board[n-1][i]='-';
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='-';
            }
            if(board[i][m-1]=='O'){
                q.push({i, m-1});
                board[i][m-1]='-';
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

                if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]=='O'){
                    board[nr][nc]='-';
                    q.push({nr, nc});
                }
            }
            

        }
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};