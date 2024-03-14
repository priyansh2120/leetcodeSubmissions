class Solution
{
    private:
        void helper(int index, int sum, vector<int> &curr, vector<vector< int>> &ans,
            vector<int> &candidates, int target)
        {

            if (sum > target)
            {
                return;
            }

            if (sum == target)
            {
                ans.push_back(curr);	// Add the current combination to the result
                return;
            }

           	// Iterate through the candidates starting from 'index'
            for (int i = index; i < candidates.size(); i++)
            {
               	// Skip duplicates
                if (i > index && candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                curr.push_back(candidates[i]);	// Choose the current candidate
               	// Recursively call the helper function with the next index and
               	// updated sum
                helper(i + 1, sum + candidates[i], curr, ans, candidates, target);
                curr.pop_back();	// Backtrack: Remove the current candidate from the
               	// combination
            }
        }

    public:
        vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
        {
            vector<vector < int>> ans;
            vector<int> curr;
           	// Sort the candidates to handle duplicates correctly
            sort(candidates.begin(), candidates.end());
            helper(0, 0, curr, ans, candidates, target);
            return ans;
        }
};