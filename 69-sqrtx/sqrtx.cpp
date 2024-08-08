class Solution {
public:
    int mySqrt(int x) {
        long long low = 1;
        long long high = x;
        if(x==0){
            return 0;
        }

       
        int ans = x;
        while(high>=low){
            long long mid = (low+high)/2;
            if(mid<=x/mid){
                ans = mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};