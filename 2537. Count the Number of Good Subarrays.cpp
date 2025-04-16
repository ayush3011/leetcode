class Solution {
public:
    // TC : O(n) 
    long long countGood(vector<int>& nums, int k) {

        int n = nums.size(), i = 0, j = 0;
        long long result = 0;
        unordered_map<int, int> mp; // keeps track of the frequnecy of element
        long long pairs = 0;        // keeps track of the pairs 

        // expanding the sliding window, i.e. j
        while (j < n) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            // when we have enough pairs, we shrink
            while (pairs >= k) {
                result += (n - j); // adds all the remaining pairs of the array till the end;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};
