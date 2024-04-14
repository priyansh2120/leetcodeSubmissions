class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<vector<int>>s(points.begin(), points.end());
        int ans = 1e9;
        for(int i=0; i<points.size(); i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j=0; j<points.size(); j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1==x2 or y1==y2){
                    continue;
                }
                if(s.count({x1, y2}) and s.count({x2, y1})){
                    ans = min(ans, abs(x1-x2)*abs(y1-y2)) ;
                }
            }
        }
        return (ans==1e9)?0:ans;
    }
};