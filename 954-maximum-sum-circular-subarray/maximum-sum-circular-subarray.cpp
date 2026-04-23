class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

            // max subarray
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            if(currMax < 0) currMax = 0;

            // min subarray
            currMin += nums[i];
            minSum = min(minSum, currMin);
            if(currMin > 0) currMin = 0;

            totalSum += nums[i];
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};