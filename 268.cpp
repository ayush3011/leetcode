int missingNumber(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)
            sum+=it;

        int n=nums.size();

        return (((n+1)*n)/2)-sum;
}
