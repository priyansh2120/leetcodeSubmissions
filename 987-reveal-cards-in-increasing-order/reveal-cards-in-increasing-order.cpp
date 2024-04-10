class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // alternate filling
        int j = 0;
        int mark = 1;
        int i = 0;
        int n = deck.size();
        vector<int>ans(n, -1);
        sort(deck.begin(), deck.end());
        while(j<n){
            if(ans[i]==-1 and mark ==1){
                mark=1-mark;
                ans[i]= deck[j]; 
                j++;
                i= (i+1)%n;
            }
            if(ans[i]==-1 and mark==0){
                mark= 1-mark;
                i= (i+1)%n;
            }
            if(ans[i]!=-1){
                i= (i+1)%n;
            }
        }
        return ans;
    }
};