class Solution {
public:
    // // Approach 1 : using map, TC : O(n), SC : O(n)
    // int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    //     // mapping the pairs
    //     map<pair<int, int>, int> m;
    //     int result = 0;

    //     for (auto& d : dominoes) {
    //         // mapping pairs in ascending order for each domino
    //         if (d[0] > d[1]) {
    //             swap(d[0], d[1]);
    //         }
    //         m[{d[0], d[1]}]++;
    //     }

    //     for (auto& it : m) {
    //         int freq = it.second;
    //         result += (freq * (freq - 1) / 2); // combination formula, freqC2
    //     }

    //     return result;
    // }

    // Approach 2 --> using a vector, TC : O(n), SC : O(100) --> constant space
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> v(100, 0);
        int result = 0;

        for (auto& d : dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            int num = d[0] * 10 + d[1];

            result += (v[num]);

            v[num]++;
        }
        return result;
    }
};
