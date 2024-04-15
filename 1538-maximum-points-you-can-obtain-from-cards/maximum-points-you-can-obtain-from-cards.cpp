class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0;
        int n = cardPoints.size();
        for(int i=0; i<n-k; i++){
            sum+=cardPoints[i];
        }
        int s =0;
        int e = n-k;
        int ans = 1e9;
        ans = min(ans, sum);
        while(e<n){
            sum-=cardPoints[s];
            sum+=cardPoints[e];
            e++;
            s++;
            ans = min(ans, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0)-ans;
    }
};