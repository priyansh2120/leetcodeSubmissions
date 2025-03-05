class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long mul = 0;
        if(n==1){
            return ans;
        }
        for(int i=2; i<=n; i++){
            mul+=4;
            ans+=mul;

        }
        return ans;
    }
};