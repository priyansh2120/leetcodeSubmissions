//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int x) {
        // Your code goes here
        vector<vector<int>>ans;
        int n  = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            if(i>0 and arr[i]==arr[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j>i+1 and arr[j]==arr[j-1]){
                    continue;
                }
                int k = j+1;
                int l =n-1;
                while(k<l){
                    int sum = arr[i]+arr[j]+arr[k]+arr[l];
                    
                    if(sum<x){
                        k++;
                    }
                    else if(sum>x){
                        l--;
                    }
                    else if(sum==x){
                        ans.push_back({arr[i],arr[j], arr[k], arr[l]});
                        k++;
                        l--;
                        while(k<l and arr[k]==arr[k-1]){
                            k++;
                        }
                        while(k<l and arr[l]==arr[l+1]){
                            l--;
                        }
                    }
                }
                
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends