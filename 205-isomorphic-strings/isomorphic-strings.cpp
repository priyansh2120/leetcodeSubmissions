class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mpp;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(t[i])!= mpp.end()){
                if(mpp[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                mpp[t[i]]=s[i];
            }
        }
        map<char, char>mpp1;
        for(int i=0; i<s.size(); i++){
            if(mpp1.find(s[i])!= mpp1.end()){
                if(mpp1[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                mpp1[s[i]]=t[i];
            }
        }

        return true;
    }
};