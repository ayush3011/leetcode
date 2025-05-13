class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {

        // character array to count the frequency of the characters
        vector<int> count(26, 0);

        for (char& ch : s) {
            count[ch - 'a']++;
        }

        while (t--) {
            vector<int> next(26, 0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    // 'z' becomes "ab"
                    next[0] = (next[0] + count[i]) % MOD;
                    next[1] = (next[1] + count[i]) % MOD;
                } else {
                    // char becomes next char
                    next[i + 1] = (next[i + 1] + count[i]) % MOD;
                }
            }
            count = move(next);
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + count[i]) % MOD;
        }

        return result;
    }
};
