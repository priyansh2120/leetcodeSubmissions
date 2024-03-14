class Solution {
private:
    void helper(int index, int sum, vector<int>&curr, vector<vector<int>>&ans, 
        vector<int>& candidates, int target){
            
        // each element can be taken any amount of time
        // 3 options
        // take the same element and call the recursion for the next
        if(sum>target or index>=candidates.size()){
            return;
        }
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        curr.push_back(candidates[index]);
        helper(index, sum+candidates[index], curr, ans, candidates, target);
        // helper(index+1, sum+candidates[index], curr, ans, candidates, target);
        curr.pop_back();
        helper(index+1, sum, curr, ans, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        helper(0, 0, curr, ans, candidates, target);
        return ans;
    }
};