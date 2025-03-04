class Solution {
private:
    bool helper(int index, vector<int>&powers, int n, int sum){
        
        if(sum==n){
            return true;
        }
        if(sum>n){
            return false;
        }
        if(index>=powers.size()){
            return false;
        }
        int l = helper(index+1, powers, n, sum+powers[index]);
        int r = helper(index+1, powers, n, sum);
        return (l || r);
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int>powers;
        int temp = 1;
        while(temp<=1e7){
            powers.push_back(temp);
            temp*=3;
        }
        return helper(0, powers, n, 0);
    }
};