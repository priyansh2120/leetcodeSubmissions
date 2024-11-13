class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(items.begin(), items.end());
        
    
        int maxBeautySoFar = 0;
        for (auto& item : items) {
            maxBeautySoFar = max(maxBeautySoFar, item[1]);
            item[1] = maxBeautySoFar;
        }

      
        vector<int> result;
        result.reserve(queries.size());

        
        for (int q : queries) {
            
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX},
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[0] < b[0];
                                  });
            
            if (it != items.begin()) {
                result.push_back((it - 1)->at(1));
            } else {
                result.push_back(0);
            }
        }
        
        return result;
    }
};