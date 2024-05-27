class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = n; i >= 0; i--)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] >= i)
                    count++;
            }
            if (count == i)
                return count;
        }
        return -1;
    }
};