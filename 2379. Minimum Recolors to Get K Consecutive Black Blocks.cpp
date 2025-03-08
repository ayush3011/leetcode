class Solution {
public:
    // Approach 1
    //  int minimumRecolors(string blocks, int k) {
    //      // counting the operations
    //      int minOperations = INT_MAX;

    //     // iterating through the whole string with a sliding window of size k
    //     for (int i = 0; i <= blocks.size() - k; i++) {
    //         // storing number of operations for each window
    //         int temp = 0;
    //         for (int j = 0; j < k; j++) {
    //             if (blocks[i + j] == 'W') {
    //                 temp++;
    //             }
    //         }
    //         // finding the minimum among temp and minOperations
    //         minOperations = min(minOperations, temp);
    //         temp = 0;
    //     }

    //     return minOperations;
    // }

    // Approach 2
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0, j = 0;
        int ops = k;
        int w = 0;

        while (j < n) {
            if (blocks[j] == 'W') {
                w++;
            }

            if (j - i + 1 == k) {
                ops = min(ops, w);

                if (blocks[i] == 'W') {
                    w--;
                }
                i++;
            }
            j++;
        }
        return ops;
    }
};
