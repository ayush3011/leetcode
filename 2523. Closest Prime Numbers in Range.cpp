class Solution {
public:
    bool checkPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {

        int firstPrime = 0, secondPrime = 0;
        int minDiff = INT32_MAX;
        vector<int> ans(2, -1);

        for (int i = left; i <= right; i++) {
            if (checkPrime(i)) {
                if (firstPrime == 0) {
                    firstPrime = i;
                } else if (secondPrime == 0) {
                    secondPrime = i;
                } else {
                    firstPrime = secondPrime;
                    secondPrime = i;
                }

                if (firstPrime != 0 && secondPrime != 0) {
                    if ((secondPrime - firstPrime) < minDiff) {
                        minDiff = secondPrime - firstPrime;
                        ans[0] = firstPrime;
                        ans[1] = secondPrime;
                    }
                }
            }
        }
        return ans;
    }
};
