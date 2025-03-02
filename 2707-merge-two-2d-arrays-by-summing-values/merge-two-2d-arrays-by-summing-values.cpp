class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        while(ptr1<n and ptr2<m){
            if(nums1[ptr1][0]==nums2[ptr2][0]){
                ans.push_back({nums1[ptr1][0], nums1[ptr1][1]+nums2[ptr2][1]});

                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1][0]>nums2[ptr2][0]){
                ans.push_back(nums2[ptr2]);
                ptr2++;
            }
            else if(nums1[ptr1][0]<nums2[ptr2][0]){
                ans.push_back(nums1[ptr1]);
                ptr1++;
            }
            
        }
        if(ptr1!=n){
            for(int i=ptr1; i<n; i++){
                ans.push_back(nums1[i]);
            }
        }
        else if(ptr2!=m){
            for(int i=ptr2; i<m; i++){
                ans.push_back(nums2[i]);
            }
        }
        return ans;

    }
};