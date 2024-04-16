class Solution {
public:
    int numberOfSubstrings(string s) {
        int st=0, e=0;
        int mina=-1, minb=-1, minc=-1;
        int ans =0;
        while(e<s.size()){
            if(s[e]=='a'){
                mina=e;
            }
            else if(s[e]=='b'){
                minb=e;
            }
            else if(s[e]=='c'){
                minc=e;
            }

            ans+=max(0, min(mina, min(minb, minc))-st+1);
            e++;
        }
        return ans;
    }
};