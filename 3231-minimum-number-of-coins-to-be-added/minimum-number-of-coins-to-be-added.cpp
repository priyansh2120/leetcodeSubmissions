class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int range =0;
        sort(coins.begin(), coins.end());
        int i=0;
        int to_be_achieved = 1;
        int ans =0;
        int n = coins.size();
        while(range<target){
            

            if(i<n and coins[i]<=to_be_achieved){
                range+=coins[i];
                to_be_achieved+=coins[i];
                i++;
                cout<<range<<endl;
            }
            else{
                range+=to_be_achieved;
                to_be_achieved+=(to_be_achieved);
                ans++;
                cout<<range<<endl;
            }
        }
        
        return ans;
    }
};