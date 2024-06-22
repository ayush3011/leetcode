int minOperations(vector<int>& nums) 
{
        int ans=0, flag=0, i=0;
        
        for(i=0; i<nums.size()-2; i++)
        {
            if(nums[i]==0)
            {
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                ans++;
            }
        }
         
        if (find(nums.begin(), nums.end(), 0) != nums.end()) 
        {
            return -1;
        }
    
        return ans;
}
