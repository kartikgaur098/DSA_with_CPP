class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, left = 0;
        for (int num : nums) total += num;

        for (int i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }

        return -1;
    }
};
