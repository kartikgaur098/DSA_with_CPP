class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());  // O(n log n)
    //     int start = 0, end = nums.size() - 1;

    //     while (start <= end) {
    //         int mid = start + (end - start) / 2;

    //         if (nums[mid] > mid) {
    //             end = mid - 1;
    //         } else {
    //             start = mid + 1;
    //         }
    //     }

    //     return start;
    // }

    // sum wala solution 
    // int missingNumber(vector<int>& nums) {
    //     int ans=0;
    //      int sum=0,sumIndex=0;
    //      int n=nums.size();
    //     for (int i =0 ; i<n ; i++){
    //         sum = sum+ nums[i];
    //         sumIndex = sumIndex + i;
    //     }
    //     ans = (sumIndex + n) - sum ;
    //     return ans;
    // }

    // xor wala sol
    int missingNumber(vector<int>& nums) {
    int xorAll = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        xorAll ^= i;         // XOR of all indices
        xorAll ^= nums[i];   // XOR of all array elements
    }

    xorAll ^= n;             // Include the last number (n)

    return xorAll;           // Result is the missing number
}

};
