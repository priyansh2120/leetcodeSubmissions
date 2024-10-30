const int NUM_MOD = 2;
const long long BASE = 89;
const long long MODS[NUM_MOD] = {1000000007LL, 1000000009LL};

struct Hash {
    vector<long long> hashValues[NUM_MOD], powerValues[NUM_MOD];

    Hash(const string &input) {
        int length = input.size();
        for (int i = 0; i < NUM_MOD; i++) {
            powerValues[i].resize(length + 1);
            hashValues[i].resize(length + 1);
            powerValues[i][0] = 1;
            hashValues[i][0] = 0;
        }
        for (int i = 0; i < length; i++) {
            char character = input[i];
            for (int j = 0; j < NUM_MOD; j++) {
                powerValues[j][i + 1] = powerValues[j][i] * BASE % MODS[j];
                hashValues[j][i + 1] = (hashValues[j][i] * BASE + character) % MODS[j];
            }
        }
    }

    array<long long, NUM_MOD> getHash(int left, int right) {
        array<long long, NUM_MOD> result;
        for (int i = 0; i < NUM_MOD; i++) {
            result[i] = (hashValues[i][right + 1] - hashValues[i][left] * powerValues[i][right + 1 - left] % MODS[i] + MODS[i]) % MODS[i];
        }
        return result;
    }
};

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        Hash hash(s);
        int start = 1, end = n;
        string longestDup = "";

        while (start <= end) {
            int mid = start + (end - start) / 2;
            string duplicate = findDuplicateOfLength(s, hash, mid);
            if (!duplicate.empty()) {
                longestDup = duplicate;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return longestDup;
    }

private:
    string findDuplicateOfLength(const string &s, Hash &hash, int len) {
        unordered_map<string, int> seenHashes;
        for (int i = 0; i + len <= s.size(); i++) {
            auto currentHash = hash.getHash(i, i + len - 1);
            string combinedHash = to_string(currentHash[0]) + "_" + to_string(currentHash[1]);

            if (seenHashes.count(combinedHash)) {
                return s.substr(i, len);
            }
            seenHashes[combinedHash] = i;
        }
        return "";
    }
};
