class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // brute
        // map and iterate
        // iteration can be optimized
        unordered_map<int, vector<int>>mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        for(auto it: mpp){
            int num = it.first;
            vector<int>ind = it.second;
            // presum array
            if(ind.size()==1){
                ans[ind[0]]=0;
                continue;
            }
            vector<long long>presum(ind.size(), 0);
           
            for(int i=1; i<ind.size(); i++){
                presum[i]= presum[i-1]+ind[i-1];
            }
            vector<long long>postsum(ind.size(), 0);
            for(int i=ind.size()-2; i>=0; i--){
                postsum[i]=postsum[i+1]+ind[i+1];
            }
            for(auto it: presum){
                cout<<it<<' ';
            }
            cout<<endl;
            for(auto it: postsum){
                cout<<it<<' ';
            }
            cout<<endl;
            for(int i=0; i<ind.size(); i++){
                long long ansi = 0;
                ansi += (long long)i*ind[i]-presum[i];
                // cout<<num*ind[i]-presum[i]<<endl;
                ansi += postsum[i]-(long long)(ind.size()-i-1)*ind[i];
                // cout<<postsum[i]-(ind.size()-i-1)*ind[i]<<endl;
                
                ans[ind[i]]=ansi;
            }
            
        }
        return ans;
    }
};