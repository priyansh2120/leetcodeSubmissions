//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        map<int, int>mpp;
        int n = s.size();
        int start = 0;
        int end = 0;
        int ans = -1e9;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
            end++;
            int maxi = -1e9;
            int sum =0;
            for(auto it:mpp){
                maxi = max(maxi, it.second);
                sum+=it.second;
            }
            sum-=maxi;
            
            if(sum>k){
                // cout<<i<<endl;
                while(true){
                    mpp[s[start]]--;
                    int maxi1 = -1e9;
                    int sum1 =0;
                    for(auto it:mpp){
                        maxi1 = max(maxi1, it.second);
                        sum1+=it.second;
                    }
                    sum1-=maxi1; 
                    start++;
                    if(sum1<=k){
                        break;
                    }
                   
                }
            }
            ans = max(ans, end-start);

        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends