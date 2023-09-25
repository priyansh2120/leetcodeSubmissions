//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
     int atmost(vector<int>&nums, int k){
        int start =0;
        int ans = 0;
        int n = nums.size();
        int cnt = 0;
        // reading
        for(int i=0; i<n; i++){
            // operation
            if(nums[i]&1){
                cnt++;
            }
            // condition
            while(cnt>k){
                if(nums[start]&1){
                    cnt--;
                }
                start++;
            }
            // updation 
            ans += (i-start+1);
        }
        return ans;
    }
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atmost(nums,k)-atmost(nums, k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends