class Solution {
private:
    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }

public:
    int calculate(string s) {
        int ans = 0;
        stack<pair<int, int>> st;
        int n = s.size();
        int sign = 1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+' || s[i] == '-') {
                sign = (s[i] == '+') ? 1 : -1;
            } else if (isDigit(s[i])) {
                int num = 0;
                while (i < n && isDigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                i--; 
                ans += sign * num;
            } else if (s[i] == '(') {
                st.push({ans, sign});
                ans = 0;
                sign = 1;
            } else if (s[i] == ')') {
                auto past = st.top();
                int xans = past.first;
                int xsign = past.second;
                ans = xans + xsign * ans;
                st.pop();
            }
        }
        return ans;
    }
};