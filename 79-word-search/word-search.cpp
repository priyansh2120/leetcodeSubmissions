class Solution {
private:
    bool dfs(int cr, int cc, string &word, vector<vector<char>>& board, 
            int index, vector<vector<int>>&vis){
        if(index>=word.size()){
            return true;
        }

        int dr[]={0, 0, 1, -1};
        int dc[]={-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if(nr>=0 and nr<board.size() and nc>=0 and nc<board[0].size()and vis[nr][nc]==0){
                if(board[nr][nc]==word[index]){
                    vis[nr][nc]=1;
                    if(dfs(nr, nc, word, board, index+1, vis)){
                        return true;
                    }
                    vis[nr][nc]=0;
                }
            }
        }
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(board.size(), vector<int>(board[0].size()));
                    vis[i][j]=1;
                    if(dfs(i,j, word, board, 1, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};