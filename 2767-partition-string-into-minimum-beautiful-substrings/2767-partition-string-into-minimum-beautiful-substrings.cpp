class Solution {
private:
    long long convert(string &s, int start, int end){
        long long num = 0;
        int i= 0;
        int n = s.size();
        for(int i=start; i<end; i++){
            num = num*2 + s[i]-'0';
        }
        return num;
    }
    bool isPowof5(long long x){
        if(x<125){
            return x==1 or x==5 or x==25;
        }
        if(x%125!=0){
            return false;
        }
        return isPowof5(x/125);
    }
public:
    int minimumBeautifulSubstrings(string s) {
        // in these kind of problem we utilize the concept of till storage in dp array
        // dp[i]-> min no of substring till ith index
        // we memoize the previous solutions

        int n = s.size();
        vector<int>dp(n+1, 1e9);
        dp[0]=0;

        for(int i=1; i<=n; i++){
            if(s[i-1]=='1'){
                for(int j=0; j<i; j++){
                    if(s[j]=='1'){
                        long long num = convert(s, j, i);
                        if(isPowof5(num)){
                            dp[i]= min(dp[i], 1+dp[j]);
                        }
                    }
                }
            }
        }
        return (dp[n]==1e9)?-1:dp[n];
    }
};