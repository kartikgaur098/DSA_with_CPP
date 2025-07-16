class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            // Ensure mid is even (so mid and mid+1 form a pair if valid)
            if (mid % 2 == 1) mid--;

            // Check if the pair starting at mid is valid
            if (nums[mid] == nums[mid + 1]) {
                // single element is in the right half
                low = mid + 2;
            } else {
                // single element is in the left half including mid
                high = mid;
            }
        }
        return nums[low];
    }
};
