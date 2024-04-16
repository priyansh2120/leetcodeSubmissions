class Solution {
public:
    int characterReplacement(string s, int k) {
        int st=0, e=0;
        vector<int>freq(26, 0);
        int maxf = 0;
        int ans =0;
        while(e<s.size()){
            freq[s[e]-'A']++;
            maxf= max(maxf, freq[s[e]-'A']);

            while((e-st+1-maxf)>k){
                freq[s[st]-'A']--;
                maxf = *max_element(freq.begin(), freq.end());
                st++;
            }
            ans = max(ans, e-st+1);
            e++;
        }
        return ans;
    }
};