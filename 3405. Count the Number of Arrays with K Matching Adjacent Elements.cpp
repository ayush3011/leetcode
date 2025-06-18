int MOD = 1e9 + 7;

class Solution {
public:
    // Binary Exponentiation to compute a^b % MOD in O(log b) time
    int findPower(long long a, long long b) {
        long long result = 1;
        a = a % MOD;

        while (b > 0) {
            // If b is odd, multiply current 'a' to result
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }

            // Square the base
            a = (a * a) % MOD;

            // Divide the exponent by 2
            b = b / 2;
        }

        return result;
    }

    // Computes nCr % MOD using precomputed factorial and Fermat's inverse
    long long nCr(int n, int r, vector<long long>& factorial,
                  vector<long long>& fermatFact) {
        // nCr = n! / ((n-r)! * r!) % MOD
        //     = n! * inverse((n-r)!) * inverse(r!) % MOD
        return factorial[n] * fermatFact[n - r] % MOD * fermatFact[r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        // Precompute factorials up to n
        vector<long long> factorial(n + 1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for (int i = 2; i <= n; i++) {
            factorial[i] = (i * factorial[i - 1]) % MOD;
        }

        // Precompute inverse factorials using Fermat's Little Theorem
        // a^(-1) % MOD = a^(MOD-2) % MOD when MOD is prime
        vector<long long> fermatFact(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], MOD - 2);
        }

        // Total number of good arrays:
        // Choose k positions (out of n-1) where value changes: (n-1)Ck
        long long result = nCr(n - 1, k, factorial, fermatFact);

        // First element can be any of m values
        result = (result * m) % MOD;

        // Each of the remaining n-k-1 values can be chosen from (m-1) options
        result = (result * findPower(m - 1, n - k - 1)) % MOD;

        return result;
    }
};
