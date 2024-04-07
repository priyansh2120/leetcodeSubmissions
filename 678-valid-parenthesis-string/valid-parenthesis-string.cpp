class Solution {
public:
    bool checkValidString(string s) {
        int open =0;
        int closed = 0;
        int unallo = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='('){
                open++;
            }
            else if (s[i]==')'){
                closed++;
            }
            else if(s[i]=='*'){
                unallo++;
                
            }
            int unfilled = open-closed;
            if(unfilled>unallo){
                return false;
            }
            
        }
        open = 0;
        closed=0;
        unallo=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }
            else if (s[i]==')'){
                closed++;
            }
            else if(s[i]=='*'){
                unallo++;
                
            }
            int unfilled = closed-open;
            if(unfilled>unallo){
                return false;
            }
            
        }
        return true;
    }
};