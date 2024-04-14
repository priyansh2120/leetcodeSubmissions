class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<int, pair<int, int>>>st;
        for(auto it: points){
            int dis = it[1]*it[1]+it[0]*it[0];
            st.insert({dis, {it[0], it[1]}});
        }
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
            auto itr = st.begin();
            auto it= *itr;
            st.erase(itr);

            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};