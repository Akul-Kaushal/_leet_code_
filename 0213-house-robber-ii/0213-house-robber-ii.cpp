class Solution {
public:
    int rob(vector<int>& nums) {
        if(0 == nums.size()) return 0;
        if(1 == nums.size()) return nums[0];
        if(2 == nums.size()) return max(nums[0],nums[1]);

        int left = nums[0];
        int mid_1 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size()-1; ++i) {
            int cur = max(left + nums[i], mid_1);
            left = mid_1;
            mid_1 = cur;
        }

        int mid_2 = nums[1];
        int right = max(nums[2], nums[1]);
        for (int i = 3; i < nums.size(); ++i) {
            int cur = max(mid_2 + nums[i], right);
            mid_2 = right;
            right = cur;
        }
        return max(mid_1,right);
    }
};