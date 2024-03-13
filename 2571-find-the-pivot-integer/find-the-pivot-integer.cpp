class Solution {
public:
    int pivotInteger(int n) {
        // take choice from 1 to n
        for(int i =1;i<=n; i++){
            int l = (i*(i+1))/2;
            int r = (n*(n+1))/2-l+i;
            if(l==r){
                return i;
            }
        }
        return -1;
    }
};