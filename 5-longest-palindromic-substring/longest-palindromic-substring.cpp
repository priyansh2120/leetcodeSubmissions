typedef long long int ll;

class Hash {
    const int MOD = 1e9 + 7;
    const ll b1 = 5689, b2 = 8861;
    vector<pair<ll, ll>> hashes, pow;

public:
    Hash(string s) {
        int n = s.size();
        hashes.assign(n + 1, {0, 0});  // Fixed initialization
        pow.assign(n + 1, {1, 1});

        for (int i = 1; i <= n; i++) {
            hashes[i] = {
                (hashes[i - 1].first * b1 + (s[i - 1] - 'a' + 1)) % MOD,
                (hashes[i - 1].second * b2 + (s[i - 1] - 'a' + 1)) % MOD
            };
            pow[i] = {
                (pow[i - 1].first * b1) % MOD,
                (pow[i - 1].second * b2) % MOD
            };
        }
    }

    pair<ll, ll> get(int l, int r) {
        l++, r++;  // Convert to 1-based indexing
        ll hash1 = (hashes[r].first - (hashes[l - 1].first * pow[r - l + 1].first % MOD) + MOD) % MOD;
        ll hash2 = (hashes[r].second - (hashes[l - 1].second * pow[r - l + 1].second % MOD) + MOD) % MOD;
        return {hash1, hash2};
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        Hash hash1(s);
        string t = s;
        reverse(t.begin(), t.end());
        Hash hash2(t);

        int maxLen = 1, start = 0;

        auto isPalindrome = [&](int l, int r) {
            return hash1.get(l, r) == hash2.get(n - 1 - r, n - 1 - l);
        };

        for (int i = 0; i < n; i++) {
            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            // Even length
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};