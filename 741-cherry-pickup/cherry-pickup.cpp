// class Solution {
// private:
//     int helper1(int r, int c, int n, vector<vector<int>>& grid){
//         // can go down
//         // can go right

//         // base case idhar likhio bhai
//         // path validity
//         if(r==n-1 and c==n-1){
//             int x = grid[r][c];
//             grid[r][c]=0;
//             return x;
//         }
//         // if anyone goes out of bound
//         if(r>=n or c>=n ){
//             return -1e9;
//         }
//         // ek toh agar thorn aa gaya toh return some big negative no if found
//         in driver code
//         // we will write 0 for that
//         if(grid[r][c]==-1){
//             return -1e9;
//         }

//         // lets go down bro
//         else if(grid[r][c]==0){
//             int down = helper1(r+1, c, n, grid);
//             int dr = helper1(r, c+1, n, grid);
//             return max(down, dr);
//         }
//         else if(grid[r][c]==1){
//             grid[r][c]=0;
//             int down = helper1(r+1, c, n, grid);
//             int dr = helper1(r, c+1, n, grid);

//             return 1+max(down, dr);
//         }
//         return -1e9;

//     }
//     int helper2(int r, int c, int n, vector<vector<int>>& grid){
//         // can go down
//         // can go right

//         // base case idhar likhio bhai
//         // path validity
//         if(r==0 and c==0){
//             int x = grid[r][c];
//             grid[r][c]=0;
//             return x;
//         }
//         // if anyone goes out of bound
//         if(r<0 or c<0){
//             return -1e9;
//         }
//         // ek toh agar thorn aa gaya toh return some big negative no if found
//         in driver code
//         // we will write 0 for that
//         if(grid[r][c]==-1){
//             return -1e9;
//         }

//         // lets go down bro
//         else if(grid[r][c]==0){
//             int up = helper2(r-1, c, n, grid);
//             int ul = helper2(r, c-1, n, grid);
//             return max(up, ul);
//         }
//         else if(grid[r][c]==1){
//             grid[r][c]=0;
//             int up = helper2(r-1, c, n, grid);
//             int ul = helper2(r, c-1, n, grid);

//             return 1+max(up, ul);
//         }
//         return -1e9;

//     }
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         // lets look at what are the options
//         // while going down we have down or right
//         // while going up we have left or up
//         // can we modify the source array given
//         // we have to collect most cherries condition will reverse

//         vector<vector<int>>cpy = grid;
//         int n= grid.size();
//         int l = helper1(0, 0, n, cpy);
//         if(l<0){
//             l=0;
//         }

//         int r = helper2(n-1, n-1, n, cpy);
//         if(r<0){
//             r=0;
//         }
//         cout<<l<<" "<<r<<endl;
//         return l+r;

//     }
// };
// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         // recursive me dikkat aayegi
//         // lets directly think of tabulation here
//         int n = grid.size();
//         vector<vector<int>>dp(n, vector<int>(n, 0));
//         if(grid[0][0]==-1 or grid[n-1][n-1]==-1){
//             return 0;
//         }

//         for(int i=0; i<n; i++){
//             if(grid[0][i]==-1){
//                 dp[0][i]=0;
//             }
//         }
//         for(int i=0; i<n; i++){

//             for(int j=0; j<n; j++){
//                 if(i==0){
//                 // can only go right
//                 // go right and if cherry found add 1 to prev
//                     if(grid[i][j]!=-1){
//                         if(j-1>=0)
//                             dp[i][j]=dp[i][j-1]+grid[i][j];
//                     }
//                     else{
//                         dp[i][j]=0;
//                     }

//                 }
//                 else{
//                     if(grid[i][j]!=-1){
//                         if(j-1>=0){

//                         }
//                     }
//                 }
//             }
//         }
//     }
// };

// problem with both the approach updating grid is hectic we cant keep track of
// which cherry was taken from where

// copying solution

/*
    So the idea here is instead of doing 1 traversal form (0,0)->(n-1,n-1) and
then 1 traversal from (n-1,n-1)->(0,0) We will do 2 traversals independtly from
(0,0)->(n-1,n-1). Now lets's talk about state we can have [r1,c1,r2,c2] -> state
we can have but this is O(n^4) we can reduce it to O(n^3) because manhattan
distance remains same i.e. (r1-0) + (c1-0) = (r2-0) + (c2-0) so the current
state becomes [r1,c1,c2] and r2 = r1+c1-c2
    */

class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
                int r1, int c1, int c2, int n) {
    int r2 = r1 + c1 - c2; // explanation in the above section
    // if any of the current rows or colums goes out of bound or there is a
    // thorn on a current block then return -1e9
    if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 ||
        grid[r2][c2] == -1)
        return -1e9;
    if (dp[r1][c1][c2] != -1) // if we have already calculated the value for
                            // current state then return that value
        return dp[r1][c1][c2];
    // if we are right most bottom corner then simply return grid value
    if (r1 == n - 1 && c1 == n - 1)
        return grid[r1][c1];
    // ans will be the ans for current state + future state
    int ans = grid[r1][c1];
    if (r1 != r2) // this is put in place to not pickup a cherry that is already
                // picked up
        ans +=grid[r2][c2]; 
    // if the cherry is not picked up already then pick it up
    // Now we need to take the max of 4 cases for both traversals
    // 1.) Right Right
    // 2.) Down Down
    // 3.) Right Down
    // 4.) Down Right
    int temp = max({helper(grid, dp, r1, c1 + 1, c2 + 1, n),
                    helper(grid, dp, r1 + 1, c1, c2, n),
                    helper(grid, dp, r1, c1 + 1, c2, n),
                    helper(grid, dp, r1 + 1, c1, c2 + 1, n)});
    ans += temp;          // add it to the ans
    dp[r1][c1][c2] = ans; 
    return ans;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, helper(grid, dp, 0, 0, 0, n));
    }
};