class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int reduction_count = 0;
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - reduction_count < 0)
                ans += 0;
            else
                ans = ans + (happiness[i] - reduction_count);
            reduction_count++;
        }
        return ans;
    }
};