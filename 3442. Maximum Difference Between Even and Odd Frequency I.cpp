class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        int maxOddFreq = INT_MIN, minEvenFreq = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        for (auto it : m) {
            int freq = it.second;
            if (freq % 2 == 0) {
                minEvenFreq = min(minEvenFreq, freq);
            } else {
                maxOddFreq = max(maxOddFreq, freq);
            }
        }

        return maxOddFreq - minEvenFreq;
    }
};
