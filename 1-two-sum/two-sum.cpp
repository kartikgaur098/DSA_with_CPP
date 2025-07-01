class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // sort(arr.begin(), arr.end());
        int i = 0;
        int j = 0;
        while (i <= j) {
            for (j = i+1; j <= arr.size()-1; j++) {
                int sum = arr[i] + arr[j];
                if (sum == target) {
                    return {i, j};
                }
            }
            i++;
        }
        return {-1, -1};
    }
};