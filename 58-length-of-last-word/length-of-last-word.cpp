class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        while(s[i]==' '){
            i--;
        }
        int cnt =0;
        while(i>=0 and  s[i]!=' ' ){
            i--;
            cnt++;
        }
        return cnt;
    }
};