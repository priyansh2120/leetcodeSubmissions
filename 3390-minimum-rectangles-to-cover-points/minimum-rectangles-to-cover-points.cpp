class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int i=0;
        int ans =0;
        if(w==0){
            map<int, int>mpp;
            for(auto it:points){
                mpp[it[0]]++;
            }
            return mpp.size();
        }
        while(i<points.size()){
            int ini = points[i][0];
            int fin = ini+w;
            while(i<points.size() and points[i][0]<=fin){
                i++;
            }
            ans++;
        }
        return ans;
           
        

        
    }
};