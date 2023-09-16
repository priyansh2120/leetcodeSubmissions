//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  private:
    long long helper(int n, vector<int>&arr, long long k){
        //   no of window having sum < k
        int start =0;
        int end =0;
        long long sum =arr[0];
        long long ans =0;
        while(end<n){
            if(sum<=k){
                end++;
                ans+=end-start;
                
                sum+=arr[end];
                
                
            }
            else{
                while(sum>k){
                    sum-=arr[start];
                    start++;
                }
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
  public:
    long long countSubarray(int n,vector<int> arr,long long l,long long r) {
        // code here
        return helper(n, arr, r)- helper(n, arr, l-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends