class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int most = 0;
        int count = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++)
        {
            
            if(nums[i] == 1)
            {
                count++;
            } else
            {
                count--;
            }
            if(mp.count(count))
            {
                int currLen = i - mp[count];
                most = max(currLen, most);
            } else
            {
                mp[count] = i;
            }
          
        }
        return most;
    }
};