class Solution {
public:
    long long coloredCells(int n) {
        long long N = n;  // Ensure n is treated as long long
        return N * N + (N - 1) * (N - 1);
    }
};
