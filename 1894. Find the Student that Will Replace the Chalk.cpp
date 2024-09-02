class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += chalk[i];
        }

        int reducedK = k % sum;

        for (int i = 0; i < n; i++) {
            if (reducedK < chalk[i]) {
                return i;
            }
            reducedK = reducedK - chalk[i];
        }

        return -1;
    }
};
