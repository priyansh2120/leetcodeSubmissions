class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        int i=0;
        int j=0;

        while(i<=n/2 and j<=n/2){
            vis[i][j]=1;
            i++;
            j++;
        }
        i=n/2;
        j=n/2;
        while(i>=0 and j<n){
            vis[i][j]=1;
            i--;
            j++;
        }
        i=n/2;
        j=n/2;
        while(i<n){
            vis[i][j]=1;
            i++;
        }

        unordered_map<int, int>mpp1;
        unordered_map<int, int>mpp2;
        int sum1=0;
        int sum2=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==1){
                    mpp1[grid[i][j]]++;
                    sum1++;
                }
                else{
                    sum2++;
                    mpp2[grid[i][j]]++;
                }
            }
        }

        // max jo hai uske remaining sabko banado
        // ab jo dusra hai usme uske alawa jitne hai usko 
        
        //    take 0 in 1st case
        int ans =1e9;
        int x = sum1-mpp1[0];
        int y = sum2-max(mpp2[1],mpp2[2]);
        ans = min(ans, x+y);

        x = sum1-mpp1[1];
        y = sum2-max(mpp2[0],mpp2[2]);
        ans = min(ans, x+y);

        x = sum1-mpp1[2];
        y = sum2-max(mpp2[1],mpp2[0]);
        ans = min(ans, x+y);

        return ans;
    }
};