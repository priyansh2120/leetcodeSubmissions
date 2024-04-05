class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        int i=0;
        while(i<n-1){
            if(tolower(s[i]) == tolower(s[i+1]) && ((isupper(s[i]) && islower(s[i+1])) || (isupper(s[i+1]) && islower(s[i])))){
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i--;
            }
            else{
                i++;
            }
            if(i<0){
                i++;
            }
        }
        return s;
    }
};