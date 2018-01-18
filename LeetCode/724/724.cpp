class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int d = nums.size();

        if(d == 0)
            return -1;

        int left = nums[0], right = 0;
        for(int i = 0; i < d; i++)
            right += nums[i];
        if(left == right)
            return 0;

        for(int i = 1; i < d; i++)
        {
            left += nums[i];
            right -= nums[i - 1];
            if(left == right)
                return i;
        }
        return -1;
    }
};
