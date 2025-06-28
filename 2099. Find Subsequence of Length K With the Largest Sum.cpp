class Solution {
public:
    // // Approach 1 : using sorting on numbers and indexes --> TC : O(nlogn)
    // // because of full array sorting
    // vector<int> maxSubsequence(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     vector<pair<int, int>> vec(n);

    //     for (int i = 0; i < n; i++) {
    //         vec[i] = make_pair(i, nums[i]);
    //     }

    //     auto lambda = [](auto& p1, auto& p2) { return p1.second > p2.second;
    //     };

    //     sort(vec.begin(), vec.end(), lambda);

    //     sort(vec.begin(), vec.begin() + k);

    //     vector<int> result(k);

    //     for (int i = 0; i < k; i++) {
    //         result[i] = vec[i].second;
    //     }
    //     return result;
    // }

    // Approach 2 : Using partial sorting --> TC : O(n)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            return nums;
        }

        vector<int> temp(nums); // temp = nums

        nth_element(begin(temp), begin(temp) + k - 1, end(temp),
                    greater<int>());
        // avg time = O(n)

        int kthLargest = temp[k - 1];
        int countKthLargest = count(begin(temp), begin(temp) + k, kthLargest);

        vector<int> result;

        for (int num : nums) {
            if (num > kthLargest) {
                result.push_back(num);
            } else if (num == kthLargest && countKthLargest > 0) {
                result.push_back(num);
                countKthLargest--;
            }

            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};
