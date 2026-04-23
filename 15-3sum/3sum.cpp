class Solution {
public:
 vector<vector<int>> threeSum(vector<int>& a) {
    vector<vector<int>> res;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (i && a[i] == a[i-1]) continue;
        int l = i + 1, r = a.size() - 1;
        while (l < r) {
            int s = a[i] + a[l] + a[r];
            if (s < 0) l++;
            else if (s > 0) r--;
            else {
                res.push_back({a[i], a[l], a[r]});
                while (l < r && a[l] == a[l+1]) l++;
                // while (l < r && a[r] == a[r-1]) r--;
                l++; r--;
            }
        }
    }
    return res;
}
};