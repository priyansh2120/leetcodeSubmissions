class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int i = s.size() - 1;
        string temp = "";
        string ans = "";

        while (i >= 0) {
            if (temp.size() == k) {
                ans.append(temp);
                temp = "";
                ans.push_back('-');
            }

            if (s[i] != '-') {
                temp.push_back(toupper(s[i]));
            }

            i--;
        }

        ans.append(temp);
        reverse(ans.begin(), ans.end());

        // Erase leading hyphen, if present
        if (!ans.empty() && ans[0] == '-') {
            ans.erase(ans.begin());
        }

        return ans;
    }
};
