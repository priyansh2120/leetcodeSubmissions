//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    const int mod = 1000000007;
    private:
    long long helper(int n, vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n]%mod;
        }
        long long ans = 0;
        if(n>=1){
            ans=(ans+helper(n-1, dp))%mod;
        }
        if(n>=2){
            ans=(ans+helper(n-2, dp))%mod;
        }
        if(n>=3){
            ans=(ans+helper(n-3, dp))%mod;
        }
        return dp[n]=ans%mod;
    }
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        vector<int>dp(n+1, -1);
        return helper(n, dp)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends