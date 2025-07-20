class Solution {
public:
    // TC --> O(32) or O(1) maximum 32 iterations or 32 right shifts for signed int
    // SC --> O(1)
    int hammingWeight(int n) {
        int count = 0; // to store count of set bits
        
        while (n != 0){
            if (n & 1){ // or n & 1 == 1
                count++;
            }
            n = n >> 1; // right shifting the bits
        }

        return count;
    }
};
