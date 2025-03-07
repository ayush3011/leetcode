class Solution {
public:
    // // Approach 1
    // bool checkPrime(int n) {
    //     if (n < 2)
    //         return false;
    //     for (int i = 2; i <= sqrt(n); i++) {
    //         if (n % i == 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // vector<int> closestPrimes(int left, int right) {

    //     int firstPrime = 0, secondPrime = 0;
    //     int minDiff = INT32_MAX;
    //     vector<int> ans(2, -1);

    //     for (int i = left; i <= right; i++) {
    //         if (checkPrime(i)) {
    //             if (firstPrime == 0) {
    //                 firstPrime = i;
    //             } else if (secondPrime == 0) {
    //                 secondPrime = i;
    //             } else {
    //                 firstPrime = secondPrime;
    //                 secondPrime = i;
    //             }

    //             if (firstPrime != 0 && secondPrime != 0) {
    //                 if ((secondPrime - firstPrime) < minDiff) {
    //                     minDiff = secondPrime - firstPrime;
    //                     ans[0] = firstPrime;
    //                     ans[1] = secondPrime;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // Approach 2

    vector<bool> sieveHelper(int n) {
        vector<bool> vec(n + 1, true);
        vec[0] = vec[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (vec[i] == true) {
                for (int j = 2; i * j <= n; j++) {
                    vec[i * j] = false;
                }
            }
        }
        return vec;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> vec = sieveHelper(right);

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (vec[i] == true) {
                primes.push_back(i);
            }
        }

        int minDiff = INT32_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff=diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};
