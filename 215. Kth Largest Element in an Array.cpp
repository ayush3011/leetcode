class Solution {
public:
    // // Approach 1 : Sorting, TC : O(n*logn)
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end(), greater<int>());
    //     return nums[k - 1];
    // }

    // // Approac 2 : Using min-heap : TC : O(n*logk) --> Worst k=n hence TC :
    // // O(n*logn)
    // int findKthLargest(vector<int>& nums, int k) {

    //     priority_queue<int, vector<int>, greater<int>>
    //         pq; // by default it is max-heap
    //     for (int& num : nums) {
    //         pq.push(num);
    //         if (pq.size() > k) {
    //             pq.pop();
    //         }
    //     }
    //     return pq.top();
    // }

    // Approach 3 : Using QuickSelect Algorithm, TC : Worst : O(n^2) but Avg TC
    // : O(n)

    int partitionAlgo(vector<int>& nums, int l, int r) {
        int p = nums[l]; // fixing the partition to the leftest element
        int i = l + 1, j = r;
        while (i <= j) {
            if (nums[i] < p && nums[j] > p) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= p) {
                i++;
            }
            if (nums[j] <= p) {
                j--;
            }
        }
        swap(nums[l], nums[j]);
        return j; // pivot is at jth index
    }

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0, r = n - 1, pivotIdx = 0;

        // kth largest element is at nums[k-1] when partitioned in descending
        // order

        while (true) {
            pivotIdx = partitionAlgo(nums, l, r);
            if (pivotIdx == k - 1) {
                break;
            } else if (pivotIdx > k - 1) {
                r = pivotIdx - 1;
            } else {
                l = pivotIdx + 1;
            }
        }
        return nums[pivotIdx];
    }
};
