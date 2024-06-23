double minimumAverage(vector<int>& nums) 
{
        vector<double> arr;
        int n=nums.size(), i=0, j=n-1;
        sort(nums.begin(), nums.end());
        while(i<j)
        {
            double average=((nums[i]+nums[j])/2.0);
            arr.push_back(average);
            i++;
            j--;
        }
        return *min_element(arr.begin(), arr.end());
}
