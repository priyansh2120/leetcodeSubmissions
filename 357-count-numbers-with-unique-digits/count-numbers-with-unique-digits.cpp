class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>cnt={1, 9, 9, 8, 7, 6, 5, 4, 3};
        vector<int>pre;
        pre.push_back(cnt[0]);
        int pro =1;
        for(int i=1; i<cnt.size(); i++){
            pro*=cnt[i];
            pre.push_back(pre[i-1]+pro);
        }
        
        return pre[n];
    }
};