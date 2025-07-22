class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int _max = 0, cur = 0;
        int slide = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (0 == nums[i]) {
                cur++;
            }

            while (cur > k) {
                if (0 == nums[slide]) {
                    cur--;
                }
                slide++;
            }
            _max = max(_max, i - slide + 1);
        }
        return _max;
    }
};