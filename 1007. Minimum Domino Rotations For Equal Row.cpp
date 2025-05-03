class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val) {
        int n = tops.size();
        // for counting swaps on both the sides
        int swapTop = 0, swapBottom = 0;

        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val)
                return -1;
            else if (tops[i] != val) {
                swapTop++;
            } else if (bottoms[i] != val) {
                swapBottom++;
            }
        }

        // return the minimun swaps of the two
        return min(swapTop, swapBottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int result = INT_MAX;

        // Doing it brute force because constraints are small
        for (int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);
            if (swaps != -1) {
                result = min(result, swaps);
            }
        }

        // if no swaps possible we return -1 else return result(swaps)
        return result == INT_MAX ? -1 : result;
    }
};
