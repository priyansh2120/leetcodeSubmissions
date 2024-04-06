class Solution {
public:
      bool canBeValid(string s, string locked) {
          
        if (s.length()&1) 
            return false;
          
        int free = 0, open = 0, closed = 0, not_paired;
        for(int i = 0; i <s.length(); i++) {
            if (locked[i] == '0')
                free++;
            else if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                closed++;
            not_paired = closed-open;
            if (not_paired > free)
                return false;
        }
          
        free = 0, open = 0, closed = 0, not_paired=0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if (locked[i] == '0')
                free++;
            else if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                closed++;
            not_paired = open-closed;
            if (not_paired > free)
                return false;
        }
          
        return true;
    }
};