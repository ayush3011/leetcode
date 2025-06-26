class Solution {
public:
    // Greedy Approach, TC : O(n)
    int longestSubsequence(string s, int k) {
        int n = s.size();

        long long multiplier = 1; // 2^0, 2^1....

        int length = 0;

        // iterating backwards to make up the decimal number
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') { // greedily choosing all the 0 bits because they do not impact the decimal value
                length++; 
            } else if (multiplier <= k) {  // choosing 1 bits only if they are <= k
                k -= multiplier;
                length++;
            }

            if (multiplier <= k) {
                multiplier <<= 1; // same as multiplier *=2;
            }
        }

        return length;
    }
};
