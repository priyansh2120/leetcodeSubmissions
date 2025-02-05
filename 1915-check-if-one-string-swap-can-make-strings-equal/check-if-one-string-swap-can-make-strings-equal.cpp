class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        string t1="";
        string t2="";
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                cnt++;
                t2.push_back(s2[i]);
                t1.push_back(s1[i]);
            }
        }
        if(cnt>2){
            return false;
        }
        sort(t2.begin(), t2.end());
        sort(t1.begin(), t1.end());
        if(t1==t2){
            return true;
        }
        return false;
        
    }
};