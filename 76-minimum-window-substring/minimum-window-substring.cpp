class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        vector<int>v(256, 0);
        for(auto it: t){
            v[it]++;
        }
        int cnt =0;
        int st =0;
        int e=0;
        int ans =1e9;
        int beg=0;
        while(e<s.size()){
            v[s[e]]--;
            if(v[s[e]]>=0){
                cnt++;
            }
            while(cnt==m){
                if(e-st+1<ans){
                    ans=e-st+1;
                    beg = st;
                }
                v[s[st]]++;
                if(v[s[st]]>0){
                    cnt--;
                }
                st++;
            }
            e++;
        }
        return (ans==1e9)?"":s.substr(beg, ans);
    }
};