class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string n1 = to_string(num1), n2 = to_string(num2), n3 = to_string(num3);

        // Padding with leading zeros if necessary
        while (n1.size() < 4) n1 = "0" + n1;
        while (n2.size() < 4) n2 = "0" + n2;
        while (n3.size() < 4) n3 = "0" + n3;

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int intN1 = n1[i] - '0';
            int intN2 = n2[i] - '0';
            int intN3 = n3[i] - '0';
            ans = (ans * 10) + min(intN1, min(intN2, intN3));
        }
        return ans;
    }
};
