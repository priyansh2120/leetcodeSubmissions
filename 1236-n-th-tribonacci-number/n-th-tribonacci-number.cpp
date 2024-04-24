class Solution {

public:
    int tribonacci(int n) {
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }
        
        for(int i=3; i<=n; i++){
            int curr = prev1+prev2+prev3;
            prev1= prev2;
            prev2= prev3;
            prev3=curr;
        }

        return prev3;
    }
};