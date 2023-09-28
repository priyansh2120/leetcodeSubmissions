//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int solve(int n, int m,vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,0)));

        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1==j2){
                    dp[n-1][j1][j2]= grid[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2]= grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int mx = INT_MIN;
                    for(int dj1 =-1 ; dj1<=1; dj1++){
                        for(int dj2 = -1; dj2<=1; dj2++){
                            if(j1==j2){
                                if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)
                                    mx = max(mx, grid[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
                                else
                                    mx = max(mx,INT_MIN);
                                
                            }
                            else{
                                if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)
                                    mx = max(mx, grid[i][j1]+grid[i][j2]+dp[i+1][j1+dj1][j2+dj2]);
                                else
                                    mx = max(mx,INT_MIN);
                            }
                        }
                    }
                    dp[i][j1][j2]=mx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends