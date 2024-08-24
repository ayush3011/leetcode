class Solution {
public:
    long func(long halfLengthInteger, bool isEven) {

        long num = halfLengthInteger;

        if (isEven == false) {
            num = num / 10;
        } // skipping the last digit of the half length of odd length strings...

        // building the other half of the number
        while (num > 0) {
            int digit = num % 10;
            halfLengthInteger = halfLengthInteger * 10 + digit;
            num /= 10;
        }

        return halfLengthInteger;
    }

    string nearestPalindromic(string n) {

        int L = n.length();

        int mid = L / 2; // taking the half of the string n

        int halfLength =
            L % 2 == 0 ? mid
                       : mid + 1; // to handle the even and odd length strings

        long halfLengthInteger =
            stol(n.substr(0, halfLength)); // converting half into integer

        vector<long> possibleResults;

        possibleResults.push_back(func(halfLengthInteger, L % 2 == 0));
        possibleResults.push_back(func(halfLengthInteger + 1, L % 2 == 0));
        possibleResults.push_back(func(halfLengthInteger - 1, L % 2 == 0));
        possibleResults.push_back((long)(pow(10, L-1) - 1));
        possibleResults.push_back((long)(pow(10, L) + 1));

        long result = LONG_MAX;
        long diff = LONG_MAX;
        long originalNumber = stol(n);

        for (long num : possibleResults) {
            if (num == originalNumber)
                continue;

            if (abs(num - originalNumber) < diff) {
                diff = abs(num - originalNumber);
                result = num;
            } else if (abs(num - originalNumber) ==
                       diff) { // if there is a tie between the absolute value
                               // of two palindromes
                result = min(result, num);
            }
        }

        return to_string(result);
    }
};
