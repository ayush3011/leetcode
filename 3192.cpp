int minOperations(vector<int>& nums) 
{
        int operations = 0;
        bool flip = false;

        for (int i = 0; i < nums.size(); ++i) 
        {
            if ((nums[i] == 0 && !flip) || (nums[i] == 1 && flip)) 
            {
                operations++;
                flip = !flip;
            }
        }
        return operations;
}
