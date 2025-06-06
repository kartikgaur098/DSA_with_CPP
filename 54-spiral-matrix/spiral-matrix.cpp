class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();         // number of rows
        int m = mat[0].size();      // number of columns

        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            // 1. Traverse Top Row
            for (int j = scol; j <= ecol; j++)
                ans.push_back(mat[srow][j]);

            // 2. Traverse Right Column
            for (int i = srow + 1; i <= erow; i++)
                ans.push_back(mat[i][ecol]);

            // 3. Traverse Bottom Row (if not same as top)
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--)
                    ans.push_back(mat[erow][j]);
            }

            // 4. Traverse Left Column (if not same as right)
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--)
                    ans.push_back(mat[i][scol]);
            }

            // Move to the inner layer
            srow++; erow--;
            scol++; ecol--;
        }

        return ans;
    }
};
