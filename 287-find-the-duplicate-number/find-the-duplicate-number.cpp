class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect intersection point
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];           // move 1 step
            fast = nums[nums[fast]];    // move 2 steps
        } while (slow != fast);

        // Phase 2: Find entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};