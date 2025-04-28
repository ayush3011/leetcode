class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int i = 0, j = 0, n = nums.size();
        long long sum = 0, result = 0;

        while (j < n) {
            // adding the current number in the sum
            sum += nums[j];

            // if sum*length >= k we shrink the window size
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++; // moving i forward
            }

            // adding all the subarrays of the current found array.
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};
