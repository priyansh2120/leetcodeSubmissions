//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        // code here
          // sliding window having sum == k
        int start =0;
        int end = 0;
        // if sum<k expand window
        // if sum == k expand window and check or check while zeroes are there encompass that
        // if sum > k start shrinking window

        // naive approach
        // find each and every subarray with 0(n^2) and calculate the sum

        // proper approach use sliding window as described above
        int sum = 0;
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            // operation 
            sum += nums[i];

            // condition
            while(sum>goal){
                sum-=nums[start];
                start++;
            }
            // updation 
            ans += i-start+1;
        }
        start =0;
        sum=0;
        for(int i=0; i<n and goal>0; i++){
            sum+=nums[i];

            while(sum>goal-1 and goal>0){
                sum-=nums[start];
                start++;
            }
            ans-=(i-start+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends