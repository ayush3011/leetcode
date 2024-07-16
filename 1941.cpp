bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;

        for (auto ch : s) {
            m[ch]++;
        }

        int checkValue = m[s[0]];

        for (auto it : m) {
            if (it.second != checkValue) {
                return false;
            }
        }
        return true;
}
